#include "push_swap.h"

int	check_duplicate(t_stack **stack_a, int num, size_t pos)
{
	t_stack	*tmp;
	size_t	i;

	if (!*stack_a)
		return (0);
	tmp = *stack_a;
	i = 0;
	while (i < pos)
	{
		if (tmp->content == num)
		{
			return (1);
		}
		tmp = tmp->next;
		i++;
	}
	return (0);
}

t_stack	*create_stack_arg(char *argv, size_t *pos)
{
	char	*tmp;
	t_stack	*tmp_stack;
	int		num;

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

void	find_order(t_stack **stack_a, long order)
{
	t_stack			*lowest_num;
	t_stack			*tmp;

	tmp = *stack_a;
	while (tmp->order > -1)
	{
		if (!tmp)
			return ;
		tmp = tmp->next;
	}
	lowest_num = find_next_lowest_num(*stack_a);
	while (tmp)
	{
		if ((tmp)->content == lowest_num->content)
		{
			(tmp)->order = order;
			break;
		}
		(tmp) = (tmp)->next;
	}
	tmp = *stack_a;
}

t_stack	*fill_stack(size_t size, char **argv, t_stack *stack_a)
{
	size_t	i;
	t_stack	*tmp_stack;

	i = 1;
	while (i < size)
	{
		tmp_stack = create_stack_arg (argv[i], &i);
		if (!tmp_stack
			|| check_duplicate(&stack_a, tmp_stack->content, tmp_stack->pos))
		{
			if (tmp_stack)
				free(tmp_stack);
			ft_stackclear(&stack_a);
			return (NULL);
		}
		ft_stackadd_back(&stack_a, tmp_stack);
		i++;
	}
	i = 0;
	while (i < size - 1)
	{
		find_order(&stack_a, i);
		i++;
	}
	return (stack_a);
}
