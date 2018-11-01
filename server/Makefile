default: all


NAME	=	server.out

CC		=	gcc
CFLAGS	=	-Wall -Wextra -Werror -Wpedantic

SRC_DIR	= 	./sources
SRC		= 	$(SRC_DIR)/main.c 			\
			$(SRC_DIR)/app.c 			\
			$(SRC_DIR)/client.c 		\
			$(SRC_DIR)/connexion.c 		\
			$(SRC_DIR)/read_client.c 	\
			$(SRC_DIR)/send_all_clients.c

OBJ		= 	$(SRC:.c=.o)

RM		= 	rm -f


all:		$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
	$(RM) $(OBJ)

fclean: 	clean
	$(RM) $(NAME)

re: 		fclean all

.PHONY	=	all $(NAME) clean fclean re
