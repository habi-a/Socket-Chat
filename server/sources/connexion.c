#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "../includes/server.h"


int                 init_connection(void)
{
    int             socketfd;
    t_sockaddr_in   sin;

    memset(&sin, 0, sizeof(sin));
    if ((socketfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == INVALID_SOCKET)
    {
        perror("socket()");
        exit(errno);
    }
    sin.sin_addr.s_addr = htonl(INADDR_ANY);
    sin.sin_port = htons(PORT);
    sin.sin_family = AF_INET;
    if (bind(socketfd, (t_sockaddr *) &sin, sizeof(sin)) == SOCKET_ERROR)
    {
        perror("bind()");
        exit(errno);
    }
    return (socketfd);
}

void            end_connection(int socketfd)
{
    closesocket(socketfd);
}
