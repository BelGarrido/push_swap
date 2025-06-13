#include "push_swap.h"

/* 
void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*tmp;

	if (*lst != NULL)
	{
		while ((*lst)->next != NULL)
		{
			tmp = (*lst)->next;
			ft_lstdelone(*lst, del);
			*lst = tmp;
		}
		ft_lstdelone(*lst, del);
		*lst = NULL;
	}
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst != NULL)
	{
		del(lst -> number);
		free(lst);
	}
}

void ft_del(void *content)
{
	free(content);
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	if (lst)
	{
		while (lst -> next != NULL)
		{
			f(lst -> number);
			lst = lst -> next;
		}
		f(lst -> number);
	}
} */

/* t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_list;
	t_list	*new_node;
	void	*content_transformed;

	new_list = NULL;
	new_node = NULL;
	if (lst == NULL)
		return (NULL);
	while (lst != NULL)
	{
		content_transformed = f(lst -> number);
		new_node = ft_lstnew (content_transformed);
		if (new_node == NULL)
		{
			ft_lstclear(&new_node, del);
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		lst = lst ->next;
	}
	return (new_list);
} */
/* t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	new -> number = content;
	new -> next = NULL;
	return (new);
} */

/* void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (new && lst)
	{
		(*new).next = *lst;
		*lst = &(*new);
	}
} */
