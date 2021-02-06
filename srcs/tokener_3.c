#include "../shell.h"

t_node	*split_redirect(t_env *env)
{
	t_node	*token;
	char	*line;
	size_t	j;

	line = env->pipetokens->data;
	j = env->input->i + 1;
	//printf("#########");
	while (j < env->input->len)
	{
		if(line[j] == '>' || line[j] == '<')
		{
			j++;
			break;
		}
		j++;
	}
	token = new_node(ft_substr(line, env->input->i, j));
	env->input->i = j;
	return (token);
}