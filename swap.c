/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagarri@student.42malaga.com <anagarri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:10:40 by anagarri@st       #+#    #+#             */
/*   Updated: 2025/06/24 10:11:30 by anagarri@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap(t_stack **stack)
{
	t_stack	*first;
	t_stack	*second;

	if (!stack || !*stack || !(*stack)->next)
		return ;
	first = *stack;
	second = (*stack)->next;
	first->next = second->next;
	second->next = first;
	*stack = second;
}

void	sa(t_stack **stack_a)
{
	swap(stack_a);
	ft_putstr_fd("sa\n", 1);
}

void	sb(t_stack **stack_b)
{
	swap(stack_b);
	ft_putstr_fd("sb\n", 1);
}

void	ss(t_stack **stack_a, t_stack **stack_b)
{
	swap(stack_a);
	swap(stack_b);
	ft_putstr_fd("ss\n", 1);
}
