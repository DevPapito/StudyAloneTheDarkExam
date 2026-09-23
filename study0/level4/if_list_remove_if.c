#include <stdlib.h>

void	if_list_remove_if(t_list **begin_refer, void *data_ref, int (*cmp)(int, int))
{
	t_list *node;

	node = *begin_refer;
	if ((*cmp)(node->data, data_ref) == 0)
	{
		*begin_refer = node->next;
		free(node);
		if_list_remove_if(&begin_refer, data_ref, cmp);
	}
	else
		if_list_remove_if(&node->next, data_red, cmp);
}
