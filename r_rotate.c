#include "push_swap.h"

void	ft_r_rotate_both(t_radix **stack_a, t_radix **stack_b, int i)
{
	if (i < 0)
	{
		ft_r_rrotate(stack_a, 's');
		ft_r_rrotate(stack_b, 's');
		write(1, "rrr\n", 4);
	}
	else
	{
		ft_r_rotate(stack_a, 's');
		ft_r_rotate(stack_b, 's');
		write(1, "rr\n", 4);
	}
}

void	ft_r_rotate(t_radix **stack, char c)
{
	t_radix *first;
	t_radix *last;
	int		last_content;

	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
	if (!(*stack)->next)
		return ;
	first = *stack;
	last = ft_radixlast(first);
	last_content = last->content;
	last->content = first->content;
	while (first->next != last)
	{
		first->content = first->next->content;
		first = first->next;
	}
	first->content = last_content;
}

void	ft_r_rrotate(t_radix **stack, char c)
{
	t_radix *first;
	t_radix *last;
	int		first_content;
	

	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
	if (!(*stack)->next)
		return ;
	first = *stack;
	last = ft_radixlast(first);
	first_content = first->content;
	first->content = last->content;
	while (last->prev != first)
	{
		last->content = last->prev->content;
		last = last->prev;
	}
	last->content = first_content;
}
