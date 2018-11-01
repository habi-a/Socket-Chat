#include <errno.h>
#include <stdio.h>
#include <stdlib.h>

#include "../includes/server.h"


int             read_client(int socketfd, t_sockaddr_in *csin, char *buffer)
{
    int         n;
    socklen_t   sinsize;

    n        = 0;
    sinsize  = sizeof(*csin);
    if ((n = recvfrom(socketfd, buffer, BUF_SIZE - 1, 0, (t_sockaddr *)csin, &sinsize)) < 0)
    {
        perror("recvfrom()");
        exit(errno);
    }
    buffer[n] = '\0';
    return n;
}
