#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	t_stack	*tmp;

	printf("SORT_THREE\n");
	tmp = *stack;
	while (!is_sorted(stack))
	{
		//printf("IS_SORTED: %i\n", is_sorted(stack));
		if(tmp->index == 3)
		{
			ra(&tmp);
			printf("DEBUG\n");
		}
		else if(tmp->index > tmp->next->index)
		{
			sa(&tmp);
			printf("DEBUG\n");
		}
		else if(tmp->index < tmp->next->index)
		{
			rra(&tmp);
			printf("DEBUG\n");
		}
		*stack = tmp;
	}
}
