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

void ft_push(t_stack **from, t_stack **to, char c)
{
	t_stack *tmp_from;
	t_stack *tmp_to;

	if (c == 'a')
		write(1, "pa\n", 3);
	else if (c == 'b')
		write(1, "pb\n", 3);
	tmp_from = *from;
	tmp_to = *to;
	ft_stackadd_front(to, tmp_from);
	*from = tmp_from->next;
	free(tmp_from);
	(*from)->prev = NULL;
	tmp_from = *from;
	while (tmp_from->next != NULL)
	{
		tmp_from->pos -= 1;
		tmp_from = tmp_from->next;
	}	
}