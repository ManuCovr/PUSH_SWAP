# Standard
NAME			= push_swap

# Compiler and Flags
CC				= @cc
CFLAGS			= -Wall -Werror -Wextra -g -fsanitize=address
RM				= rm -f

# Directories
LIBFT			= ./libft/libft.a
INC				= inc/
OBJ_DIR			= obj/

# Source
SRC =	push.c \
								reverse.c \
								rotate.c \
								sort_stack.c \
								sort_three.c \
								swap.c \
								error.c \
								init_a_to_b.c \
								init_b_to_a.c \
								main.c \
								split.c \
								stack_init.c \
								stack_utils.c

OBJECTS = $(SRC: .c = .o)


all: $(NAME)

$(LIBFT):
	@make -C ./libft

$(NAME): $(LIBFT) $(OBJECTS)
	$(CC) $(CFLAGS) $(NAME) $(OBJECTS) $(LIBFT)

clean:
	@$(RM) -r $(OBJECTS)
	@make clean -C ./libft

fclean:		clean
	@$(RM) $(NAME)
	@$(RM) $(LIBFT)

re:		fclean all

.PHONY: all clean fclean re