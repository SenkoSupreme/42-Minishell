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
		{
			j++;
			break;
		}
		j++;
	}
	token = new_pipenode(ft_substr(line, env->input->i, j));
	env->input->i = j;
	return (token);
}

t_node	*split_node(t_env *env, char c)
{
	t_node	*token;
	char	*line;
	size_t	j;

	line = env->pipetokens->data;
	j = env->input->i + 1;
	while (j < env->input->len)
	{
		if(line[j] == c)
		{
			break;
		}
		j++;
	}
	token = new_node(ft_substr(line, env->input->i, j));
	env->input->i = j;
	return (token);
}


void	check_command(t_node *node)
{
	char *command;
	char *built_ins[7] = {"echo", "pwd", "cd", "export", "unset", "exit", "env"};
	int i;

	i = 0;
	command = node->data;

	while(i < 7)
	{
		if (ft_strcmp(command, built_ins[i]) != 0)
		{
			node->type = 0;
		}
		else
		{
			node->type = CMD;
			break;														
		}
		i++;
	}
	if (command[0] == '-')
		node->type = ARG;
	if(command[0] == '|')
		node->type = PIPE;
	if (command[0] == '<' || command[0] == '>')
		node->type = REDIR;
}

void	check_quote(t_node **node)
{
	char 	*command;
	int		com_len;
	int		i;

	command = (*node)->data;
	com_len = ft_strlen(command);
	i = 0;

	
	if (((command[0] == '"'  && command[com_len - 1] == '"')) 
	|| ((command[0] == '\'' ) && (command[com_len - 1]) == '\''))
	{
		command = ft_substr(command, 1, com_len - 1);
		(*node)->data = command;
		(*node)->type = QUOTE;
	}
}