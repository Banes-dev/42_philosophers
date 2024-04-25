CC = cc

CFLAGS = -g -Wall -Wextra -Werror -fsanitize=thread

# Normal
NAME = philo
FUNC = src/philo.c src/error.c src/utils.c src/init.c src/thread.c src/thread_action.c src/monitor.c
OBJS = ${FUNC:.c=.o}


# Compil
all: 	${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME} -pthread

clean:	
	rm -f ${OBJS}

fclean:	clean
	rm -f ${NAME}

re:	fclean all

.PHONY: all clean fclean re