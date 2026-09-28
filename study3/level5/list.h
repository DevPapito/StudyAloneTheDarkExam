#ifndef LIST_H
# define LIST_H

typedef struct s_list
{
	int	data;
	struct s_list *next;
}	t_list;


int	cycle_detector(const t_list *list);

#endif
