#include "push_swap.h"

t_stack	*ft_stacknew(int content, size_t pos, long order)
{
	t_stack	*new_element;

	new_element = (t_stack *)malloc(sizeof(t_stack));
	if (!new_element)
		return (0);
	new_element->content = content;
	new_element->pos = pos;
	new_element->order = order;
	new_element->prev = NULL;
	new_element->next = NULL;
	return (new_element);
}

void	ft_stackadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	tmp = *lst;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
	new->prev = tmp;
}

void	ft_stackadd_front(t_stack **lst, t_stack *new)
{
	t_stack *tmp;

	if (!*lst)
	{
		new->next = NULL;
		*lst = new;
		return;
	}
	new->next = *lst;
	*lst = new;
	tmp = *lst;
	tmp = tmp->next;
	while (tmp != NULL)
	{
		tmp->pos += 1;
		tmp = tmp->next;
	}
}

void	ft_stackclear(t_stack **lst)
{
	t_stack	*tmp;

	if (!*lst)
		return ;
	while (*lst)
	{
		tmp = (*lst)->next;
		free(*lst);
		*lst = tmp;
	}
	*lst = NULL;
}

t_stack	*ft_stacklast(t_stack *stack)
{
	int	i;

	i = 0;
	if (!stack)
		return (NULL);
	while (stack->next != NULL)
	{
		stack = stack->next;
		i++;
	}
	return (stack);
}
