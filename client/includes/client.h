#ifndef   _SOCKET_CLIENT_H_
# define  _SOCKET_CLIENT_H_


# include <sys/types.h>
# include <sys/socket.h>
# include <netinet/in.h>
# include <arpa/inet.h>
# include <unistd.h>
# include <netdb.h>

# define  CRLF	              "\r\n"
# define  PORT	              1977
# define  BUF_SIZE            1024
# define  INVALID_SOCKET      -1
# define  SOCKET_ERROR        -1
# define  closesocket(s)      close(s)

typedef   struct sockaddr_in  t_sockaddr_in;
typedef   struct sockaddr     t_sockaddr;
typedef   struct in_addr      t_in_addr;
typedef   struct hostent      t_hostent;

int       init_connection(const char *address, t_sockaddr_in *sin);
int       read_server(int socketfd, t_sockaddr_in *sin, char *buffer);
void      app(const char *address, const char *name);
void      end_connection(int socketfd);
void      write_server(int socketfd, t_sockaddr_in *sin, const char *buffer);


#endif    /* _SOCKET_CLIENT_H_ */
