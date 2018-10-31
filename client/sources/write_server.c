#include <string.h>

#include "../includes/client.h"


void write_server(int socketfd, t_sockaddr_in *sin, const char *buffer)
{
    if (sendto(socketfd, buffer, strlen(buffer), 0, (t_sockaddr *)sin, sizeof(*sin)) < 0)
    {
        perror("sendto()");
        exit(errno);
    }
}
