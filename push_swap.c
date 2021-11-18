#include "push_swap.h"
int	check_order(t_stack *stack)
{
	while(stack->next != NULL)
	{
		if(stack->next->content > stack->content)
			stack = stack->next;
		else
			return (0);
	}
	return (1);
}

t_stack	*find_lowest_num(t_stack *stack)
{
	t_stack	*lowest_num;
	
	lowest_num = ft_stacknew(stack->content, stack->pos);
	while(stack)
	{
		if (stack->content < lowest_num->content)
		{
			lowest_num->content = stack->content;
			lowest_num->pos	= stack->pos;
		}
		stack = stack->next;
	}
	return (lowest_num);
}

void	under_three(t_stack **stack_a, int arr[3])
{
	if (arr[0] > arr[1] && arr[0] < arr[2])
		ft_swap(stack_a, 'a');
	else if (arr[0] > arr[1] && arr[0] > arr[2])
	{
		if (arr[1] > arr[2])
		{
			ft_swap(stack_a, 'a');
			ft_rrotate(stack_a, 'a');
		}
		else
			ft_rotate(stack_a, 'a');
	}
	else if (arr[0] < arr[1] && arr[0] < arr[2])
	{
		ft_swap(stack_a, 'a');
		ft_rotate(stack_a, 'a');
	}
	else
		ft_rrotate(stack_a, 'a');
}

void	lowest_to_b(t_stack **stack_a, t_stack **stack_b, size_t size)
{
	size_t	i;
	t_stack	*lowest_num;

	i = 0;
	while (i < size - 4)
	{
		lowest_num = find_lowest_num(*stack_a);
		if (lowest_num->pos > size / 2)
		{
			while ((*stack_a)->content != lowest_num->content)
				ft_rrotate(stack_a, 'a');
		}
		else
		{
			while ((*stack_a)->content != lowest_num->content)
				ft_rotate(stack_a, 'a');
		}
		ft_push(stack_a, stack_b, 'b');
		i++;
	}
}

void	force_sort(t_stack **stack_a, t_stack **stack_b, size_t size)
{
	int 	arr[3];
	size_t	i;

	i = 0;

	if (size > 4)
		lowest_to_b(stack_a, stack_b, size);
	arr[0] = (*stack_a)->content;
	arr[1] = (*stack_a)->next->content;
	arr[2] = (*stack_a)->next->next->content;
	under_three(stack_a, arr);
	if (size > 4)
	{
		while (i < size - 4)
		{
			ft_push(stack_b, stack_a, 'a');
			i++;
		}
	}
}

void	push_swap(int argc, char **argv)
{
	t_stack	*stack_a;
	t_stack	*stack_b;

	stack_a = NULL;
	stack_a = fill_stack(argc, argv, stack_a);
	stack_b = NULL;
	if (!stack_a)
		write (1, "Error\n", 6);
	else if (check_order(stack_a))
		return ;
	else if (argc < 7 && argc > 3)
		force_sort(&stack_a, &stack_b, argc);
	else if(argc == 3)
		ft_swap(&stack_a, 'a');
	print_stacks(stack_a, stack_b);
}

int	main(int argc, char **argv)
{
	if (argc < 1)
		return (0);
	else
	{
		push_swap(argc, argv);
	}
}
