/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagarri@student.42malaga.com <anagarri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:09:09 by anagarri@st       #+#    #+#             */
/*   Updated: 2025/06/25 12:15:02 by anagarri@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	above_median(t_stack **stack)
{
	int		med_index;
	t_stack	*tmp;

	tmp = *stack;
	med_index = med_position(*stack);
	while (tmp != NULL)
	{
		if (tmp->index <= med_index)
			tmp->below_med = 1;
		else
			tmp->below_med = 0;
		tmp = tmp->next;
	}
	tmp = *stack;
}

void	is_big(t_stack **stack, int size)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp != NULL)
	{
		if (tmp->below_med == 0 && (size - tmp->index) < 3)
			tmp->is_big = 1;
		else
			tmp->is_big = 0;
		tmp = tmp->next;
	}
}

int	med_position(t_stack *stack)
{
	int	med_pos;
	int	size;

	size = get_size(stack);
	if (size == 0)
		return (0);
	med_pos = 0;
	if (size % 2 == 0)
		med_pos = size / 2;
	else if (size % 2 != 0)
		med_pos = (size + 1) / 2;
	return (med_pos);
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

int	max_value(int one, int two)
{
	if (one > two)
		return (one);
	else
		return (two);
}
