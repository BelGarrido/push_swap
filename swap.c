#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack *first;
	t_stack *second;

	if (!stack || !*stack || !(*stack)->next)
		return;

	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
	//printf("stack: %i\n", (*stack)->index);
	//printf("(*stack)->next: %i\n", (*stack)->next->index);
}

void	sa(t_stack **stack_a)
{
	swap(stack_a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **stack_b)
{
	swap(stack_b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr_fd("ss\n", 1);
}