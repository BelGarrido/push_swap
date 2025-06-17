#include "push_swap.h"

int	is_sorted(t_stack **stack)
{
	t_stack *tmp;

	tmp = *stack;
	while (tmp != NULL && tmp->next != NULL)
	{
		if (tmp->index > tmp->next->index)
		{
			// Not sorted
			return (0);
		}
		tmp = tmp->next;
		// Sorted
	}
	return (1);
}

void push_swap(t_stack **stack_a, t_stack **stack_b, int stack_a_size)
{
	printf("PUSH_SWAP\n");
	if (stack_a_size == 2 && !is_sorted(stack_a))
		sa(stack_a);
	else if (stack_a_size == 3 && !is_sorted(stack_a))
		sort_three(stack_a);
	else if (stack_a_size > 3 && !is_sorted(stack_a))
	{
		sort_three(stack_b);
		//sort_algorithm(stack_a, stack_b);
	}
	else
		return ;
}

void print_stack(t_stack *stack)
{
    if (!stack) // Comprueba si el stack está vacío
    {
        printf("El stack está vacío.\n");
        return;
    }

    t_stack *current = stack; // Crea un puntero temporal para recorrer el stack

    printf("Contenido del stack:\n");
    while (current) // Recorre la lista mientras el puntero no sea NULL
    {
        printf("  %d\n", current->value); // Imprime el valor del nodo actual
        current = current->next;        // Avanza al siguiente nodo
    }
}

void print_nodes(t_stack *head)
{
    t_stack *current = head;
    printf("Stack:\n");
    while (current != NULL)
    {
        printf("  [Val: %d] [In: %d] [Ps: %d]\n", current->value, current->index, current->position);
        current = current->next;
    }
}

void print_med(t_stack *head)
{
    t_stack *current = head;
    printf("Stack:\n");
    while (current != NULL)
    {
        printf("  [Val: %d] [In: %d] [MED: %d] [BIG: %d]\n", current->value, current->index, current->below_med, current->is_big);
        current = current->next;
    }
}
/* ____________________________________________________________________________

*/
int	main(int argc, char *argv[])
{	
	t_stack *stack_a;
	t_stack *stack_b;
	int stack_size;
	char **input;
	
	input = arg_prep(argc, argv);
	stack_a = NULL;
	fill_stack(&stack_a, input, argc);
	stack_b = NULL;
	print_nodes(stack_a);
	stack_size = get_size(stack_a);

	printf("size of stack a: %i\n", stack_size);
	set_index(stack_a);
	printf("set_index ----- stack_a: \n");
	print_nodes(stack_a);
	set_position(stack_a);
	printf("set_position ----- stack_a: \n");
	print_nodes(stack_a);

	send_to_b(&stack_a, &stack_b, stack_size);
	printf("send_to_b ----- stack_a: \n");
	printf("stack_a: \n");
	print_med(stack_a);
	printf("stack_b: \n");
	print_med(stack_b);

	/***************************** OK ***********************************/
	//push_swap(&stack_a, &stack_b, stack_size);
	printf("AFTER_PS\n");
	print_stack(stack_a);
	free_input(input, argc);
	free_stack(stack_a);
	//free(stack_b);
	return 0;
}


