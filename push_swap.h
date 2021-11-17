#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_stack
{
	int				content;
	size_t			pos;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

t_stack	*ft_stacknew(int content, size_t pos);
void	ft_stackadd_back(t_stack **lst, t_stack *new);
void	ft_stackclear(t_stack **lst);
void	ft_stackadd_front(t_stack **lst, t_stack *new);
int		ft_n_atoi(const char *str, int *ret);
t_stack	*fill_stack(size_t size, char **argv, t_stack *stack_a);
t_stack	*ft_stacklast(t_stack *stack);
void	ft_swap_both(t_stack **stack_a, t_stack **stack_b);
void	ft_swap(t_stack **stack, char c);
void	ft_push(t_stack **from, t_stack **to, char c);
void	ft_rotate_both(t_stack **stack_a, t_stack **stack_b, int i);
void	ft_rotate(t_stack **stack, char c);
void	ft_rrotate(t_stack **stack, char c);
void	print_stacks(t_stack *stack_a, t_stack *stack_b, int argc);


#endif