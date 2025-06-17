# include <stddef.h> // size_t
# include <stdlib.h> // malloc
# include <unistd.h> // write
# include <fcntl.h>  // flags open
# include <stdio.h> // printf
# include <limits.h> // INT_MAX & MIN
//#include "libft.h"	// library

typedef struct s_stack
{
	int	value;
	int index;
	int position;
	int target_position;
	struct s_stack	*prev;
	struct s_stack	*next;
}	t_stack;

int	get_size(t_stack *lst)
{
	int	count;

	count = 1;
	if (lst == NULL)
		return (0);
	while (lst -> next != NULL)
	{
		count++;
		lst = lst -> next;
	}
	return (count);
}

int	main (void)
{
	int size;
	int number;

	size = 5;
	number = size / 2;
	printf("%i\n", number);
	return (number);

}

