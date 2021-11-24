#include "../includes/push_swap.h"

void	solve(t_stack **stack_a, int argc)
{
	int		index;
	int		max_index;
	int		i;
	t_stack	*stack_b;

	index = 0;
	max_index = 0;
	stack_b = NULL;
	while (((argc - 2) >> max_index) != 0)
		++max_index;
	while (index < max_index)
	{
		i = 0;
		while (i < (argc - 1))
		{
			if ((((*stack_a)->order >> index) & 1) == 0)
				ft_push(stack_a, &stack_b, 'b');
			else
				ft_rotate(stack_a, 'a');
			i++;
		}
		while (stack_b)
			ft_push(&stack_b, stack_a, 'a');
		index++;
	}
}
