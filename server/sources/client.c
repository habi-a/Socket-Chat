#include <stdlib.h>
#include <string.h>

#include "../includes/server.h"


int         client_exists(t_client *clients, t_sockaddr_in *csin, int actual)
{
    int     i;

    i = 0;
    while (i < actual)
    {
        if (clients[i].sin.sin_addr.s_addr == csin->sin_addr.s_addr
            && clients[i].sin.sin_port == csin->sin_port)
            return (1);
        i++;
    }
    return (0);
}

t_client    *get_client(t_client *clients, t_sockaddr_in *csin, int actual)
{
    int     i;

    i = 0;
    while (i < actual)
    {
        if (clients[i].sin.sin_addr.s_addr == csin->sin_addr.s_addr
            && clients[i].sin.sin_port == csin->sin_port)
            return (&clients[i]);
        i++;
    }
    return (NULL);
}

void        remove_client(t_client *clients, int to_remove, int *actual)
{
    memmove(clients + to_remove, clients + to_remove + 1, (*actual - to_remove) * sizeof(t_client));
    *actual = *actual - 1;
}
