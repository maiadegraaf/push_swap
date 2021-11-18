#include "push_swap.h"

void	ft_rotate_both(t_stack **stack_a, t_stack **stack_b, int i)
{
	if (i < 0)
	{
		ft_rrotate(stack_a, 's');
		ft_rrotate(stack_b, 's');
		write(1, "rrr\n", 4);
	}
	else
	{
		ft_rotate(stack_a, 's');
		ft_rotate(stack_b, 's');
		write(1, "rr\n", 4);
	}
}

void	ft_rotate(t_stack **stack, char c)
{
	t_stack *first;
	t_stack *last;
	int		last_content;
	size_t	last_order;

	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
	if (!(*stack)->next)
		return ;
	first = *stack;
	last = ft_stacklast(first);
	last_content = last->content;
	last_order = last->order;
	last->content = first->content;
	last->order = first->order;
	while (first->next != last)
	{
		first->content = first->next->content;
		first->order = first->next->order;
		first = first->next;
	}
	first->content = last_content;
	first->order = last_order;
}

void	ft_rrotate(t_stack **stack, char c)
{
	t_stack *first;
	t_stack *last;
	int		first_content;
	size_t	first_order;

	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
	if (!(*stack)->next)
		return ;
	first = *stack;
	last = ft_stacklast(first);
	first_content = first->content;
	first_order = first->order;
	first->content = last->content;
	first->order = last->order;
	while (last->prev != first)
	{
		last->content = last->prev->content;
		last->order = last->prev->order;
		last = last->prev;
	}
	last->content = first_content;
	last->order = first_order;
}
