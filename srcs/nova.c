#include "../shell.h"

t_input		*initiate(int ac, char **av, char **ev)
{
	t_input *input;

	(void)ac;
	(void)av;
	(void)ev;

	//env = (t_env*)malloc(sizeof(t_env));
	input = (t_input*)malloc(sizeof(t_input));
	return (input);
}

t_token		*new_token(void *tok)
{
	t_token	*token;
	
	token = (t_token*)malloc(sizeof(t_token));
	if(tok)
		token->tok = tok;
	return (token);
}

t_node	*new_node(void *data)
{
	t_node *node;

	node = (t_node*)malloc(sizeof(t_node));
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

	arr = (t_array*)malloc(sizeof(t_array));
	arr->array = (int*)malloc(sizeof(int) * size);
	arr->size = size;
	i = 0;
	while (i < size)
		arr->array[i++] = -1;
	return arr;
}