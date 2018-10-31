#include <stdio.h>
#include <stdlib.h>

#include "../client/client.h"


int             init_connection(const char *address, t_sockaddr_in *sin)
{
    int         socketfd;
    t_hostent   *hostinfo;

    if ((socketfd = socket(AF_INET, SOCK_DGRAM, IPPROTO_UDP)) == INVALID_SOCKET)
    {
        perror("socket()");
        exit(errno);
    }
    if ((hostinfo = gethostbyname(address)) == NULL)
    {
        fprintf(stderr, "Unknown host %s.\n", address);
        exit(EXIT_FAILURE);
    }
    sin->sin_addr   = *(t_in_addr *)hostinfo->h_addr;
    sin->sin_port   = htons(PORT);
    sin->sin_family = AF_INET;
    return (sock);
}

void            end_connection(int socketfd)
{
    closesocket(socketfd);
}
