#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	tmp = *stack;
	while (!is_sorted(stack))
	{
		if(tmp->index == 3)
		{
			ra(&tmp);
		}
		else if(tmp->index > tmp->next->index)
		{
			sa(&tmp);
		}
		else if(tmp->index < tmp->next->index)
		{
			rra(&tmp);
		}
		*stack = tmp;
	}
}
