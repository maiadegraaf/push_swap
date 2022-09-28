#include "../includes/push_swap.h"

void	push_swap(int size, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = fill_stack(size, argv);
	stack_b = NULL;
	if (!stack_a)
		write (2, "Error\n", 6);
	else if (check_order(stack_a))
	{
		ft_stackclear(&stack_a);
		free(stack_a);
		return ;
	}
	else if (size < 6 && size > 2)
		force_sort(&stack_a, &stack_b, size);
	else if (size == 2)
		ft_swap(&stack_a, 'a');
	else
		solve(&stack_a, size);
	ft_stackclear(&stack_a);
	free(stack_a);
}

int	main(int argc, char **argv)
{
	int		counter;
	char	**split;

	counter = 0;
	if (argc < 2)
		return (0);
	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		while (split[counter])
			counter++;
		push_swap(counter, split);
		free_arr(split);
		free(split);
	}
	else
	{
		argv++;
		push_swap(argc - 1, argv);
	}
}
