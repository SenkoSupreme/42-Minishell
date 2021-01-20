#include "../shell.h"

t_env		*initiate(int ac, char **av, char **ev)
{
	t_env *env;

	(void)ac;
	(void)av;
	(void)ev;

	env = malloc(sizeof(*(env)));
	env->input = malloc(sizeof(*(env->input)));
	return (env);
}

t_token		*new_token(void *tok)
{
	t_token	*token;
	
	token = malloc(sizeof(*(token)));
	if(tok)
		token->tok = tok;
	return (token);
}

t_node	*new_node(void *data)
{
	t_node *node;

	node = malloc(sizeof(*(node)));
	if (!node)
		return NULL;
	node->data = data;
	node->next = NULL;
	return node;
}

t_array	*new_array(int size)
{
	t_array *arr;
	int		i;

	arr = malloc(sizeof(*(arr)));
	arr->array = malloc(sizeof(*(arr->array)) * size);
	arr->size = size;
	i = 0;
	while (i < size)
		arr->array[i++] = -1;
	return arr;
}