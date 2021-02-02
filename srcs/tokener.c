#include "../shell.h"

t_node	*quotenise(t_env *env)
{
	t_node	*token;
	char 	*line;

	line = env->pipetokens->data;
	if(line[env->input->i] == '\'')
		token = single_quotenise(env);
	else
		token = double_quotenise(env);
	return (token);
}

t_node	*single_quotenise(t_env *env)
{
	t_node	*token;
	char	*line;
	size_t	j;

	line = env->pipetokens->data;
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
	token = new_node(ft_substr(line, env->input->i + 1, --j));
	env->input->i = j;
	return (token);
}

t_node	*double_quotenise(t_env *env)
{
	t_node	*token;
	char	*line;
	size_t	j;

	line = env->pipetokens->data;
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
	token = new_node(ft_substr(line, env->input->i + 1, --j));
	env->input->i = j;
	return (token);
}

t_token	*get_token(t_env *env, char c)
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
		else if (line[j] == c && line[j - 1] != '\\')
		{
			break;
		}
		j++;
	}
	token = new_token(senko_substr(line, env->input->i, j++, skp));
	env->input->i = j;
	return token;
}

int tokenise(t_env *env)
{
	t_token	*token;
	char 	*line;
	size_t	i;

	line = env->input->line;       
	env->input->len = ft_strlen(line);
	i = 0;
	while (i < env->input->len)
	{
		if(line[i] != ';')
		{
			env->input->i = i;
			token = get_token(env, ';');
			add_at_the_end(&env->semitokens, (void*)token);
			i = env->input->i;
		}
		else
			i++;
	}
		while(env->semitokens)
		{
			env->semitokens->len = ft_strlen(env->semitokens->data);
			char *tok = env->semitokens->data; 
			t_ptoken *ptok;
			i = 0;
			while (i < env->semitokens->len)
			{
				if (tok[i] != '|')
				{
					env->input->i = i;
					ptok = split_pipe(env);
					add_at_the_pipe(&env->pipetokens, (void*)ptok);
					i = env->input->i;
				}
				else
				i++;
			}
			
			printf(" senmicolToken :[%s]| %zu\n", env->semitokens->data, env->semitokens->len);
			env->semitokens = env->semitokens->next;
		}

		while(env->pipetokens)
		{
			env->pipetokens->len = ft_strlen(env->pipetokens->data);
			char *tok = env->pipetokens->data; 
			t_node *ntok;
			i = 0;
			while (i < env->pipetokens->len)
			{
				if (tok[i] != ' ')
				{
					env->input->i = i;
		 			if (tok[i] == '"' /*|| tok[i] == '\''*/)
						ntok = quotenise(env);
					else		
						ntok = split_node(env, ' ');
					add_at_the_node(&env->simpletokens, (void*)ntok);
					i = env->input->i;
				}
				else
				i++;
			}

			printf(" pipeToken :[%s]\n", env->pipetokens->data);
			env->pipetokens = env->pipetokens->next;
		}
		while(env->simpletokens)
		{
			check_command(env->simpletokens);
			printf(" simpleToken :[%s] | is com [%d]\n", env->simpletokens->data, env->simpletokens->is_com);
			env->simpletokens = env->simpletokens->next;
		}
	return 0;
}
			// if (line[i] == '|' )
			// {
			// 	token = get_token(env, '|');
			// 	if (!env->pipetokens)
			// 		env->pipetokens = new_pipenode((void*)token);
			// 	else
			// 		add_at_the_pipe(&env->pipetokens, (void*)token);
			// }
			// /*else if(line[i] == ' ')
			// {
			//  	if (line[i] == '"' || line[i] == '\'')
			// 	token = quotenise(env);
			// 	else
			// 	token = get_token(env, ' ');
			// 	if (!env->tokens->pipeline->node)
			// 		env->tokens->pipeline->node = new_node((void *)token);
			// 	else
			// 		add_at_the_node(&env->tokens->pipeline->node, new_node((void *)token));
			// }*/
			// else
			// // if (line[i] == '"' || line[i] == '\'')
			// 	token = quotenise(env);
			// else if (line[i] == '<' || line[i] == '>')
			// 	token = split_redirections(env);
			// else if (line[i] == '|' )
			// {
			// 	token = split_pipe(env);
			// }
			// else if (line[i] == ';' )
			// 	token = split_scolomn(env);
			//else