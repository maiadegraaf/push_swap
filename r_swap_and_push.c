#include "push_swap.h"

void	ft_r_swap_both(t_radix **stack_a, t_radix **stack_b)
{
	ft_r_swap(stack_a, 's');
	ft_r_swap(stack_b, 's');
	write(1, "ss\n", 3);
}

void	ft_r_swap(t_radix **stack, char c)
{
	t_radix	*hold_stack;
	int		tmp_content;
	t_radix *first;
	t_radix *second;

	if (!*stack || (*stack)->next == NULL)
		return ;
	if (c == 'a')
		write(1, "sa\n", 3);
	else if (c == 'b')
		write(1, "sb\n", 3);
	hold_stack = *stack;
	first = hold_stack;
	second = hold_stack->next;
	tmp_content = first->content;
	first->content = second->content;
	second->content = tmp_content;
}

void	ft_r_push(t_radix **from, t_radix **to, char c)
{
	t_radix *tmp_from;
	t_radix	*new_from;

	ft_putchar_fd('p', 1);
	ft_putchar_fd(c, 1);
	ft_putchar_fd('\n', 1);
	tmp_from = *from;
	if ((*from)->next)
		new_from = (*from)->next;
	else
		new_from = NULL;
	ft_radixadd_front(to, tmp_from);
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
