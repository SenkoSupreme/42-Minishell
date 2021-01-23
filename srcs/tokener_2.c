#include "../shell.h"

t_token	*split_pipe(t_env *env)
{
	t_token	*token;
	char	*line;
	size_t	j;

	line = env->input->line;
	j = env->input->i + 1;
	while (j < env->input->len)
	{
		if(line[j] == '|' && line[j - 1] != '\\')
			break;
		j++;
	}
	token = new_token(ft_substr(line, env->input->i, j));
	env->input->i = j;
	token->is_pipe++; //THIS DOESN'T COUNT WHY ??
	return (token);
}

t_token	*split_scolomn(t_env *env)
{
	t_token	*token;
	char	*line;
	size_t	j;

	line = env->input->line;
	j = env->input->i + 1;
	while (j < env->input->len)
	{
		if(line[j] == ';' && line[j - 1] != '\\')
			break;
		j++;
	}
	token = new_token(ft_substr(line, env->input->i, j));
	env->input->i = j;
	return (token);
}

t_token	*split_redirections(t_env *env)
{
	t_token	*token;
	char	*line;
	size_t	j;

	line = env->input->line;
	j = env->input->i + 1;
	while (j < env->input->len)
	{
		if(line[j] == '>' || line[j] == '<')
			break;
		j++;
	}
	token = new_token(ft_substr(line, env->input->i, j));
	env->input->i = j;
	return (token);
}