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
int		ft_n_atoi(const char *str, int *ret);
int		init_stacks(int argc, char **argv);
void	ft_stackclear(t_stack **lst);

#endif