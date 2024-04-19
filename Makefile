CC = cc

CFLAGS = -g -Wall -Wextra -Werror

# Normal
NAME = philo
FUNC = src/philo.c src/error.c src/utils.c src/init.c src/thread.c src/thread_action.c
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