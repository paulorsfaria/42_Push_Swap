NAME = push_swap
NAME_BONUS = checker
CC = cc -g
CFLAGS = -Wall -Wextra -Werror
RM = rm -fr
LIBFT = ./libraries/libft

SRCS = srcs/ft_movements.c srcs/ft_stack_validations.c srcs/ft_validate.c \
       srcs/ft_finishing_sort.c srcs/ft_sorting.c srcs/ft_under_five.c srcs/main.c \
       srcs/ft_init.c srcs/ft_split_and_init.c srcs/ft_utils.c

SRCS_BONUS = bonus/checker_bonus.c bonus/ft_split_and_init_bonus.c bonus/movements_bonus.c \
             bonus/ft_init_bonus.c bonus/ft_validate_bonus.c

OBJS = ${SRCS:.c=.o}

OBJS_BONUS = ${SRCS_BONUS:.c=.o}

${NAME}:${OBJS}
		${MAKE} --no-print-directory -C ${LIBFT}
		cp ${LIBFT}/libft.a .
		${CC} ${OBJS} libft.a -o ${NAME}

${NAME_BONUS}:${OBJS_BONUS}
		${MAKE} --no-print-directory -C ${LIBFT}
		cp ${LIBFT}/libft.a .
		${CC} ${OBJS_BONUS} libft.a -o ${NAME_BONUS}

bonus: ${NAME_BONUS}

clean:
		${MAKE} --no-print-directory clean -C ${LIBFT}
		rm -fr ${OBJS}
		rm -fr ${OBJS_BONUS}

fclean: clean
		${MAKE} fclean --no-print-directory -C ${LIBFT}
		rm -fr libft.a
		rm -fr ${NAME}
		rm -fr ${NAME_BONUS}

all: ${NAME}

re: fclean all

.PHONY: all clear fclean re
