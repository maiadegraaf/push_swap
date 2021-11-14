#include "push_swap.h"

t_stack	*ft_lstnew(int content, size_t pos)
{
	t_stack *new_element;

	new_element = (t_stack *)malloc(sizeof(t_stack));
	if (!new_element)
		return (0);
	new_element->content = content;
	new_element->pos = pos;
	new_element->next = NULL;
	return (new_element);
}

void	ft_lstadd_back(t_stack **lst, t_stack *new)
{
	t_stack	*tmp;

	tmp = *lst;
	printf("hello\n");
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

void	*ft_bzero(void *str, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		((char *)str)[i] = '\0';
		i++;
	}
	return (str);
}

void	*ft_calloc(size_t count, size_t size)
{
	int		*ret;

	ret = malloc(count * size);
	if (!ret)
		return (0);
	ft_bzero(ret, count * size);
	return (ret);
}

char	*ft_strdup_c(const char *s1, char c)
{
	char	*s2;
	size_t	size;
	size_t	i;

	i = 0;
	size = 0;
	while (s1[i] != c)
	{
		size++;
		i++;
	}
	s2 = (char *)malloc((size * sizeof(char)) + 1);
	if (!s2)
		return (0);
	i = 0;
	while (i < size)
	{
		s2[i] = s1[i];
		i++;
	}
	s2[i] = '\0';
	return (s2);
}

int	ft_isdigit(int c)
{
	if (c > 47 && c < 58)
		return (1);
	return (0);
}

int	ft_atoi(const char *str, int *ret)
{
	int	p_n;
	int	i;

	i = 0;
	p_n = 1;
	while (*str && *str == ' ')
		str++;
	if (*str == '-' && *str)
	{
		p_n *= -1;
		str++;
	}
	if (!*str)
		return (1);
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1 && i < 10)
			*ret = (*ret * 10) + (str[i++] - '0');
		else
			return (1);
		if (*ret * p_n > 2147483647 || *ret * p_n < -2147483648)
			return (1);
	}
	*ret = *ret * p_n;
	return (0);
}