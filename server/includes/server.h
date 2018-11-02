#ifndef   _SOCKET_SERVER_H_
# define  _SOCKET_SERVER_H_


# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <unistd.h>
# include <netdb.h>

# define  CRLF	              "\r\n"
# define  PORT	              1977
# define  BUF_SIZE            1024
# define  MAX_CLIENTS 	      100
# define  INVALID_SOCKET      -1
# define  SOCKET_ERROR        -1
# define  closesocket(s)      close(s)

typedef   struct sockaddr_in  t_sockaddr_in;
typedef   struct sockaddr     t_sockaddr;
typedef   struct in_addr      t_in_addr;

typedef   struct              e_client
{
    t_sockaddr_in             sin;
    char                      name[BUF_SIZE];
}                             t_client;

int       init_connection(void);
int       read_client(int socketfd, t_sockaddr_in *csin, char *buffer);
int       client_exists(t_client *clients, t_sockaddr_in *csin, int actual);
void      app(void);
void      end_connection(int socketfd);
void      send_notif_join(int socketfd, t_client *clients, t_client *sender, int actual);
void      send_all_clients(int socketfd, t_client *clients, t_client *client, int actual, const char *buffer, char from_server);
void      remove_client(t_client *clients, int to_remove, int *actual);
t_client* get_client(t_client *clients, t_sockaddr_in *csin, int actual);

#endif    /* _SOCKET_SERVER_H_ */
