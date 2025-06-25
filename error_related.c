/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_related.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anagarri@student.42malaga.com <anagarri    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 11:28:23 by anagarri@st       #+#    #+#             */
/*   Updated: 2025/06/25 11:46:14 by anagarri@st      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	**arg_prep(int argc, char **argv)
{
	char	**result;
	int		i;

	if (argc < 2 || ft_strlen(argv[1]) == 0)
	{
		ft_putstr_fd("Empty string\n", 1);
		exit(1);
	}
	if (argc == 2)
		result = ft_split(argv[1], ' ');
	else
	{
		result = malloc(sizeof(char *) * argc);
		i = 0;
		while ((argc - 1) > i)
		{
			result[i] = argv[i + 1];
			i++;
		}
		result[i] = NULL;
	}
	return (result);
}

int	valid_argument(char *arg)
{
	int	i;

	i = 0;
	if (arg[i] == '\0')
		return (0);
	while (arg[i] != '\0')
	{
		if (arg[i] == '-' || arg[i] == '+')
			i++;
		if (ft_isdigit(arg[i]))
			i++;
		else
			return (0);
	}
	return (1);
}

int	repeat_num(int num, t_stack **stack)
{
	t_stack	*tmp;

	tmp = *stack;
	while (tmp != NULL)
	{
		if (tmp->value == num)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

void	error_manage(char **input, int type, t_stack **stack, int argc)
{
	if (type == 1)
	{
		ft_putstr_fd("Incorrect argument type\n", 1);
	}
	else if (type == 2)
	{
		ft_putstr_fd("Argument repeated\n", 1);
	}
	free_input(input, argc);
	free_stack(*stack);
	exit(1);
}
