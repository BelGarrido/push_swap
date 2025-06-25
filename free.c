/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagarri@student.42malaga.com <anagarri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:43:59 by anagarri@st       #+#    #+#             */
/*   Updated: 2025/06/25 11:45:45 by anagarri@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*del;

	if (stack == NULL)
		return ;
	tmp = stack;
	del = NULL;
	while (tmp != NULL)
	{
		del = tmp;
		tmp = tmp->next;
		free(del);
	}
}

void	free_input(char **input, int argc)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (input[i] != NULL)
		{
			free(input[i]);
			i++;
		}
	}
	free(input);
}
