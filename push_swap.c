#include "push_swap.h"

t_stack	*ft_lstnew(int content, int pos)
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
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = new;
}

size_t determine_stack_size(int argc, char **argv)
{
	size_t	i;
	size_t	j;
	size_t	size;

	i = 1;
	size = 0;
	while (i < (size_t)argc)
	{
		j = 0;
		while (argv[i][j] != '\0')
		{
			if (argv[i][j] != ' ')
				size++;
			j++;
		}
		i++;
	}
	return (size);
}

int create_stack_arg(char *argv, int *pos);
{
	size_t	int_size;
	char	*tmp;

	while (*argv)
	{
		while (*argv && *argv == ' ')
			argv++;
		if (!*argv)
			break;
		while (argv[int_size] != ' ')
			int_size++;
		tmp = malloc(sizeof(char) * int_size);
		if (!tmp)
			return (NULL);
		ft_strlcpy(tmp, argv, int_size);
		
	}
}

int fill_stack(int size, char **argv)
{
	t_stack	*tmp;
	size_t	i;
	size_t	j;

	i = 1;
	while (i < size)
	{
		j = 0;
		while (argv[i][j])
		{
			tmp = create_stack_arg
		}
	}
	return (0)
}

int init_stacks(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack *stack_b;
	size_t	stack_size;
	
	stack_size = determine_stack_size(argc, argv);
	printf("%zu", stack_size);
	stack_a = malloc(stack_size * sizeof(t_stack));
	if (!stack_a)
		return (0);
	stack_b = malloc(stack_size * sizeof(t_stack));
	if (!stack_b)
	{
		free(stack_a);
		return (0);
	}
	return (0);
}

int main(int argc, char **argv)
{
	if (argc < 1)
		return (0);
	else
		init_stacks(argc, argv);
}
