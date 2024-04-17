CC = cc

CFLAGS = -g -Wall -Wextra -Werror

# Normal
NAME = philo
FUNC = philo.c error.c utils.c
OBJS = ${FUNC:.c=.o}


# Compil
all: 	${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

clean:	
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re