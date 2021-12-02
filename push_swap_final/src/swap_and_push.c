#include "../includes/push_swap.h"
void	print_action(char c, char a, int i)
{
	if (c == 'p')
		ft_putchar_fd('p', 1);
	else if (c == 's')
		ft_putchar_fd('s', 1);
	else if (c == 'r')
	{
		if (i < 0)
			write (1, "r", 1);
		write(1, "r", 1);
	}
	ft_putchar_fd(a, 1);
	ft_putchar_fd('\n', 1);
}

void	ft_swap_both(t_stack **stack_a, t_stack **stack_b)
{
	ft_swap(stack_a, 's');
	ft_swap(stack_b, 's');
	write(1, "ss\n", 3);
}

void	ft_swap(t_stack **stack, char c)
{
	t_stack	*hold_stack;
	int		tmp_content;
	int		tmp_order;
	t_stack	*first;
	t_stack	*second;

	if (!*stack || (*stack)->next == NULL)
		return ;
	if (c == 'a' || c == 'b')
		print_action('s', c, 0);
	hold_stack = *stack;
	first = hold_stack;
	second = hold_stack->next;
	tmp_content = first->content;
	tmp_order = first->order;
	first->content = second->content;
	first->order = second->order;
	second->content = tmp_content;
	second->order = tmp_order;
}

void	ft_push(t_stack **from, t_stack **to, char c)
{
	t_stack	*tmp_from;
	t_stack	*new_from;

	if (c == 'a' || c == 'b')
		print_action('p', c, 0);
	tmp_from = *from;
	if ((*from)->next)
		new_from = (*from)->next;
	else
		new_from = NULL;
	ft_stackadd_front(to, tmp_from);
	if (!new_from)
	{
		*from = NULL;
		return ;
	}
	new_from->prev = NULL;
	*from = new_from;
	while (new_from != NULL)
	{
		new_from->pos -= 1;
		new_from = new_from->next;
	}
}
