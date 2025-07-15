/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagarri@student.42malaga.com <anagarri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 13:01:50 by anagarri@st       #+#    #+#             */
/*   Updated: 2025/07/15 13:03:04 by anagarri@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_stack	*find_cheapest(t_stack *stack)
{
	t_stack	*cheapest;
	t_stack	*s;
	int		min_cost;
	int		current_cost;

	min_cost = INT_MAX;
	s = stack;
	cheapest = s;
	while (s != NULL)
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

void	calculate_individual_costs(t_stack **stack_a, t_stack **stack_b)
{
	t_stack	*b;
	int		med_a;
	int		med_b;
	int		size_a;
	int		size_b;

	size_a = get_size(*stack_a);
	size_b = get_size(*stack_b);
	med_a = med_position(*stack_a);
	med_b = med_position(*stack_b);
	b = *stack_b;
	while (b != NULL)
	{
		if (b->position <= med_b)
			b->cost_b = (b->position - 1);
		else
			b->cost_b = (size_b - (b->position - 1)) * -1;
		if (b->target_pos <= med_a)
			b->cost_a = b->target_pos - 1;
		else
			b->cost_a = (size_a - (b->target_pos - 1)) * -1;
		b = b->next;
	}
}

void	calculate_costs(t_stack **stack_a, t_stack **stack_b)
{
	set_position(*stack_a);
	set_position(*stack_b);
	set_target_pos(stack_a, stack_b);
	calculate_individual_costs(stack_a, stack_b);
}
