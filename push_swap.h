#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include "libft/libft.h"
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_stack
{
	int				content;
	size_t			pos;
	long			order;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

//stack_utils
t_stack	*ft_stacknew(int content, size_t pos, long order);
void	ft_stackadd_back(t_stack **lst, t_stack *new);
void	ft_stackclear(t_stack **lst);
void	ft_stackadd_front(t_stack **lst, t_stack *new);
t_stack	*ft_stacklast(t_stack *stack);

//utils
int		ft_n_atoi(const char *str, int *ret);
void	print_stacks(t_stack *stack_a, t_stack *stack_b);
t_stack	*find_lowest_num(t_stack *stack);
t_stack	*find_next_lowest_num(t_stack *stack);
int		check_order(t_stack *stack);

//init_stacks
t_stack	*fill_stack(size_t size, char **argv, t_stack *stack_a);
t_stack	*create_stack_arg(char *argv, size_t *pos);
int		check_duplicate(t_stack **stack_a, int num, size_t pos);

//swap&push
void	ft_swap_both(t_stack **stack_a, t_stack **stack_b);
void	ft_swap(t_stack **stack, char c);
void	ft_push(t_stack **from, t_stack **to, char c);

//rotate
void	ft_rotate_both(t_stack **stack_a, t_stack **stack_b, int i);
void	ft_rotate(t_stack **stack, char c);
void	ft_rrotate(t_stack **stack, char c);

//small_stack
void	under_three(t_stack **stack_a, int arr[3]);
void	lowest_to_b(t_stack **stack_a, t_stack **stack_b, size_t size);
void	force_sort(t_stack **stack_a, t_stack **stack_b, size_t size);

//push_swap
void	push_swap(int argc, char **argv);

//chunks
void	solve(t_stack **stack_a, t_stack **stack_b, int argc);
t_stack	*find_median(t_stack *s, int size);
void	push_lt_med(t_stack **stack_a, t_stack **stack_b, long median);

#endif