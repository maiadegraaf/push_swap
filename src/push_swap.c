#include "../includes/push_swap.h"

void	push_swap(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = fill_stack(argc, argv);
	stack_b = NULL;
	if (!stack_a)
		write (2, "Error\n", 6);
	else if (check_order(stack_a))
		return ;
	else if (argc < 7 && argc > 3)
		force_sort(&stack_a, &stack_b, argc);
	else if (argc == 3)
		ft_swap(&stack_a, 'a');
	else
		solve(&stack_a, argc);
}

int	main(int argc, char **argv)
{
	if (argc < 2)
		return (0);
	else
	{
		push_swap(argc, argv);
	}
	//system("leaks push_swap");
}
