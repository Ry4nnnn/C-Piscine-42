NAME	= do-op
SRCS	= do-op.c ft_atoi.c ft_putchar.c ft_putnbr.c ft_putstr.c \
ft_strcmp.c ft_strlen.c operators.c
OBJS	= ${SRCS:.c=.o}

CC		= gcc
CFLAGS	= -Wall -Werror -Wextra
INCLUDES = .

all: ${NAME}

${NAME}: ${OBJS}
	${CC} ${CFLAGS} ${OBJS} -o ${NAME}

%.o: %.c
	${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re
