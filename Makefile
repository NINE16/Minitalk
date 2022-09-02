LIB			= printf/libftprintf.a
CC			= gcc
CFLAGS		= -Wall -Wextra -Werror -fsanitize=address
SRCS		= $(wildcard *.c)
OBJS		= ${SRCS:.c=.o}
RM			= rm -f
.c.o:
				${CC} ${CFLAGS} -c $< -o ${<:.c=.o}
 
#${NAME}:	${OBJS}
#					ar rc ${NAME} ${OBJS}
#					# ranlib ${NAME]}

all:	server client

server:	server.c $(LIB)
		CC $(CFLAG) $(LIB) server.c -o server

client:	client.c $(LIB)
		CC $(CFLAG) $(LIB) client.c -o client

$(LIB): #libft/
		make -C ./printf/

clean:
				echo "$(OBJS)"
				${RM} $(OBJS)
				make -C ./printf/ clean

fclean:		clean
				rm -rf server client
				make -C ./printf/ fclean

re:				fclean all
