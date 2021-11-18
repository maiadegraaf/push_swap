#include "push_swap.h"

int	ft_n_atoi(const char *str, int *ret)
{
	int	p_n;
	int	i;

	i = 0;
	p_n = 1;
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

void	print_stacks(t_stack *stack_a, t_stack *stack_b)
{
	int i = 0;

	printf("stack a\n");
	while (stack_a)
	{
		printf("content -> %d\tpos -> %zu\n", stack_a->content, stack_a->pos);
		stack_a = stack_a->next;
		i++;	
	}
	i = 0;
	printf("stack b\n");
	while (stack_b)
	{
		printf("content -> %d\tpos -> %zu\n", stack_b->content, stack_b->pos);
		stack_b = stack_b->next;
		i++;	
	}
} 

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