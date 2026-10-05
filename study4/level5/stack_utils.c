#include "stack.h"

t_node	*node_init(void)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	if (!node)
		return (NULL);
	node->data = -1L;
	node->next = NULL;
	return (node);
}

void	push_front(t_node **stack, t_node *node)
{
	node->next = *stack;
	*stack = node;
}

void	pop_front(t_node **stack)
{
	t_node *save;
	t_node *lst = *stack;

	save = lst->next;
	free(lst);
	*stack = save;
}

void	destroy_stack(t_node **stack)
{
	t_node *save;
	t_node *lst = *stack;

	while (lst)
	{
		save = lst->next;
		free(lst);
		lst = save;
	}
	save = NULL;
}
