#include "push_swap.h"

void	solve(t_stack **stack_a, t_stack **stack_b, int argc)
{
	t_stack *median;

	median = find_median(*stack_a, argc - 1);
	push_lt_med(stack_a, stack_b, median->order);
}

t_stack	*find_median(t_stack *s, int size)
{
	t_stack *stack_median;
	int		median;

	median = size / 2;
	while (s)
	{
		if (s->order == median)
		{
			stack_median = ft_stacknew(s->content, s->pos, s->order);
			return (stack_median);
		}
		s = s->next;
	}
	return (NULL);
}

int	find_closest(t_stack *s, long median)
{
	t_stack	*top;
	t_stack	*btm;

	top = ft_stacknew(s->content, s->pos, s->order);
	btm = ft_stacklast(top);
	while(s->pos < (size_t) median)
	{
		if (s->order <= median)
		{
			top->content = s->content;
			top->pos = s->pos;
			top->order = s->order;
			break;
		}
		s = s->next;
	}
	s = btm;
	while(s->pos > (size_t) median)
	{
		if (s->order <= median)
		{
			btm->content = s->content;
			btm->pos = s->pos;
			btm->order = s->order;
			break;
		}
		s = s->prev;
	}
	if (top->pos >= (median * 2 - btm->pos))
		return (top->pos);
	else
		return (-1 * (median * 2 - btm->pos));
}

void	push_lt_med(t_stack **stack_a, t_stack **stack_b, long median)
{
	t_stack	*tmp;
	int		rotate;

	tmp = *stack_a;
	while (*stack_a)
	{
		rotate = find_closest(*stack_a, median);
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
		*stack_a = (*stack_a)->next;
	}
	*stack_a = tmp;
}