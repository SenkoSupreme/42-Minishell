#include "../shell.h"

void	list_destroy(t_node **list)
{
	t_node *n1;
	t_node *n2;
	
	if(*list == NULL)
		return ;
	n1 = *list;
	while (n1 != NULL)
	{
		n2 = n1->next;
		safe_free((void **)&n1);
		n1 = n2;
	}
}

void	list_delete(t_node **list)
{
	t_node	*curr;
	t_node	*next;

	curr = *list;
	while (curr != NULL)
	{
		next = curr->next;
		safe_free((void **)&curr);
		curr = next;
	}
	*list = NULL;
}