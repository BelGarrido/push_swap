#include "push_swap.h"

void	rotate(t_stack **stack)
{
	t_stack *tmp;
	t_stack *tail;

	tmp = *stack;
	tail = get_last(*stack);
    (*stack) = (*stack)->next;
	tail->next = tmp;
	tmp->next = NULL;
}

void	ra(t_stack **stack_a)
{
	rotate(stack_a);
	ft_putstr_fd("ra\n", 1);
}

void	rb(t_stack **stack_b)
{
	rotate(stack_b);
	ft_putstr_fd("rb\n", 1);
}

void	rr(t_stack **stack_a, t_stack **stack_b)
{
	rotate(stack_a);
	rotate(stack_b);
	ft_putstr_fd("rr\n", 1);
}

/* int main(void)
{
	t_stack *list;
	t_stack *uno;
	t_stack *dos;

	list = malloc(sizeof(t_stack)); 
	uno = malloc(sizeof(t_stack));
	dos = malloc(sizeof(t_stack));

	(list)->index = 1;
	uno->index = 2;
	dos->index = 3;
	(list)->next = uno;
	uno->next = dos;
	dos->next = NULL;

	printf("1º: %i\n", (list)->index);
	printf("2º: %i\n", (list->next)->index);
	printf("3º: %i\n", (list->next)->next->index);
	reverse_rotate(&list);
	printf("1º: %i\n", (list)->index);
	printf("2º: %i\n", (list->next)->index);
	printf("3º: %i\n", (list->next)->next->index);
} */