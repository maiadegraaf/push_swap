#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
// # include "libft/libft.a"
# include <stdlib.h>
# include <stdio.h>

typedef struct	s_stack
{
	int				content;
	size_t			pos;
	struct s_stack	*next;
}	t_stack;

t_stack	*ft_lstnew(int content, size_t pos);
void	ft_lstadd_back(t_stack **lst, t_stack *new);
char	*ft_strdup_c(const char *s1, char c);
int		ft_isdigit(int c);
int		ft_atoi(const char *str, int *ret);
void	*ft_calloc(size_t count, size_t size);
void	*ft_bzero(void *str, size_t n);

#endif