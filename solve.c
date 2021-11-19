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

int	whats_bigger(int top, int btm)
{
	if (top > btm)
		return (top);
	else
		return (-btm);
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
	return (whats_bigger(top, btm));
}

void	solve(t_stack **stack_a, t_stack **stack_b, int argc)
{
	int		i;
	int		index;
	size_t	rotate;
	t_radix	*radix_stack;

	i = 0;
	index = 0;
	while (((argc - 2) >> index) != 0)
		++index;
	radix_stack = init_radix_stack(*stack_a, index - 1);
	if (radix_stack->content)
	{
		ft_push(stack_a, stack_b, 'b');
	}
	else
	{
		rotate = find_closest(radix_stack, (argc - 1) / 2);
		printf("rotate = %zu\n", rotate);
		if (rotate < 0)
		{
			rotate *= -1;
			while (rotate > 0)
			{
				ft_rrotate(stack_a, 'a');
				rotate--;
			}
			ft_push(stack_a, stack_b, 'b');
		}
		else
		{
			while (rotate > 0)
			{
				ft_rotate(stack_a, 'a');
				rotate--;
			}
			ft_push(stack_a, stack_b, 'b');
		}
	}
}

// t_stack	*find_median(t_stack *s, int size)
// {
// 	t_stack *stack_median;
// 	int		median;

// 	median = size / 2;
// 	while (s)
// 	{
// 		if (s->order == median)
// 		{
// 			stack_median = ft_stacknew(s->content, s->pos, s->order);
// 			return (stack_median);
// 		}
// 		s = s->next;
// 	}
// 	return (NULL);
// }

// void	push_lt_med(t_stack **stack_a, t_stack **stack_b, long median)
// {
// 	t_stack	*tmp;
// 	int		rotate;

// 	tmp = *stack_a;
// 	while (*stack_a)
// 	{
// 		rotate = find_closest(*stack_a, median);
// 		if (rotate < 0)
// 		{
// 			rotate *= -1;
// 			while (rotate > 0)
// 			{
// 				ft_rrotate(stack_a, 'a');
// 				rotate--;
// 			}
// 			ft_push(stack_a, stack_b, 'b');
// 		}
// 		else
// 		{
// 			while (rotate > 0)
// 			{
// 				ft_rotate(stack_a, 'a');
// 				rotate--;
// 			}
// 			ft_push(stack_a, stack_b, 'b');
// 		}
// 		*stack_a = (*stack_a)->next;
// 	}
// 	*stack_a = tmp;
// }
