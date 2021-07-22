DIR_SRC		=	srcs/

DIR_HEAD	=	includes/

DIR_LIB		=	libft/

SRCS		=	${DIR_SRC}client.c

SRCS2		=	${DIR_SRC}server.c ${DIR_SRC}server2.c

BSRCS		=	${DIR_SRC}client_bonus.c

BSRCS2		=	${DIR_SRC}server_bonus.c ${DIR_SRC}server2_bonus.c

INCLUDES	=	${DIR_HEAD}get_next_line.h ${DIR_HEAD}libft.h ${DIR_HEAD}minitalk.h

OBJS		=	$(SRCS:.c=.o)
OBJS2		=	${SRCS2:.c=.o}
BOBJS		=	${BSRCS:.c=.o}
BOBJS2		=	${BSRCS2:.c=.o}

NAME		=	Client
NAME2		=	Server
BNAME		=	Client_Bonus
BNAME2		=	Server_Bonus

LIBFT_A		=	libft.a
CC			=	gcc
RM			=	rm -f
CFLAGS		=	-Wall -Werror -Wextra

.c.o:
				${CC} ${CFLAGS} -I${DIR_HEAD} -c $< -o ${<:.c=.o}

all:		${NAME}

bonus:		${BNAME} ${BNAME2}

${BNAME}:	${BOBJS}
			make -C ${DIR_LIB}
			cp ${DIR_LIB}${LIBFT_A} ${LIBFT_A}
			${CC} ${CFLAGS} -I${DIR_HEAD} -o ${BNAME} ${BOBJS} ${LIBFT_A}

${BNAME2}:	${BOBJS2}
			make -C ${DIR_LIB}
			cp ${DIR_LIB}${LIBFT_A} ${LIBFT_A}
			${CC} ${CFLAGS} -I${DIR_HEAD} -o ${BNAME2} ${BOBJS2} ${LIBFT_A}

${NAME}:	${NAME2} ${OBJS}
			make -C ${DIR_LIB}
			cp ${DIR_LIB}${LIBFT_A} ${LIBFT_A}
			${CC} ${CFLAGS} -I${DIR_HEAD} -o ${NAME} ${OBJS} ${LIBFT_A}


${NAME2}:	${OBJS2}
			make -C ${DIR_LIB}
			cp ${DIR_LIB}${LIBFT_A} ${LIBFT_A}
			${CC} ${CFLAGS} -I${DIR_HEAD} -o ${NAME2} ${OBJS2} ${LIBFT_A}
clean:		
			make -C ${DIR_LIB} clean
			${RM} ${OBJS} ${OBJS2} ${BOBJS} ${BOBJS2}
fclean:		clean
			make -C ${DIR_LIB} fclean
			${RM} ${NAME} ${BNAME} ${NAME2} ${BNAME2} ${LIBFT_A}
re:			fclean all

.PHONY:		all clean fclean re
