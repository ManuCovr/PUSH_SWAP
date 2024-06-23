# Standard
NAME = push_swap
SRCS =  $(wildcard *.c)
OBJS = ${SRCS:.c=.o}
CC = gcc
CFLAGS = -Wall -Wextra -Werror -Iincludes
RM = rm -rf

# Source
SRCS = push.c \
								reverse.c \
								rotate.c \
								sort_stack.c \
								sort_three.c \
								swap.c \
								error.c \
								init_a_to_b.c \
								init_b_to_a.c \
								push_swap.c \
								split.c \
								stack_init.c \
								stack_utils.c

all: ${NAME}
${NAME}: ${OBJS}
	@${MAKE} -C ./libft
	@${CC} ${CFLAGS} ${OBJS} ./libft/libft.a -o ${NAME}
	@echo "Compiled successfully!"

clean: 
	@${MAKE} -C ./libft fclean
	@${RM} ${OBJS}
	@echo "Cleaned!"

fclean: clean
	@${RM} ${NAME}
	@echo "Fully cleaned!"

re: fclean all

.PHONY: all clean fclean re