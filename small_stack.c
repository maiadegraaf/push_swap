#include "push_swap.h"

void	under_three(t_stack **stack_a, int arr[3])
{
	if (arr[0] > arr[1] && arr[0] < arr[2])
		ft_swap(stack_a, 'a');
	else if (arr[0] > arr[1] && arr[0] > arr[2])
	{
		if (arr[1] > arr[2])
		{
			ft_swap(stack_a, 'a');
			ft_rrotate(stack_a, 'a');
		}
		else
			ft_rotate(stack_a, 'a');
	}
	else if (arr[0] < arr[1] && arr[0] < arr[2])
	{
		ft_swap(stack_a, 'a');
		ft_rotate(stack_a, 'a');
	}
	else
		ft_rrotate(stack_a, 'a');
}

void	lowest_to_b(t_stack **stack_a, t_stack **stack_b, size_t size)
{
	size_t	i;
	t_stack	*lowest_num;

	i = 0;
	while (i < size - 4)
	{
		lowest_num = find_lowest_num(*stack_a);
		if (lowest_num->pos > (size - 1) / 2)
		{
			while ((*stack_a)->content != lowest_num->content)
				ft_rrotate(stack_a, 'a');
		}
		else
		{
			while ((*stack_a)->content != lowest_num->content)
				ft_rotate(stack_a, 'a');
		}
		ft_push(stack_a, stack_b, 'b');
		i++;
	}
}

void	force_sort(t_stack **stack_a, t_stack **stack_b, size_t size)
{
	int		arr[3];
	size_t	i;

	i = 0;
	if (size > 4)
		lowest_to_b(stack_a, stack_b, size);
	arr[0] = (*stack_a)->content;
	arr[1] = (*stack_a)->next->content;
	arr[2] = (*stack_a)->next->next->content;
	if (!check_order(*stack_a))
		under_three(stack_a, arr);
	if (size > 4)
	{
		while (i < size - 4)
		{
			ft_push(stack_b, stack_a, 'a');
			i++;
		}
	}
}