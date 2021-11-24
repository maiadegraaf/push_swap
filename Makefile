NAME = push_swap checker

SRCFILES_PS :=	src/init_stacks.c \
				src/push_swap.c \
				src/rotate.c \
				src/small_stack.c \
				src/solve.c \
				src/stack_utils.c \
				src/swap_and_push.c \
				src/utils.c

SRCFILES_C :=	ft_checker/checker.c \
				src/init_stacks.c \
				src/rotate.c \
				src/swap_and_push.c \
				src/stack_utils.c \
				src/utils.c

HEADERFILES := includes/push_swap.h

CFLAGS	?= -Wall -Wextra -Werror

LIBFT := ./libft/libft.a

all: $(NAME)

$(LIBFT):
	$(MAKE) bonus -C ./libft

$(word 1, $(NAME)): $(SRCFILES_PS) $(LIBFT)
	$(CC) $(CFLAGS) $(SRCFILES_PS) $(LIBFT) -o $(word 1, $(NAME))
$(word 2, $(NAME)): $(SRCFILES_C) $(LIBFT)
	$(CC) $(CFLAGS) $(SRCFILES_C) $(LIBFT) -o $(word 2, $(NAME))

clean:
	make fclean -C ./libft

fclean: clean
	rm -f $(LIBFT)
	rm -f $(word 1, $(NAME))
	rm -f $(word 2, $(NAME))

re: fclean all

.PHONY: clean fclean re bonus