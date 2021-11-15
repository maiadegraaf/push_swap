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

int	main(int argc, char **argv)
{
	int	ret;
	if (argc < 1)
		return (0);
	else
	{
		ret = init_stacks(argc, argv);
		if (ret == 1)
			write (1, "Error\n", 6);
	}
}
