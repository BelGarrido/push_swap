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
	t_stack *min_node;

	send_to_b(stack_a, stack_b, size);
	//printf("SORT_MUCH: send_to_b: stack A\n");
	//print_med(*stack_a);
	//printf("SORT_MUCH: send_to_b: stack B\n");
	//print_med(*stack_b);
	sort_three(stack_a);
	//For every element of B
	while (get_size(*stack_b) != 0)
	{
		calculate_costs(stack_a, stack_b);
		cheapest = find_cheapest(*stack_b);
		//printf("CHEAPEST_NODE: %i\n", cheapest->value);
		execute_move(cheapest, stack_a, stack_b);
		//printf("🌠🌠🌠STACK A AFTER MOVEEES🌠🌠🌠\n");
		//print_med(*stack_a);
	}
	//printf("🦋ALL SORTED KINDO OF🦋\n");
	//print_med(*stack_a);

	//If stack A is not sorted, chose between ra and rra to rotate it into ascending order.
	//printf("med_position: %i\n", med_position(*stack_a));
	min_node = find_min_node(*stack_a);
	//printf("min node: %i\n", min_node->value);
	set_position(*stack_a);	
	if (min_node->position > med_position(*stack_a))
	{
		while((*stack_a) ->index != 1)
		{
			//printf("🦜🦜🦜🦜🦜🦜\n");
			rra(stack_a);
		}
	}
	else if (min_node->position < med_position(*stack_a))
	{
		while((*stack_a) ->index != 1)
		{
			//printf("🪼🪼🪼🪼🪼🪼\n");
			ra(stack_a);
		}
	}
	//printf("FINAL SORTED \n");
	//print_med(*stack_a);
}

t_stack	*find_min_node(t_stack *stack)
{
	int lower_index;
	t_stack *tmp;
	t_stack *min;
 	
	if (!stack)
        return NULL;
	tmp = stack;
	min = stack;
	lower_index = tmp->index;
	while (tmp != NULL)
	{
		if (tmp->index < lower_index)
		{
			lower_index = tmp->index;
			min = tmp;
		}
		tmp = tmp->next;
	}
	return (min);
}

void	calculate_costs(t_stack **stack_a, t_stack **stack_b)
{
	//printf("CALCULATE_COSTS: \n");
	//Find the current position of every element in stack A and B.
	set_position(*stack_a);
	set_position(*stack_b);
	set_target_pos(stack_a, stack_b);
	//print_med(*stack_b);
	calculate_individual_costs(stack_a, stack_b);
}

void	set_target_pos(t_stack **stack_a, t_stack **stack_b)
{
	int	best_index;
	int	best_pos;
	t_stack *a;
	t_stack *b;

	a = *stack_a;
	b = *stack_b;
	//printf("SET_TARGET_POS: now b->tp should be -1\n");
	init_target_pos(*stack_b); //now all of them are -1; no FUNCIONAAAAA
	//print_med(*stack_b);

	while(b != NULL)
	{
		best_index = INT_MAX;
		best_pos = 0;
		a = *stack_a;
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
		//printf("tagert position of b (%i) %i\n", b->value, b->target_pos);
		b = b->next;
	}
	//b->target_pos = best_pos; //problemis
	//printf("SET_TARGET_POS: best_position = %i\n", best_pos);
/* 	//printf("SSET_TARGET_POS: stack A\n");
	print_med(*stack_a);
	//printf("SSET_TARGET_POS: stack B\n");
	print_med(*stack_b); */
}

void	init_target_pos(t_stack *stack)
{
	t_stack *tmp;

	tmp = stack;
	while (tmp != NULL)
	{
		tmp->target_pos = -1;
		tmp = tmp->next;
	}
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
	//printf("📈📈📈CALCULATE INDIVIDUAL COSTS📈📈📈\n");

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
	if(size == 0)
		return (0);
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

void	cost_b_p(t_stack *cheapest, t_stack **stack_a, t_stack **stack_b)
{
	if (cheapest->cost_a < 0)
	{
		while (cheapest->cost_a < 0)
		{
			rra(stack_a);
			cheapest->cost_a++;
		}
		while (cheapest->cost_b > 0)
		{
			rb(stack_b);
			cheapest->cost_b--;
		}
	}
	else if (cheapest->cost_a > 0)
	{
		while (cheapest->cost_a > 0 && cheapest->cost_b > 0)
		{
			rr(stack_a, stack_b);
			cheapest->cost_a--;
			cheapest->cost_b--;
		}
		if (cheapest->cost_a != 0)
		{
			while(cheapest->cost_a > 0)
			{
				ra(stack_a);
				cheapest->cost_a--;
			}
		}	
		else if (cheapest->cost_b != 0)
		{
			while(cheapest->cost_b > 0)
			{
				rb(stack_b);
				cheapest->cost_b--;
			}
		}
	}
	else
	{
		while (cheapest->cost_b > 0)
		{
			rb(stack_b);
			cheapest->cost_b--;
		}
	}
}

void	cost_b_n(t_stack *cheapest, t_stack **stack_a, t_stack **stack_b)
{
	if (cheapest->cost_a > 0)
	{
		while (cheapest->cost_a > 0)
		{
			ra(stack_a);
			cheapest->cost_a--;
		}
		while (cheapest->cost_b < 0)
		{
			rrb(stack_b);
			cheapest->cost_b++;
		}
	}
	else if (cheapest->cost_a < 0)
	{
		while (cheapest->cost_a < 0 && cheapest->cost_b < 0)
		{
			rrr(stack_a, stack_b);
			cheapest->cost_a++;
			cheapest->cost_b++;
		}
		if (cheapest->cost_a != 0)
		{	
			while (cheapest->cost_a < 0)
			{
				rra(stack_a);
				cheapest->cost_a++;
			}
			//bucle inecesario
			while (cheapest->cost_a > 0)
			{
				ra(stack_a);
				cheapest->cost_a--;
			}
		}
		else if (cheapest->cost_b != 0)
		{		
			while (cheapest->cost_b < 0)
			{
				rrb(stack_b);
				cheapest->cost_b++;
			}
			//bucle innecesario
			while (cheapest->cost_b > 0)
			{
				rb(stack_b);
				cheapest->cost_b--;
			}
		}
	}
	else
	{
		while (cheapest->cost_b < 0)
		{
			rrb(stack_b);
			cheapest->cost_b++;
		}
	}
}

void	cost_b_0(t_stack *cheapest, t_stack **stack_a)
{
	if (cheapest->cost_a < 0)
	{
		while (cheapest->cost_a < 0)
		{
			rra(stack_a);
			cheapest->cost_a++;
		}
	}
	else if (cheapest->cost_a > 0)
	{
		while (cheapest->cost_a > 0)
		{
			ra(stack_a);
			cheapest->cost_a--;
		}
	}
}

void	execute_move(t_stack *cheapest, t_stack **stack_a, t_stack **stack_b)
{
		////printf("🎪🎪🎪 EXECUTE MOVE: stack B 🎪🎪🎪\n");
		//print_med(*stack_b);
		//printf("cheapest value: %i\n", cheapest->value);
		if(cheapest->cost_b == 0)
		{
			//printf("🎪b0\n");
			cost_b_0(cheapest, stack_a);
		}
		else if (cheapest->cost_b < 0)
		{
			//printf("🎪bn\n");
			cost_b_n(cheapest, stack_a, stack_b);
		}
		else
		{
			//printf("🎪bp\n");
			cost_b_p(cheapest, stack_a, stack_b);
		}
		pa(stack_a, stack_b);
}