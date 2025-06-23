#include "push_swap.h"

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

t_stack	*get_last(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst -> next != NULL)
		lst = lst -> next;
	return (lst);
}
t_stack	*get_previous_last(t_stack *lst)
{
	if (lst == NULL)
		return (NULL);

	while (lst->next->next != NULL)
	{		
		lst = lst -> next;
	}
	return (lst);
}
void	ft_lstaddback(t_stack **lst, t_stack *new)
{
	t_stack	*last_node;

	last_node = *lst;
	if ((*lst) && new)
	{
		while (last_node -> next != NULL)
			last_node = last_node -> next;
		last_node -> next = new;
		//new->prev = last_node; DECIDIR
	}
	else if (!(*lst) && new)
	{
		*lst = new;
		new->prev = NULL;
	}
}
long	ft_atol(char *s)
{
	int	i;
	int	neg;
	long	number;

	i = 0;
	neg = 1;
	number = 0;
	while ((s[i] >= 9 && s[i] <= 13) || s[i] == 32)
		i++;
	if (s [i] == '+' || s[i] == '-')
	{
		if (s[i] == '-')
			neg = -neg;
		i++;
	}
	while (s[i] >= '0' && s[i] <= '9')
	{
		number = number * 10 + s[i] - '0';
		i++;
	}
	return (number * neg);
}

/* int	get_mediana(t_stack *stack)
{
	int size;
	int n;

	size = get_size(stack);
	if(size == 0)
		return (0);
	if (size % 2 != 0)
	{
		n = (size + 1) / 2;
	}
	else
	{
		n = size / 2;
	}
	return (n);
} */

void	above_median(t_stack **stack)
{
	int med_index;
	t_stack *tmp;
	
	tmp = *stack;
	med_index = med_position(*stack);
	while(tmp != NULL)
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
	t_stack *tmp;
	
	tmp = *stack;
	while(tmp != NULL)
	{
		if (tmp->below_med == 0 && (size - tmp->index) < 3)
			tmp->is_big = 1;
		else
			tmp->is_big = 0;
		tmp = tmp->next;
	}
}

int	ft_abs(int num)
{
	if (num < 0)
		return (num * -1);
	else
		return (num);
}

int	max_value(int one, int two)
{
	if (one > two)
		return (one);
	else 
		return(two);
}