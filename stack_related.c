/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_related.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagarri@student.42malaga.com <anagarri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:58:07 by anagarri@st       #+#    #+#             */
/*   Updated: 2025/06/25 12:01:41 by anagarri@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	fill_stack(t_stack **stack_a, char **input, int argc)
{
	long	num;
	int		i;

	i = 0;
	while (input[i] != NULL)
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
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
		return ;
	new->value = num;
	new->next = NULL;
	ft_lstaddback(stack_a, new);
}

void	send_to_b(t_stack **stack_a, t_stack **stack_b, int size_b)
{
	int	dinamic_size;
	int	i;

	i = 0;
	above_median(stack_a);
	is_big(stack_a, size_b);
	while (i < size_b)
	{
		if ((*stack_a)->below_med == 1)
			pb(stack_a, stack_b);
		else
			ra(stack_a);
		i++;
	}
	dinamic_size = (get_size(*stack_a));
	while (dinamic_size > 3)
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
