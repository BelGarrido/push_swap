/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagarri@student.42malaga.com <anagarri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 09:53:26 by anagarri@st       #+#    #+#             */
/*   Updated: 2025/06/24 09:59:48 by anagarri@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_sorted(t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp != NULL && tmp->next != NULL)
	{
		if (tmp->index > tmp->next->index)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	push_swap(t_stack **stack_a, t_stack **stack_b, int stack_a_size)
{
	if (stack_a_size == 2 && !is_sorted(stack_a))
		sa(stack_a);
	else if (stack_a_size == 3 && !is_sorted(stack_a))
		sort_three(stack_a);
	else if (stack_a_size > 3 && !is_sorted(stack_a))
	{
		sort_much(stack_a, stack_b, stack_a_size);
	}
	else
		return ;
}

int	main(int argc, char *argv[])
{
	t_stack	*stack_a;
	t_stack	*stack_b;
	int		stack_size;
	char	**input;

	input = arg_prep(argc, argv);
	stack_a = NULL;
	fill_stack(&stack_a, input, argc);
	stack_b = NULL;
	stack_size = get_size(stack_a);
	set_index(stack_a);
	push_swap(&stack_a, &stack_b, stack_size);
	free_input(input, argc);
	free_stack(stack_a);
	free(stack_b);
	return (0);
}
