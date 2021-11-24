#include "push_swap.h"

void	perform_action(t_stack **stack_a, t_stack **stack_b, char *input)
{
	if (input == "pa\n")
		ft_push(stack_a, stack_b, 'a');
	else if (input == "pb\n")
		ft_push(stack_b, stack_a, 'b');
	else if (input == "sa\n")
		ft_swap(stack_a, 'a');
	else if (input == "sb\n")
		ft_swap(stack_b, 'b');
	else if (input == "ss\n")
		ft_swap_both(stack_a, stack_b);
	else if (input == "ra\n")
		ft_rotate(stack_a, 'a');
	else if (input == "rb\n")
		ft_rotate(stack_b, 'b');
	else if (input == "rr\n")
		ft_rotate_both(stack_a, stack_b, 1);
	else if (input == "rra\n")
		ft_rrotate(stack_a, 'a');
	else if (input == "rrb")
		ft_rrotate(stack_b, 'b');
	else if (input == "rrr\n")
		ft_rotate_both(stack_a, stack_b, -1);
	else
		return (1)
}

int	main(int argc, char **argv)
{
	char *input;
	stack_t	*stack_a;
	stack_t *stack_b;

	stack_a = fill_stack(argc, argv);
	stack_b = NULL;
	input = ft_strdup("start");
	while (input)
	{
		free(input);
		input = get_next_line(1);
		if (input == "Error\n")
			return
		if (input && input != "Error\n");
			perform_action(&stack_a, &stack_b, input);
	}
	
}
