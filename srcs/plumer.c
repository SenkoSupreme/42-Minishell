#include "../shell.h"

void	safe_free(void **ptr)
{
	if(*ptr == NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}

void free_node(t_node *lst, void (*del)(void*))
{
	if (lst && del)
	{
		(*del)(lst->data);
		free(lst);
	}
}