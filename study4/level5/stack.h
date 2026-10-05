#ifndef STACK_H
# define STACK_H

# include <stdlib.h>

typedef struct s_node
{
	long	data;
	struct s_node	*next;
}	t_node;

t_node	*node_init(void);
void	push_front(t_node **stack, t_node *node);
void	pop_front(t_node **stack);
void	destroy_stack(t_node **stack);

#endif
