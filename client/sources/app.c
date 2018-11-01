#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "../includes/client.h"


void                app(const char *address, const char *name)
{
    int             n;
    int             socketfd;
    char            buffer[BUF_SIZE];
    fd_set          rdfs;
    t_sockaddr_in   sin;

    memset(&sin, 0, sizeof(sin));
    socketfd = init_connection(address, &sin);
    write_server(socketfd, &sin, name);
    while (1)
    {
        FD_ZERO(&rdfs);
        FD_SET(STDIN_FILENO, &rdfs);
        FD_SET(socketfd, &rdfs);
        if (select(socketfd + 1, &rdfs, NULL, NULL, NULL) == -1)
        {
            perror("select()");
            exit(errno);
        }
        if (FD_ISSET(STDIN_FILENO, &rdfs))
        {
            fgets(buffer, BUF_SIZE - 1, stdin);
            {
                char *p;

                p = NULL;
                if ((p = strstr(buffer, "\n")) != NULL)
                    *p = 0;
                else
                    buffer[BUF_SIZE - 1] = 0;
            }
            write_server(socketfd, &sin, buffer);
        }
        else if (FD_ISSET(socketfd, &rdfs))
        {
            if ((n = read_server(socketfd, &sin, buffer)) == 0)
            {
                printf("Server disconnected !\n");
                break;
            }
            puts(buffer);
        }
    }
    end_connection(socketfd);
}
