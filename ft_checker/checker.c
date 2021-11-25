#include "../includes/push_swap.h"

int	perform_action(t_stack **stack_a, t_stack **stack_b, char *input)
{
	if (!ft_strncmp("pa\n", input, 3))
		ft_push(stack_b, stack_a, 'x');
	else if (!ft_strncmp("pb\n", input, 3))
		ft_push(stack_a, stack_b, 'x');
	else if (!ft_strncmp("sa\n", input, 3))
		ft_swap(stack_a, 'x');
	else if (!ft_strncmp("sb\n", input, 3))
		ft_swap(stack_b, 'x');
	else if (!ft_strncmp("ss\n", input, 3))
		ft_swap_both(stack_a, stack_b);
	else if (!ft_strncmp("ra\n", input, 3))
		ft_rotate(stack_a, 'x');
	else if (!ft_strncmp("rb\n", input, 3))
		ft_rotate(stack_b, 'x');
	else if (!ft_strncmp("rr\n", input, 3))
		ft_rotate_both(stack_a, stack_b, 1);
	else if (!ft_strncmp("rra\n", input, 4))
		ft_rrotate(stack_a, 'x');
	else if (!ft_strncmp("rrb\n", input, 4))
		ft_rrotate(stack_b, 'x');
	else if (!ft_strncmp("rrr\n", input, 4))
		ft_rotate_both(stack_a, stack_b, -1);
	else
		return (1);
	return (0);
}

int	write_error(void)
{
	write(2, "Error\n", 6);
	return (0);
}

int	main(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	char	*input;

	stack_a = fill_stack(argc, argv);
	stack_b = NULL;
	input = ft_strdup("start");
	while (input)
	{
		input = get_next_line(0);
		if (input && !ft_strncmp("Error\n", input, 6))
			return (write_error());
		if (input)
		{
			if (perform_action(&stack_a, &stack_b, input))
				return (write_error());
		}
	}
	if (!input && !stack_b && check_order(stack_a))
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free (input);
}
