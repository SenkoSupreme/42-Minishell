#include "../shell.h"

t_env		*initiate(int ac, char **av, char **ev)
{
	t_env *env;

	(void)ac;
	(void)av;
	(void)ev;

	env = malloc(sizeof(*env));
	env->input = malloc(sizeof(*(env->input)));
	return (env);
}

t_token		*new_token(void *tok)
{
	t_token	*token;
	
	token = malloc(sizeof(*token));
	if(tok)
		token->tok = tok;
	return (token);
}

