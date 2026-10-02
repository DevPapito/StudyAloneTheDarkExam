#ifndef LIST_H
# define LIST_H

# include <stdlib.h>

typedef struct s_list
{
	long data;
	struct s_list	*next;
}	t_list;

t_list	*node_init(void);
void	push_front(t_list **list, t_list *node);
void	pop_front(t_list **list);
void	destroy_list(t_list **list);
int	list_len(t_list **list);

#endif
