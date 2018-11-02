#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../includes/server.h"


void                app(void)
{
    int             socketfd;
    int             actual_index;
    int             max_index;
    char            buffer[BUF_SIZE];
    fd_set          rdfs;
    t_client        clients[MAX_CLIENTS];

    actual_index = 0;
    socketfd = init_connection();
    max_index = socketfd;
    while (1)
    {
        FD_ZERO(&rdfs);
        FD_SET(STDIN_FILENO, &rdfs);
        FD_SET(socketfd, &rdfs);
        if (select(max_index + 1, &rdfs, NULL, NULL, NULL) == -1)
        {
            perror("select()");
            exit(errno);
        }
        if (FD_ISSET(STDIN_FILENO, &rdfs))
            break;
        else if (FD_ISSET(socketfd, &rdfs))
        {
            t_sockaddr_in csin;

            memset(&csin, 0, sizeof(csin));
            read_client(socketfd, &csin, buffer);
            if (client_exists(clients, &csin, actual_index))
            {
                t_client *client = get_client(clients, &csin, actual_index);
                if (client != NULL)
                    send_all_clients(socketfd, clients, client, actual_index, buffer, 0);
            }
            else if (actual_index != MAX_CLIENTS)
            {
                t_client c;

                c.sin = csin;
                strncpy(c.name, buffer, BUF_SIZE - 1);
                clients[actual_index] = c;
                actual_index++;
                send_notif_join(socketfd, clients, &c, actual_index);
                printf("%s joined the chat\n", c.name);
            }
        }
    }
    end_connection(socketfd);
}
