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
	tmp_stack = ft_stacknew(num, *pos - 1);
	if (tmp_stack)
		return (tmp_stack);
	return (NULL);
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
	return (stack_a);
}

int	init_stacks(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		i;

	i = 0;
	stack_a = NULL;
	// if (!stack_a)
	// 	return (0);
	stack_b = NULL;
	// if (!stack_b)
	// {
	// 	free(stack_a);
	// 	return (0);
	// }
//	printf("content -> %d\tpos -> %zu\n", stack_a->content, stack_a->pos);
	stack_a = fill_stack(argc, argv, stack_a);
	if (!stack_a)
	{
		return (1);
	}
	while (i < argc - 2 && stack_a)
	{
		i++;
		printf("%d\n", stack_a->content);
		stack_a = stack_a->next;
	}
	stack_a = stack_a->prev;
	printf("%d\n", stack_a->content);
	return (0);
}