#include "push_swap.h"
/* 
void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		write (fd, &s[i], 1);
		i++;
	}
} */

void	push(t_stack **s_give, t_stack **s_receive)
{
	t_stack *tmp_a;
	
	if (!s_give || !*s_give)
		return ;
	tmp_a = *s_give;
	*s_give = (*s_give)->next;
	if(*s_receive == NULL)
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

/* void print_nodes(t_stack *head)
{
    t_stack *current = head;
    printf("Stack:\n");
    while (current != NULL)
    {
        printf("  [Val: %d] [In: %d] [Ps: %d]\n", current->value, current->index, current->position);
        current = current->next;
    }
}

int main(void)
{
	t_stack *list;
	t_stack *uno;
	t_stack *dos;
	t_stack *b;

	list = malloc(sizeof(t_stack)); 
	uno = malloc(sizeof(t_stack));
	dos = malloc(sizeof(t_stack));
	b = malloc(sizeof(t_stack));
	b = NULL;
	//b->index = 8;
	//b->next = NULL;
	(list)->index = 1;
	uno->index = 2;
	dos->index = 3;
	(list)->next = uno;
	uno->next = dos;
	dos->next = NULL;

	ft_putstr_fd("before PB\n", 1);
	print_nodes(list);
	print_nodes(b);
	pb(&list, &b);
	ft_putstr_fd("after PB\n", 1);
	print_nodes(list);
	print_nodes(b);
} */

