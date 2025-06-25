/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_related2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagarri@student.42malaga.com <anagarri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 12:00:55 by anagarri@st       #+#    #+#             */
/*   Updated: 2025/06/25 12:07:39 by anagarri@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	set_position(t_stack *stack)
{
	t_stack	*tmp;
	int		i;

	i = 0;
	tmp = stack;
	while (tmp != NULL)
	{
		i++;
		tmp->position = i;
		tmp = tmp->next;
	}
}

void	init_index(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp != NULL)
	{
		tmp->index = 1;
		tmp = tmp->next;
	}
}

void	set_index(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*current;

	init_index(stack);
	tmp = stack;
	current = stack;
	while (current != NULL)
	{
		while (tmp != NULL)
		{
			if (current->value > tmp->value)
				current->index++;
			tmp = tmp->next;
		}
		tmp = stack;
		current = current->next;
	}
}

void	init_target_pos(t_stack *stack)
{
	t_stack	*tmp;

	tmp = stack;
	while (tmp != NULL)
	{
		tmp->target_pos = -1;
		tmp = tmp->next;
	}
}
