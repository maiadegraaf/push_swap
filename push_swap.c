#include "push_swap.h"
void	force_sort(t_stack **stack_a, t_stack **stack_b, int size)
{
	int	i;
	int	first;
	int middle;
	int	last;

	i = 0;
	while (i < size - 4)
	{
		ft_push(stack_a, stack_b, 'b');
		i++;
	}
	first = (*stack_a)->content;
	middle = (*stack_a)->next->content;
	last = (*stack_a)->next->next->content;
	if (first > middle && first < last)
		ft_swap(stack_a, 'a');
	else if (first > middle && first > last)
	{
		if (middle > last)
		{
			ft_swap(stack_a, 'a');
			ft_rrotate(stack_a, 'a');
		}
		else
			ft_rotate(stack_a, 'a');
	}
	print_stacks(*stack_a, *stack_b, size);
}

void	push_swap(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_a = fill_stack(argc, argv, stack_a);
	stack_b = NULL;
	if (!stack_a)
		write (1, "Error\n", 6);
	if (argc < 6)
	{
		force_sort(&stack_a, &stack_b, argc);
		return;
	}
}

int	main(int argc, char **argv)
{
	if (argc < 1)
		return (0);
	else
	{
		push_swap(argc, argv);
	}
}
