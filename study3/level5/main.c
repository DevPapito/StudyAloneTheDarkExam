#include "list.h"
#include <stdlib.h>
#include <stdio.h>

int main(void)
{
	t_list head;
	t_list middle;
	t_list tail;


	tail.data = 50;
	head.data = 10;
	middle.data = 0;

	head.next = &middle;
	middle.next = &tail;
	tail.next = &head;

	//tail.next = NULL; Nao circular
	int boolean = cycle_detector(&head);
	printf("%d\n", boolean);
}
