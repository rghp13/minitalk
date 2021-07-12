DIR_SRC		=	srcs/

DIR_HEAD	=	includes/

DIR_LIB		=	libft/

SRCS		=	${DIR_SRC}client.c

SRCS2		=	${DIR_SRC}server.c ${DIR_SRC}server2.c

INCLUDES	=	${DIR_HEAD}get_next_line.h ${DIR_HEAD}libft.h ${DIR_HEAD}minitalk.h

OBJS		=	$(SRCS:.c=.o)
OBJS2		=	${SRCS2:.c=.o}

NAME		=	Client.out
NAME2		=	Server.out

LIBFT_A		=	libft.a
CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Werror -Wextra -g

.c.o:
				${CC} ${CFLAGS} -I${DIR_HEAD} -c $< -o ${<:.c=.o}

all:		${NAME}

${NAME}:	${NAME2} ${OBJS}
			make -C ${DIR_LIB}
			${CC} ${CFLAGS} -I${DIR_HEAD} -o ${NAME} ${OBJS} ${LIBFT_A}


${NAME2}:	${OBJS2}
			make -C ${DIR_LIB}
			${CC} ${CFLAGS} -I${DIR_HEAD} -o ${NAME2} ${OBJS2} ${LIBFT_A}
clean:		
			make -C ${DIR_LIB} clean
			${RM} ${OBJS} ${OBJS2}
fclean:		clean
			make -C ${DIR_LIB} fclean
			${RM} ${NAME} ${NAME2}
re:			fclean all

.PHONY:		all clean fclean re
