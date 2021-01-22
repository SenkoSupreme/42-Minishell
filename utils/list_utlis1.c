#include "../shell.h"

void	add_back(t_node **list, void *dt)
{
	t_node *new;

	new = *list;
	while(new)
		new = new->next;
	new = new_node(dt);
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
// void			free_content(void *new_data)
// {
// 	if ((char *)new_data)
// 	{
// 		free((char *)new_data);
// 		new_data = 0;
// 	}
// }

// t_node	*new_new_node(void *new_data)
// {
// 	t_node	*head;

// 	head = (t_node*)malloc(sizeof(t_node));
// 	if (head == 0)
// 	{
// 		return (NULL);
// 	}
// 	head->data = new_data;
// 	head->next = NULL;
// 	return (head);
// }

void free_node(t_node *lst, void (*del)(void*))
{
	if (lst && del)
	{
		(*del)(lst->data);
		free(lst);
	}
}

void add_at_the_end(t_node **alst, t_node *l_new)
{
	t_node	*last;

	if (!l_new)
		return ;
	last = *alst;
	l_new->next = NULL;
	if ((*alst) == NULL)
		(*alst) = l_new;
	else
	{
		while (last->next != NULL)
			last = last->next;
		last->next = l_new;
	}
}