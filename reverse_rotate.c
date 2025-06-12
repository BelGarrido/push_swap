#include "push_swap.h"

void reverse_rotate(t_stack **stack)
{
	t_stack *tmp;
	t_stack *tail;
	t_stack *new_tail;

	tmp = (*stack);
	tail = get_last(*stack);
	new_tail = get_previous_last(*stack);
	(*stack) = tail;
	(*stack)->next = tmp;
	new_tail->next = NULL;
}
void	rra(t_stack **stack_a)
{
	reverse_rotate(stack_a);
	ft_putstr_fd("rra\n", 1);
}

void	rrb(t_stack **stack_b)
{
	reverse_rotate(stack_b);
	ft_putstr_fd("rrb\n", 1);
}

void	rrr(t_stack **stack_a, t_stack **stack_b)
{
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	ft_putstr_fd("rrr\n", 1);
}