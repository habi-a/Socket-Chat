#include "../includes/client.h"


int         read_server(int socketfd, t_sockaddr_in *sin, char *buffer)
{
    int      n;
    size_t   sinsize;

    n        = 0;
    sinsize  = sizeof(*sin)
    if ((n = recvfrom(socketfd, buffer, BUF_SIZE - 1, 0, (t_sockaddr *)sin, &sinsize)) < 0)
    {
        perror("recvfrom()");
        exit(errno);
    }
    buffer[n] = '/0';
    return n;
}
