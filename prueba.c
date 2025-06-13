# include <stddef.h> // size_t
# include <stdlib.h> // malloc
# include <unistd.h> // write
# include <fcntl.h>  // flags open
# include <stdio.h> // printf
# include <limits.h> // INT_MAX & MIN
#include "libft/libft.h"
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

void	init_index(t_stack *stack)
{
	t_stack *tmp;

	tmp = stack;
	while (tmp != NULL)
	{
		tmp->index = 1;
		tmp = tmp->next;
	}
}
void	set_index(t_stack *stack)
{
	t_stack *tmp;
	t_stack *current;

	init_index(stack);
	tmp = stack;
	current = stack;
	while (current != NULL)
	{
		while (tmp != NULL)
		{
			if(current->value > tmp->value)
			{
				current->index++;
			}
			tmp = tmp->next;
		}
		tmp = stack;
		current = current->next;
	}
}

/*___________________________________________________________________________*/

t_stack *create_node(int value)
{
    t_stack *new_node = (t_stack *)malloc(sizeof(t_stack));
    if (new_node == NULL)
    {
        perror("Error al asignar memoria");
        exit(EXIT_FAILURE);
    }
    new_node->value = value;
    new_node->index = 0;
    new_node->position = 0;
    new_node->target_position = 0;
    new_node->prev = NULL;
    new_node->next = NULL;
    return new_node;
}

// Función para añadir un nodo al final de la lista
void add_back(t_stack **head, t_stack *new_node)
{
    if (*head == NULL)
    {
        *head = new_node;
    }
    else
    {
        t_stack *current = *head;
        while (current->next != NULL)
        {
            current = current->next;
        }
        current->next = new_node;
        new_node->prev = current;
    }
}

// Función para imprimir la lista (para verificar)
void print_list(t_stack *head)
{
    t_stack *current = head;
    printf("Lista de ejemplo:\n");
    while (current != NULL)
    {
        printf("  [Value: %d]\n", current->value); // Solo imprimimos el value por simplicidad
        current = current->next;
    }
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

// Función para liberar la memoria de la lista
void free_list(t_stack *head)
{
    t_stack *current = head;
    t_stack *next_node;
    while (current != NULL)
    {
        next_node = current->next;
        free(current);
        current = next_node;
    }
}


// --- Main para probar tus funciones ---

int main()
{
    t_stack *my_list = NULL; // Puntero al inicio de la lista

    // Valores no ascendentes para la lista
    int values[] = {5, 12, 3, 18, 7, 1, 15, 9, 20, 4};
    int i;
    const int LIST_LENGTH = sizeof(values) / sizeof(values[0]); // Calcula la longitud del array

    printf("Creando una lista enlazada de %d nodos con valores predefinidos...\n", LIST_LENGTH);

    for (i = 0; i < LIST_LENGTH; i++)
    {
        t_stack *new_node = create_node(values[i]);
        add_back(&my_list, new_node);
    }

    // Aquí puedes llamar a tus funciones para comprobarlas
    // Por ejemplo, para ver la lista que se creó:
    print_list(my_list);
	set_index(my_list);
	print_index(my_list);
    // No olvides liberar la memoria al final
    free_list(my_list);
    printf("Memoria de la lista liberada.\n");

    return 0;
}