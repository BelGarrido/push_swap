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
			ra(&tmp);
		else if(tmp->index > tmp->next->index)
			sa(&tmp);
		else if(tmp->index < tmp->next->index)
			rra(&tmp);
		*stack = tmp;
	}
}


void	sort_much(t_stack **stack_a, t_stack **stack_b, int size)
{
	t_stack *cheapest;

	printf("SORT_MUCH: send_to_b\n");
	send_to_b(stack_a, stack_b, size);
	print_med(*stack_a);
	print_med(*stack_b);
	printf("SORT_MUCH: sort_three\n");
	sort_three(stack_a);
	//For every element of B
	printf("SORT_MUCH: before bucle del algoritmo\n");
	int i = 0;
	while (/* get_size(*stack_b) != 0 */ i < 7)
	{
		//Calculate the number of actions (the cost) to put each element in stack B at its target position in stack A and choose the element that’s cheapest to move.
		calculate_costs(stack_a, stack_b);
		cheapest = find_cheapest(*stack_b);
		printf("CHEAPEST_NODE: %i\n", cheapest->value);
		//Execute the sequence of actions needed to move the element from stack B to stack A.
		execute_move(cheapest, stack_a, stack_b);
		i++;
	}
	//If stack A is not sorted, chose between ra and rra to rotate it into ascending order.
	/* while(!is_sorted(stack_b))
	{
		rrb(stack_b);
	} */
}

void	calculate_costs(t_stack **stack_a, t_stack **stack_b)
{
	printf("CALCULATE_COSTS: \n");
	//Find the current position of every element in stack A and B.
	set_position(*stack_a);
	set_position(*stack_b);
	set_target_pos(stack_a, stack_b);
	calculate_individual_costs(stack_a, stack_b);
}

void	set_target_pos(t_stack **stack_a, t_stack **stack_b)
{
	printf("SET_TARGET_POS: \n");
	int	best_index;
	int	best_pos;
	t_stack *a;
	t_stack *b;

	best_index = INT_MAX;
	a = *stack_a;
	b = *stack_b;
	printf("SET_TARGET_POS: now b->tp should be -1\n");
	init_target_pos(*stack_b); //now all of them are -1; no FUNCIONAAAAA
	print_med(*stack_b);

	while(b != NULL)
	{
		printf("SET_TARGET_POS: inside de loop \n");

		while(a != NULL)
		{
			if (a->index > b->index && a->index < best_index)
			{
				best_index = a->index;
				best_pos = a->position;
			}
			a = a->next;
		}
		if(best_index == INT_MAX)
			best_pos = find_min_index(*stack_a);
		b->target_pos = best_pos; 
		b = b->next;
		a = *stack_a;
	}
	//b->target_pos = best_pos; //problemis
	printf("SET_TARGET_POS: best_position = %i\n", best_pos);
	print_med(*stack_a);
	print_med(*stack_b);
}

void	init_target_pos(t_stack *stack)
{
	t_stack *tmp;
	printf("INTIT_TARGET_POSITION:\n");

	tmp = stack;
	while (tmp != NULL)
	{
		tmp->target_pos = -1;
		tmp = tmp->next;
	}
	print_med(stack);

}

int	find_min_index(t_stack *stack)
{
	int	lower_pos;
	int lower_index;
	t_stack *tmp;

	tmp = stack;
	lower_index = tmp->index;
	while (tmp != NULL)
	{
		if (tmp->index < lower_index)
		{
			lower_index = tmp->index;
			lower_pos = tmp->position;
		}
		tmp = tmp->next;
	}
	return (lower_pos);
}

void	calculate_individual_costs(t_stack **stack_a, t_stack **stack_b)
{
	printf("CALCULATE INDIVIDUAL COSTS\n");

	t_stack *b;
	int		med_a;
	int		med_b;
	int		size_a;
	int		size_b;

	size_a = get_size(*stack_a);
	size_b = get_size(*stack_b);
	med_a = med_position(*stack_a);
	med_b = med_position(*stack_b);
	b = *stack_b;

	while(b != NULL)
	{
		if (b->position <= med_b)
			b->cost_b = (b->position - 1);
		else
			b->cost_b = (size_b - (b->position - 1)) * -1;
		if (b->target_pos <=med_a)
			b->cost_a = b->target_pos - 1;
		else
			b->cost_a = (size_a - (b->target_pos - 1)) * -1;
		b = b->next;
	}
}

int	med_position(t_stack *stack)
{
	int med_pos;
	int size;

	size = get_size(stack);
	med_pos = 0;
	if (size % 2 == 0)
	{
		med_pos = size / 2;
	}
	else if (size % 2 != 0)
	{
		med_pos = (size + 1 )/ 2;
	}
	return (med_pos);
}

t_stack	*find_cheapest(t_stack *stack)
{	
	t_stack *cheapest;
	t_stack	*s;
	int min_cost;
	int current_cost;
	
	min_cost = INT_MAX;
	s = stack;
	cheapest = s;
	while(s != NULL)
	{
		if (s->cost_a * s->cost_b > 0)
			current_cost = max_value(ft_abs(s->cost_a), ft_abs(s->cost_b));
		else
			current_cost = ft_abs(s->cost_a) + ft_abs(s->cost_b);
		if (current_cost < min_cost)
		{
			min_cost = current_cost;
			cheapest = s;
		}
		s = s->next;
	}
	return (cheapest);
}

void	execute_move(t_stack *cheapest, t_stack *stack_a, t_stack *stack_b)
{
		printf("🎪 EXECUTE MOVE\n");
		print_med(cheapest);
		if (stack->cost_a == 0 && stack->cost_b == 0)
			pa(&stack_a, stack_b);
}
