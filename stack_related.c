#include "push_swap.h"

void	fill_stack(t_stack **stack_a, char **input, int argc)
{
	long num;
	int i;

	i = 0;
	while(input[i] != NULL)
	{
		if (!valid_argument(input[i]))
			error_manage(input, 1, stack_a, argc);
		num = ft_atol(input[i]);
		if (((num > INT_MAX) || (num < INT_MIN)))
		{
			ft_putstr_fd("Incorrect argument type: number too big\n", 1);
			free_input(input, argc);
			free_stack(*stack_a);
			exit(1);
		}
		if (repeat_num(num, stack_a))
			error_manage(input, 2, stack_a, argc);
		append_node(stack_a, num);
		i++;
	}
}

void	append_node(t_stack **stack_a, int num)
{
	t_stack *new;

	new = malloc(sizeof(t_stack));
	if(!new)
		return;
	new->value = num;
	new->next = NULL;
	ft_lstaddback(stack_a, new);
}

/* INDEX */

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
/* POSITION */

void	set_position(t_stack *stack)
{
	t_stack *tmp;
	int i;

	i = 0;
	tmp = stack;
	while (tmp != NULL)
	{
		i++;
		tmp->position = i;
		tmp = tmp->next;
	}
}

void	send_to_b(t_stack **stack_a, t_stack **stack_b, int size)
{
	int dinamic_size;
	int i;
	
	i = 0;
	above_median(stack_a, size);
	while(i < size)
	{
		if ((*stack_a)->below_med == 1)			
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		i++;
	}
	dinamic_size = (get_size(*stack_a));
	while(dinamic_size > 3)
	{
		if ((*stack_a)->is_big != 1)
		{
			pb(stack_a, stack_b);
			dinamic_size--;
		}
		else
			ra(stack_a);
	}
}
