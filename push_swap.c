#include "push_swap.h"

int	is_sorted(t_stack *stack_a)
{
	while (stack_a->next != NULL)
	{
		if (stack_a->value > stack_a->next->value)
		{
			// Not sorted
			return (0);
		}
		stack_a = stack_a->next;
		// Sorted
	}
	return (1);
}

/****** push_swap() ********/
// Check the stack A is sorted?
	// YES - DONE 
	// NO 
	// if 2 values -> sa
	// if 3 values -> sort_three()
	// if > 3 values -> sort_algorithm()
	
/* int push_swap(t_stack **stack_a, t_stack **stack_b, int stack_a_size)
{
	if (stack_a_size == 2 && !is_sorted(*stack_a))
		sa(stack_a);
	else if (stack_a_size == 3 && !is_sorted(*stack_a))
		sort_three(stack_a);
	else if (stack_a_size > 3 && !is_sorted(*stack_a))
		sort_algorithm(stack_a, stack_b);
} */


/****** sort_algorithm() ********/
//{
	// Pb everthing but 3 elements to stack B
	// Sort_three() the remaining 3 elements in stack A
	// While there's elements in stack B
		// Calculate position: Find the position of numbers in A and B
							// Find the target position in stack B
		// Get the cheapest action
		// Execute the sequence of actions
	// Rotate stack A if needed
//}

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
        printf("%d\n", current->value); // Imprime el valor del nodo actual
        current = current->next;        // Avanza al siguiente nodo
    }
}
int	main(int argc, char *argv[])
{	
	t_stack *stack_a;
	t_stack *stack_b;
	int stack_size;
	char **input;
	
	input = arg_prep(argc, argv);
	int i = 0;
	while(i < 6)
	{
		printf("input: %s\n", input[i]);
		i++;
	}
	stack_a = NULL;
	fill_stack(&stack_a, input, argc);
	stack_b = NULL;
	print_stack(stack_a);
	// Get size of the stack A
	stack_size = get_size(stack_a);
	/***************************** OK ***********************************/

	printf("size of stack a: %i\n", stack_size);
	// Assign index in the stack A to know the smallest and bigger
		//assign_index(/* & */stack_a);
		//push_swap(&stack_a, &stack_b, stack_size);
	// free stack a
	free_input(input, argc);
	free_stack(stack_a);
	free(stack_b);
	return 0;
}


