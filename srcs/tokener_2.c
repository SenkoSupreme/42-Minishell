#include "../shell.h"

t_ptoken	*split_pipe(t_env *env)
{
	t_ptoken	*token;
	char	*line;
	size_t	j;

	line = env->semitokens->data;
	j = env->input->i + 1;
	while (j < env->input->len)
	{
		if(line[j] == '|' && line[j - 1] != '\\')
			break;
		j++;
	}
	token = new_pipenode(ft_substr(line, env->input->i, j));
	env->input->i = j;
	return (token);
}

t_node	*split_node(t_env *env)
{
	t_node	*token;
	char	*line;
	size_t	j;

	line = env->pipetokens->data;
	j = env->input->i + 1;
	while (j < env->input->len)
	{
		if(line[j] == ' ')
			break;
		j++;
	}
	token = new_node(ft_substr(line, env->input->i, j));
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

void	check_command(t_node *node)
{
	char *command;
	char *built_ins[] = {"echo", "ls", "pwd", "cd"};
	int i;

	i = 0;
	while(node)
	{
		command = node->data;
		while(command[i++])
			if (ft_strcmp(command, built_ins[i]) != 0)
				node->is_com = 0;
			else
			{
				node->is_com = 1;
				break;
			}
	}
}