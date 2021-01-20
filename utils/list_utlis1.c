#include "../shell.h"

void	add_back(t_node **list, void *data)
{
	t_node *new;

	new = *list;
	while(new)
		new = new->next;
	new = new_node(data);
	if(!new)
		return ;
}

void	add_front(t_node **list, void *data)
{
	t_node *new;

	if(!*list)
		*list = new_node(data);
	else
	{
		new = new_node(data);
		if(!new)
			return ;
		new->next = *list;
		*list = new;
	}
}

void	iter_list(t_node **list, void(*fn)(void **))
{
	t_node *tmp;

	if(*list == NULL)
		return ;
	tmp = *list;
	while (tmp != NULL)
	{
		(fn)(&tmp->data);
		tmp = tmp->next;
	}
}

size_t	list_size(t_node *list)
{
	t_node	*tmp;
	size_t	i;

	if (list == NULL)
		return 0;
	tmp = list;
	i = 0;
	while(tmp != NULL)
	{
		printf("clear : [%s]\n", (char *)tmp->data);
		tmp = tmp->next;
		i++;
	}
	return i;
}

void	list_clear(t_node **list)
{
	void *(fn);
	fn = safe_free;
	iter_list(list, fn);
	//fn = destroy
	//iter_list(list, fn);
}
