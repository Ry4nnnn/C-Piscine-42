NAME = libft.a
SRCS = srcs/ft_putchar.c srcs/ft_putstr.c srcs/ft_strcmp.c srcs/ft_strlen.c srcs/ft_swap.c
OBJS = ${SRCS:.c=.o}

CC = gcc
CFLAGS = -Wall -Werror -Wextra
INCLUDES = includes

all: ${NAME}

${NAME}: ${OBJS}
	ar rcs ${NAME} ${OBJS}

srcs/%.o: srcs/%.c
	${CC} ${CFLAGS} -I ${INCLUDES} -c $< -o $@

clean:
	rm -f ${OBJS}

fclean: clean
	rm -f ${NAME}

re: fclean all

.PHONY: all clean fclean re