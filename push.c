/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagarri@student.42malaga.com <anagarri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/24 10:15:23 by anagarri@st       #+#    #+#             */
/*   Updated: 2025/06/24 10:15:57 by anagarri@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push(t_stack **s_give, t_stack **s_receive)
{
	t_stack	*tmp_a;

	if (!s_give || !*s_give)
		return ;
	tmp_a = *s_give;
	*s_give = (*s_give)->next;
	if (*s_receive == NULL)
	{
		*s_receive = tmp_a;
		tmp_a->next = NULL;
	}
	else
	{
		tmp_a->next = *s_receive;
		*s_receive = tmp_a;
	}
}

void	pb(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_a, stack_b);
	ft_putstr_fd("pb\n", 1);
}

void	pa(t_stack **stack_a, t_stack **stack_b)
{
	push(stack_b, stack_a);
	ft_putstr_fd("pa\n", 1);
}
