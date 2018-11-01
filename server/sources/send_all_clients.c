#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../includes/server.h"


static void write_client(int socketfd, t_sockaddr_in *sin, const char *buffer)
{
    if (sendto(socketfd, buffer, strlen(buffer), 0, (t_sockaddr *)sin, sizeof(*sin)) < 0)
    {
        perror("sendto()");
        exit(errno);
    }
}

void        send_all_clients(int socketfd, t_client *clients, t_client *sender, int actual, const char *buffer, char from_server)
{
    int     i;
    char    message[BUF_SIZE];

    i = 0;
    message[0] = 0;
    while (i < actual)
    {
        if (sender != &clients[i])
        {
            if (!from_server)
            {
                strncpy(message, sender->name, BUF_SIZE - 1);
                strncat(message, " : ", sizeof(message) - strlen(message) - 1);
            }
            strncat(message, buffer, sizeof(message) - strlen(message) - 1);
            write_client(socketfd, &clients[i].sin, message);
        }
        i++;
    }
}
