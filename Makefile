NAME := push_swap
SRCFILES := \
			init_stacks.c \
			push_swap.c \
			rotate.c \
			small_stack.c \
			solve.c \
			stack_utils.c \
			swap_and_push.c \
			utils.c

HEADERFILES := push_swap.h

CFLAGS	= -Wall -Wextra -Werror

LIBFT = ./libft/libft.a

all: push_swap

$(LIBFT):
	$(MAKE) bonus -C ./libft

$(NAME): $(SRCFILES)
	$(CC) $(CFLAGS) -o $(NAME) $^ $(LIBFT)

clean:
	rm -f $(OBJFILES) $(BONUS_OBJFILES)

fclean: clean
	rm -f $(NAME) $^

re: fclean all

.PHONY: clean fclean re bonus