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
	if (((neg == 1 && number > INT_MAX) || (neg == -1 && - number < INT_MIN)))
			return (0);
	return (number * neg);
}
