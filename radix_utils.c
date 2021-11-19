#include "push_swap.h"

t_radix	*ft_radixnew(int content, size_t pos)
{
	t_radix	*new_element;

	new_element = (t_radix *)malloc(sizeof(t_radix));
	if (!new_element)
		return (0);
	new_element->content = content;
	new_element->pos = pos;
	new_element->prev = NULL;
	new_element->next = NULL;
	return (new_element);
}

void	ft_radixadd_back(t_radix **lst, t_radix *new)
{
	t_radix	*tmp;

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

void	ft_radixadd_front(t_radix **lst, t_radix *new)
{
	t_radix *tmp;

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

void	ft_radixclear(t_radix **lst)
{
	t_radix	*tmp;

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

t_radix	*ft_radixlast(t_radix *radix)
{
	int	i;

	i = 0;
	if (!radix)
		return (NULL);
	while (radix->next != NULL)
	{
		radix = radix->next;
		i++;
	}
	return (radix);
}
