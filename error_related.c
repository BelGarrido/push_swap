//#include "push_swap.h"
#include <stdio.h>
#include "libft/libft.h"
#include "push_swap.h"

/* char **arg_clean(int argc, char **argv)
{
	char **result;
	int i;

	result = malloc(sizeof(char *) * argc); // +1 opcional si quieres NULL-terminated
	i = 0;
	while ((argc - 1) > i)
	{
		result[i] = argv[i + 1];
		i++;
	}
	return (result);
} */

char **arg_prep(int argc, char **argv)
{
	char **result;
	int i;
	if (argc < 2 || ft_strlen(argv[1]) == 0) /*no segura de que funcione*/
	{
		ft_putstr_fd("Empty string\n", 1);
		exit(1);
	}
	if (argc == 2)
		result = ft_split(argv[1], ' ');
	else
	{
		result = malloc(sizeof(char *) * argc); // +1 opcional si quieres NULL-terminated
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

int valid_argument(char *arg)
{
	int i;

	i = 0;
	if (arg[i] == '\0')
		return (0);
	while(arg[i] != '\0')
	{
		if (arg[i] == '-' || arg[i] == '+')
			i++;
		if (ft_isdigit(arg[i]))
			i++;
		else
			return 0;
	}
	return 1;
}

int	repeat_num(int num, t_stack **stack)
{
	t_stack *tmp;

	tmp = *stack;
	while (tmp != NULL)
	{
		if(tmp->value == num)
			return (1);
		tmp = tmp->next;
	}
	return (0);
}

/* void	error_empty()
{
	ft_putstr_fd("Empty string\n", 1);
	exit(1);
} */
void	error_manage(char **input, int type, t_stack **stack, int argc) /*t_stack **stack,*/
{
	if (type == 1)
	{
		ft_putstr_fd("Incorrect argument type\n", 1);
	}
	else if(type == 2)
	{
		ft_putstr_fd("Argument repeated\n", 1);
	}
	else if (type == 3)
	{
		ft_putstr_fd("Incorrect argument type\n", 1);
	}
	//free_stack(stack); NECESARIO?
	free_input(input, argc);
	free_stack(*stack);
	exit(1);
}

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;
	t_stack *del;

	if (stack == NULL)
		return;
	tmp = stack;
	del = NULL;
	while (tmp != NULL)
	{
		del = tmp;
		tmp = tmp->next;
		free(del);
	}
	//free(stack);
}
void	free_input(char **input, int argc)
{
	int i;

	i = 0;
	if(argc == 2)
	{
		//printf("free_input\n");
		while(input[i] != NULL)
		{
			////printf("free_input_X\n");
			free(input[i]);
			i++;
		}
	}
	free(input);
}

/* void	free_stack(t_stack *stack)
{
	if (stack == NULL)
		return;

	free_stack(stack->next);
	free(stack);
} */
