#include "list.h"

t_list	*node_init(void)
{
	t_list *node;

	node = malloc(sizeof(t_list));
	if (!node)
		return (NULL);
	node->data = -1L;
	node->next = NULL;
	return (node);
}

void	push_front(t_list **list, t_list *node)
{
	node->next = *list;
	*list = node;
}

void	pop_front(t_list **list)
{
	t_list *save;
	t_list *lst = *list;

	save = lst->next;
	free(lst);
	*list = save;
}

void	destroy_list(t_list **list)
{
	t_list *lst = *list;
	t_list *save;

	while (lst)
	{
		save = lst->next;
		free(lst);
		lst = save;
	}
}

int	list_len(t_list **list)
{
	t_list *lst = *list;
	int count = 0;

	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
