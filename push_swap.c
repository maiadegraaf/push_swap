#include "push_swap.h"

// size_t determine_stack_size(int argc, char **argv)
// {
// 	size_t	i;
// 	size_t	j;
// 	size_t	size;

// 	i = 1;
// 	size = 0;
// 	while (i < (size_t)argc)
// 	{
// 		j = 0;
// 		while (argv[i][j] != '\0')
// 		{
// 			if (argv[i][j] != ' ')
// 				size++;
// 			j++;
// 		}
// 		i++;
// 	}
// 	return (size);
// }

int	check_duplicate(t_stack **stack_a, int num)
{
	t_stack	*tmp;

	tmp = *stack_a;
	printf("num in dup -> %d\n", num);
	while (tmp->next != NULL)
	{
		printf("content -> %d\tpos -> %zu\n", tmp->content, tmp->pos);
		if (tmp->content == num)
			return (1);
		tmp = tmp->next;
	}
	printf("end dup\n\n");
	return (0);
}

int create_stack_arg(char *argv, size_t *pos, t_stack *stack_a)
{
	char	*tmp;
	t_stack	*tmp_stack;
	int		num;
	
	while (*argv)
	{
		num = 0;
		tmp = ft_strdup_c(argv, ' ');
		printf("tmp -> %s\n", tmp);
		if (ft_atoi(tmp, &num) || check_duplicate(&stack_a, num))
		{
			free(tmp);
			return (1);
		}
		tmp_stack = ft_lstnew(num, *pos - 1);
		printf("tmp-stack:\tcontent -> %d\tpos -> %zu\n", tmp_stack->content, tmp_stack->pos);
		if (tmp_stack)
			ft_lstadd_back(&stack_a, tmp_stack);
		printf("stack_a:\tcontent -> %d\tpos -> %zu\n", stack_a->content, stack_a->pos);
		free (tmp);
		pos++;
		while (*argv && *argv != ' ')
			argv++;
	}
	return (0);
}

int	fill_stack(size_t size, char **argv, t_stack *stack_a)
{
	size_t	i;
	size_t	j;

	i = 1;
	while (i < size)
	{
		j = 0;
		printf("\ni -> %zu\n", i);
		while (argv[i][j])
		{
			create_stack_arg (argv[i], &i, stack_a);
			// printf("pos -> %zu\n", i);
			j++;
		}
		i++;
	}
	return (0);
}

int	init_stacks(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!stack_a)
		return (0);
	stack_b = ft_calloc(argc, sizeof(t_stack));
	if (!stack_b)
	{
		free(stack_a);
		return (0);
	}
	printf("content -> %d\tpos -> %zu\n", stack_a->content, stack_a->pos);
	fill_stack(argc, argv, stack_a);
	while (stack_a->next != NULL)
	{
		printf("%d\n", stack_a->content);
		stack_a = stack_a->next;
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
