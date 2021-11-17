#include "push_swap.h"

void	ft_swap_both(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_a, 's');
	ft_swap(stack_b, 's');
	write(1, "ss\n", 3);
}

void	ft_swap(t_stack **stack, char c)
{
	t_stack	*hold_stack;
	int tmp;
	t_stack *first;
	t_stack *second;

	if (!*stack || (*stack)->next == NULL)
		return ;
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
	hold_stack = *stack;
	first = hold_stack;
	second = hold_stack->next;
	tmp = first->content;
	first->content = second->content;
	second->content = tmp;
}

void	ft_push(t_stack **from, t_stack **to, char c)
{
	t_stack *tmp_from;
	t_stack	*new_from;

	ft_putchar_fd('p', 1);
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
	tmp_from = *from;
	if ((*from)->next)
		new_from = (*from)->next;
	else
		new_from = NULL;
	ft_stackadd_front(to, tmp_from);
	if (!new_from)
	{
		*from = NULL;
		return;
	}
	new_from->prev = NULL;
	*from = new_from;
	while (new_from != NULL)
	{
		new_from->pos -= 1;
		new_from = new_from->next;
	}
}

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

	if (c == 'a')
		write(1, "ra\n", 3);
	else if (c == 'b')
		write(1, "rb\n", 3);
	if (!(*stack)->next)
		return ;
	first = *stack;
	last = ft_stacklast(first);
	last_content = last->content;
	last->content = first->content;
	while (first->next != last)
	{
		first->content = first->next->content;
		first = first->next;
	}
	first->content = last_content;
}

void	ft_rrotate(t_stack **stack, char c)
{
	t_stack *first;
	t_stack *last;
	int		first_content;

	if (c == 'a')
		write(1, "rra\n", 4);
	else if (c == 'b')
		write(1, "rrb\n", 4);
	if (!(*stack)->next)
		return ;
	first = *stack;
	last = ft_stacklast(first);
	first_content = first->content;
	first->content = last->content;
	while (last->prev != first)
	{
		last->content = last->prev->content;
		last = last->prev;
	}
	last->content = first_content;
}
