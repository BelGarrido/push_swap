/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   costs_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagarri@student.42malaga.com <anagarri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/15 12:12:41 by anagarri@st       #+#    #+#             */
/*   Updated: 2025/07/15 13:06:07 by anagarri@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	both_postive(t_stack *cheapest, t_stack **stack_a, t_stack **stack_b)
{
	while (cheapest->cost_a > 0 && cheapest->cost_b > 0)
	{
		rr(stack_a, stack_b);
		cheapest->cost_a--;
		cheapest->cost_b--;
	}
	if (cheapest->cost_a != 0)
	{
		while (cheapest->cost_a > 0)
		{
			ra(stack_a);
			cheapest->cost_a--;
		}
	}
	else if (cheapest->cost_b != 0)
	{
		while (cheapest->cost_b > 0)
		{
			rb(stack_b);
			cheapest->cost_b--;
		}
	}
}

void	both_negative(t_stack *cheapest, t_stack **stack_a, t_stack **stack_b)
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
	}
	else if (cheapest->cost_b != 0)
	{
		while (cheapest->cost_b < 0)
		{
			rrb(stack_b);
			cheapest->cost_b++;
		}
	}
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
		both_postive(cheapest, stack_a, stack_b);
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
		both_negative(cheapest, stack_a, stack_b);
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
