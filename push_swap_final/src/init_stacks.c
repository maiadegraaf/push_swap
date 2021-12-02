#include "../includes/push_swap.h"

int	check_duplicate(t_stack **stack_a, int num)
{
	t_stack	*tmp;

	if (!*stack_a)
		return (0);
	tmp = *stack_a;
	while (tmp)
	{
		if (tmp->content == num)
		{
			return (1);
		}
		tmp = tmp->next;
	}
	return (0);
}

t_stack	*create_stack_arg(char *argv, size_t *pos)
{
	char	*tmp;
	t_stack	*tmp_stack;
	long		num;

	num = 0;
	tmp = ft_strdup(argv);
	if (ft_n_atoi(tmp, &num))
	{
		free(tmp);
		return (NULL);
	}
	free(tmp);
	tmp_stack = ft_stacknew(num, *pos - 1, -1);
	if (tmp_stack)
		return (tmp_stack);
	return (NULL);
}

void	find_order(t_stack **stack_a, size_t size)
{
	t_stack			*lowest_num;
	t_stack			*tmp;
	size_t			i;

	i = 0;
	while (i < size)
	{
		tmp = *stack_a;
		lowest_num = find_next_lowest_num(*stack_a);
		while (tmp)
		{
			if ((tmp)->content == lowest_num->content)
			{
				(tmp)->order = i;
				break ;
			}
			(tmp) = (tmp)->next;
		}	
		free(lowest_num);
		i++;
	}
}

t_stack	*fill_stack(size_t size, char **argv)
{
	size_t	i;
	t_stack	*tmp;
	t_stack	*stack_a;

	i = 0;
	stack_a = NULL;
	while (i < size)
	{
		tmp = create_stack_arg (argv[i], &i);
		if (!tmp || check_duplicate(&stack_a, tmp->content))
		{
			if (tmp)
				free(tmp);
			ft_stackclear(&stack_a);
			return (NULL);
		}
		ft_stackadd_back(&stack_a, tmp);
		i++;
	}
	find_order(&stack_a, size);
	return (stack_a);
}
