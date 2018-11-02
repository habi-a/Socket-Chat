#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include "../includes/client.h"


int             init_connection(const char *address, t_sockaddr_in *sin)
{
    int         socketfd;
    t_hostent   *hostinfo;

    if ((socketfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == INVALID_SOCKET)
    {
        perror("socket()");
        exit(errno);
    }
    printf("\033[0;32m=> Socket client has been created.\033[0m\n");
    printf("\033[0;33m=> Attempting to connect to %s...\033[0m\n", address);
    if ((hostinfo = gethostbyname(address)) == NULL)
    {
        fprintf(stderr, "\033[0;31mUnknown host %s.\033[0m\n", address);
        exit(EXIT_FAILURE);
    }
    sin->sin_addr   = *(t_in_addr *)hostinfo->h_addr;
    sin->sin_port   = htons(PORT);
    sin->sin_family = AF_INET;
    puts("");
    return (socketfd);
}

void            end_connection(int socketfd)
{
    closesocket(socketfd);
}
