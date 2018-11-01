#include <stdio.h>
#include <stdlib.h>

#include "../includes/client.h"


int main(int argc, char **argv)
{
    if (argc < 2)
    {
        printf("Usage : %s [server-address] [pseudo]\n", argv[0]);
        return (EXIT_FAILURE);
    }
    app(argv[1], argv[2]);
    return (EXIT_SUCCESS);
}
