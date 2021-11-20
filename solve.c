#include "push_swap.h"

t_radix	*init_radix_stack(t_stack *stack, int index)
{
	t_radix	*radix_stack;
	t_radix	*tmp;

	radix_stack = ft_radixnew((stack->order >> index) & 1, stack->pos);
	stack = stack->next;
	while (stack)
	{
		tmp = ft_radixnew((stack->order >> index) & 1, stack->pos);
		ft_radixadd_back(&radix_stack, tmp);
		stack = stack->next;
	}
	return (radix_stack);
}

int	find_closest(t_radix *stack, int middle)
{
	int		top;
	int		btm;
	t_radix	*last;

	top = 0;
	last = ft_radixlast(stack);
	while (stack && top <= middle)
	{
		if (stack->content == 1)
			break ;
		top++;
		stack = stack->next;
	}
	btm = 0;
	while (last && btm < middle)
	{
		if (stack->content == 1)
			break ;
		btm++;
		stack = stack->prev;
	}
	if (top > btm)
		return (top);
	else
		return (-btm);
}

void	go_to_closest(t_radix **stack, int rotate, void r(t_radix **stack, char c), char c)
{
	while (rotate)
	{
		r(stack, c);
		rotate--;
	}
}

int	all_zeros(t_radix *radix_stack)
{
	while (radix_stack)
	{
		if(radix_stack->content == 0)
			return(1);
		radix_stack = radix_stack->next;
	}
	return (0);
}

void	move_zero(t_radix **radix_stack_a, t_radix **radix_stack_b, size_t size)
{
	size_t	rotate;

	if (!(*radix_stack_a)->content)
		ft_r_push(radix_stack_a, radix_stack_b, 'b');
	else
	{
		rotate = find_closest(*radix_stack_a, size / 2);
		if (rotate < 0)
			go_to_closest(radix_stack_a, -rotate, ft_r_rrotate, 'a');
		else
		{
			go_to_closest(radix_stack_a, rotate, ft_r_rotate, 'a');
		}
		ft_r_push(radix_stack_a, radix_stack_b, 'b');
	}
}

void	solve(t_stack **stack_a, int argc)
{
	int		index;
	int		max_index;
	int		i;
	t_radix	*radix_stack_a;
	t_radix *radix_stack_b;

	index = 0;
	i = 0;
	max_index = 0;
	radix_stack_b = NULL;
	while (((argc - 2) >> max_index) != 0)
		++max_index;
	while (index < max_index)
	{
		radix_stack_a = init_radix_stack(*stack_a, index);
		while (all_zeros(radix_stack_a) && i < 10)
		{
			move_zero(&radix_stack_a, &radix_stack_b, argc - 1);
			i++;
		}
		while (radix_stack_b)
			ft_r_push(&radix_stack_b, &radix_stack_a, 'a');
		index++;
	}
}
