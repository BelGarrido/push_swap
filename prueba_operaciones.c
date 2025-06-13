#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;
	t_stack *del;

	if (stack == NULL)
		return;
	tmp = stack;
	del = NULL;
	while (tmp != NULL)
	{
		del = tmp;
		tmp = tmp->next;
		free(del);
	}
	//free(stack);
}

void print_index(t_stack *head)
{
    t_stack *current = head;
    printf("Lista de ejemplo:\n");
    while (current != NULL)
    {
        printf("  [Val: %d] [In: %d]\n", current->value, current->index); // Solo imprimimos el value por simplicidad
        current = current->next;
    }
}

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

t_stack	*get_last(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst -> next != NULL)
		lst = lst -> next;
	return (lst);
}
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write (fd, &s[i], 1);
		i++;
	}
}
t_stack	*get_previous_last(t_stack *lst)
{

	if (lst == NULL)
		return (NULL);

	while (lst->next->next != NULL)
	{		
		lst = lst -> next;
	}
	return (lst);
}
void	ft_lstaddback(t_stack **lst, t_stack *new)
{
	t_stack	*last_node;

	last_node = *lst;
	if ((*lst) && new)
	{
		while (last_node -> next != NULL)
			last_node = last_node -> next;
		last_node -> next = new;
		//new->prev = last_node; DECIDIR
	}
	else if (!(*lst) && new)
	{
		*lst = new;
		new->prev = NULL;
	}
}
/*-----------------------------------------------------------------*/
void reverse_rotate(t_stack **stack)
{
	t_stack *tmp;
	t_stack *tail;
	t_stack *new_tail;

	tmp = (*stack);
	tail = get_last(*stack);
	new_tail = get_previous_last(*stack);
	(tail)->next = tmp;
	(*stack) = tail;
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
			//ra(&tmp);
			printf("DEBUG\n");
		}
		else if(tmp->index > tmp->next->index)
		{
			//sa(&tmp);
			printf("DEBUG\n");
			print_index(*stack);

		}
		else if(tmp->index < tmp->next->index)
		{
			rra(&tmp);
			printf("DEBUG\n");
			print_index(tmp);
		}
		*stack = tmp;
	}
	printf("FINAL\n");

}

// You still need to have these functions declared/defined elsewhere
// (e.g., in push_swap.h and your .c files)

int main(void)
{
    t_stack *node1;
    t_stack *node2;
    t_stack *node3;

    printf("--- Iniciando pruebas de sort_three con 3 nodos manuales ---\n");

    // --- Escenario 1: Lista desordenada (ej. 2, 1, 3 por índice) ---
    printf("\nEscenario 1: Inicial (2, 3, 1)\n");

    // Manually create and link nodes for (2, 2, 3)
    node1 = (t_stack *)malloc(sizeof(t_stack));
    node2 = (t_stack *)malloc(sizeof(t_stack));
    node3 = (t_stack *)malloc(sizeof(t_stack));

    if (!node1 || !node2 || !node3) {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }

    // Node 1 (head)
    node1->value = 20;
    node1->index = 2;
    node1->position = 0; // Not used in this test, but good to initialize
    node1->target_position = 0;
    node1->prev = NULL;
    node1->next = node2;

    // Node 2
    node2->value = 30;
    node2->index = 3;
    node2->position = 0;
    node2->target_position = 0;
    node2->prev = node1;
    node2->next = node3;

    // Node 3 (tail)
    node3->value = 10;
    node3->index = 1;
    node3->position = 0;
    node3->target_position = 0;
    node3->prev = node2;
    node3->next = NULL;

    t_stack *stack_a_s1 = node1; // Head of the list for Scenario 1

    printf("Antes de sort_three:\n");
    print_index(stack_a_s1);
    sort_three(&stack_a_s1);
    printf("Después de sort_three:\n");
    print_index(stack_a_s1);
     free_stack(stack_a_s1);

    // --- Escenario 2: Otra lista desordenada (ej. 3, 1, 2 por índice) ---
    printf("\nEscenario 2: Inicial (3, 1, 2)\n");

    // Manually create and link nodes for (3, 1, 2)
    node1 = (t_stack *)malloc(sizeof(t_stack));
    node2 = (t_stack *)malloc(sizeof(t_stack));
    node3 = (t_stack *)malloc(sizeof(t_stack));

    if (!node1 || !node2 || !node3) {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }

    // Node 1 (head)
    node1->value = 30;
    node1->index = 3;
    node1->position = 0;
    node1->target_position = 0;
    node1->prev = NULL;
    node1->next = node2;

    // Node 2
    node2->value = 10;
    node2->index = 1;
    node2->position = 0;
    node2->target_position = 0;
    node2->prev = node1;
    node2->next = node3;

    // Node 3 (tail)
    node3->value = 20;
    node3->index = 2;
    node3->position = 0;
    node3->target_position = 0;
    node3->prev = node2;
    node3->next = NULL;

    t_stack *stack_a_s2 = node1; // Head of the list for Scenario 2

    printf("Antes de sort_three:\n");
    print_index(stack_a_s2);
    sort_three(&stack_a_s2);
    printf("Después de sort_three:\n");
    print_index(stack_a_s2);
     free_stack(stack_a_s2);

    // --- Escenario 3: Lista ya ordenada (ej. 1, 2, 3 por índice) ---
    printf("\nEscenario 3: Inicial (1, 2, 3) - No debería hacer nada\n");

    // Manually create and link nodes for (1, 2, 3)
    node1 = (t_stack *)malloc(sizeof(t_stack));
    node2 = (t_stack *)malloc(sizeof(t_stack));
    node3 = (t_stack *)malloc(sizeof(t_stack));

    if (!node1 || !node2 || !node3) {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }

    // Node 1 (head)
    node1->value = 10;
    node1->index = 1;
    node1->position = 0;
    node1->target_position = 0;
    node1->prev = NULL;
    node1->next = node2;

    // Node 2
    node2->value = 20;
    node2->index = 2;
    node2->position = 0;
    node2->target_position = 0;
    node2->prev = node1;
    node2->next = node3;

    // Node 3 (tail)
    node3->value = 30;
    node3->index = 3;
    node3->position = 0;
    node3->target_position = 0;
    node3->prev = node2;
    node3->next = NULL;

    t_stack *stack_a_s3 = node1; // Head of the list for Scenario 3

    printf("Antes de sort_three:\n");
    print_index(stack_a_s3);
    sort_three(&stack_a_s3);
    printf("Después de sort_three:\n");
    print_index(stack_a_s3);
     free_stack(stack_a_s3);

    printf("\n--- Todas las pruebas completadas ---\n");
    return 0;
}