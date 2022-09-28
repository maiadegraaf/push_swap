NAME = push_swap

SRCFILES :=	src/init_stacks.c \
				src/push_swap.c \
				src/rotate.c \
				src/small_stack.c \
				src/solve.c \
				src/stack_utils.c \
				src/swap_and_push.c \
				src/utils.c

HEADERFILES := includes/push_swap.h

CFLAGS	?= -Wall -Wextra -Werror

LIBFT := ./libft/libft.a

all: $(NAME)

$(LIBFT):
	$(MAKE) bonus -C ./libft

$(NAME): $(SRCFILES) $(LIBFT)
	$(CC) $(CFLAGS) $(SRCFILES) $(LIBFT) -o $(NAME)

clean:
	make fclean -C ./libft

fclean: clean
	rm -f $(LIBFT)
	rm -f $(NAME)

re: fclean all

.PHONY: clean fclean re bonus