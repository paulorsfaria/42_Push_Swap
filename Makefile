NAME = push_swap
CC = cc -g
CFLAGS = -Wall -Wextra -Werror
RM = rm -fr
LIBFT = ./libraries/libft

SRCS = srcs/main.c srcs/ft_validate.c srcs/ft_freedom.c \
		srcs/ft_init.c srcs/ft_movements.c srcs/ft_sorting.c \
		srcs/ft_utils.c srcs/ft_split_and_init.c \
		srcs/ft_under_five.c

OBJS = ${SRCS:.c=.o}

${NAME}:${OBJS}
		${MAKE} --no-print-directory -C ${LIBFT}
		cp ${LIBFT}/libft.a .
		${CC} ${OBJS} libft.a -o ${NAME}

clean:
		${MAKE} --no-print-directory clean -C ${LIBFT}
		rm -fr ${OBJS}

fclean: clean
		${MAKE} fclean --no-print-directory -C ${LIBFT}
		rm -fr libft.a
		rm -fr ${NAME}

all: ${NAME}

re: fclean all

.PHONY: all clear fclean re
