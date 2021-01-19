#include "../shell.h"

int tokenise(t_env *env)
{
	t_token *token;
	char 	*line;
	int		i = 0;
	int		j = 0;

	line = env->input->line;
	env->input->len = ft_strlen(line);
	while (i < env->input->len)
	{
		if(line[i] != ' ')
		{
			env->input->i = i;
			if (line[i] == '"' || line[i] == '\'')
				token = quotenise(env);
			else
				token = get_token(env);
			i = env->input->i;
			printf("Token :[%s]\n", token->tok);
			

		}
	}
	
}

t_token	*quotenise(t_env *env)
{
	t_token	*token;

	if(env->input->line[env->input->i] == '\'')
		token = single_quotenise(env);
	else
		token = double_quotenise(env);
	if (token)
		token->is_quote = 1;
	return (token);
}

t_token	*sigle_quotenise(t_env *env)
{
	t_token	*token;
	char	*line;
	size_t	j;

	line = env->input->line;
	j = env->input->i + 1;
	while (j < env->input->len)
	{
		if(line[j] == '\'' && line[j - 1] != '\\')
		{
			j++;
			break;
		}
		j++;
	}
	token = new_token(ft_substr(line, env->input->i, j));
	env->input->i = j;
	return (token);
}

t_token	*double_quotenise(t_env *env)
{
	t_token	*token;
	char	*line;
	size_t	j;

	line = env->input->line;
	j = env->input->i + 1;
	while (j < env->input->len)
	{
		if(line[j] == '"' && line[j - 1] != '\\')
		{
			j++;
			break;
		}
		j++;
	}
	token = new_token(ft_substr(line, env->input->i, j));
	env->input->i = j;
	return (token);

}