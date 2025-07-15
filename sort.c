/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagarri@student.42malaga.com <anagarri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:11:20 by anagarri@st       #+#    #+#             */
/*   Updated: 2025/07/15 13:25:29 by anagarri@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_three(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	tmp = *stack;
	while (!is_sorted(stack))
	{
		if (tmp->index == 3)
			ra(&tmp);
		else if (tmp->index > tmp->next->index)
			sa(&tmp);
		else if (tmp->index < tmp->next->index)
			rra(&tmp);
		*stack = tmp;
	}
}

void	sort_much(t_stack **stack_a, t_stack **stack_b, int size)
{
	t_stack	*cheapest;
	t_stack	*min_node;

	send_to_b(stack_a, stack_b, size);
	sort_three(stack_a);
	while (get_size(*stack_b) != 0)
	{
		calculate_costs(stack_a, stack_b);
		cheapest = find_cheapest(*stack_b);
		execute_move(cheapest, stack_a, stack_b);
	}
	min_node = find_min_node(*stack_a);
	set_position(*stack_a);
	if (min_node->position > med_position(*stack_a))
	{
		while ((*stack_a)->index != 1)
			rra(stack_a);
	}
	else if (min_node->position < med_position(*stack_a))
	{
		while ((*stack_a)->index != 1)
			ra(stack_a);
	}
}

int	best_target(t_stack *stack_a, int b_index)
{
	int		best_index;
	int		best_pos;
	t_stack	*a;

	best_index = INT_MAX;
	best_pos = 0;
	a = stack_a;
	while (a != NULL)
	{
		if (a->index > b_index && a->index < best_index)
		{
			best_index = a->index;
			best_pos = a->position;
		}
		a = a->next;
	}
	if (best_index == INT_MAX)
		best_pos = find_min_index(stack_a);
	return (best_pos);
}

void	set_target_pos(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*b;

	b = *stack_b;
	init_target_pos(*stack_b);
	while (b != NULL)
	{
		b->target_pos = best_target(*stack_a, b->index);
		b = b->next;
	}
}

void	execute_move(t_stack *cheapest, t_stack **stack_a, t_stack **stack_b)
{
	if (cheapest->cost_b == 0)
		cost_b_0(cheapest, stack_a);
	else if (cheapest->cost_b < 0)
		cost_b_n(cheapest, stack_a, stack_b);
	else
		cost_b_p(cheapest, stack_a, stack_b);
	pa(stack_a, stack_b);
}
