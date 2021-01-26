#include "../shell.h"

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

t_token	*single_quotenise(t_env *env)
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
	token = new_token(ft_substr(line, env->input->i, j++));
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
	token = new_token(ft_substr(line, env->input->i, j++));
	env->input->i = j;
	return (token);
}

t_token	*get_token(t_env *env)
{
	t_token *token;
	t_array	*skp;
	char	*line;
	size_t	j;
	int		k;

	skp = new_array(256); //256 ARRAY SIZE
	k = 0;
	j = env->input->i + 1;
	line = env->input->line;
	while(j < env->input->len)
	{
		if(line[j] =='\\')
			skp->array[k++]	= j;
		else if (line[j] == ' ' && line[j - 1] != '\\')
			break;
		
		j++;
	}
	token = new_token(senko_substr(line, env->input->i, j++, skp));
	env->input->i = j;
	return token;
}

int tokenise(t_env *env)
{
	t_token *token;
	char 	*line;
	size_t	i;

	line = env->input->line;
	printf("line :[%s]\n", line);
	env->input->len = ft_strlen(line);
	i = 0;
	while (i < env->input->len)
	{
		if(line[i] != ' ' || line[i] != '\t')
		{
			env->input->i = i;
			if (line[i] == '"' || line[i] == '\'')
				token = quotenise(env);
			else if (line[i] == '<' || line[i] == '>')
				token = split_redirections(env);
			else if (line[i] == '|' )
			{
				token = split_pipe(env);
				token->is_pipe++;
			}
			else if (line[i] == ';' )
				token = split_scolomn(env);
			else
				token = get_token(env);
			i = env->input->i;
			printf("Token :[%s]\n", token->tok);
			add_at_the_end(&env->tokens, (void*)token);
		}
		else
			i++;
	}
	printf("N pipes : [%d] \n", token->is_pipe);
	return 0;
}