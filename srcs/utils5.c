#include "../minishell.h"

char		**list_to_array(t_list *lst)
{
	char	**av;
	int		len;
	int		i;

	len = ft_lstsize(lst);
	av = malloc(sizeof(char *) * (len + 1));
	i = 0;
	while (i < len)
	{
		av[i] = lst->content;
		i++;
		lst = lst->next;
	}
	av[i] = NULL;
	return	(av);
}

char	*last_com_return(char *res, int *i)
{
	char *var;
	char *tmp;

	var = ft_itoa(g_minishell.ret);
	tmp = res;
	res = ft_strjoin(res, var);
	free(var);
	free(tmp);
	(*i) += 2;
	return (res);
}

char	*ft_append(char *str, char *res, int *i)
{
	res = ft_strappend(res, str[*i]);
	(*i)++;
	return (res);
}

int		custom_len(char *s)
{
	int len;

	len = 0;
	while(s[len] && s[len] != '=')
		len++;
	return (len);
}

void	delete_node(char *s)
{
	t_list *tmp;
	t_list *prev;

	tmp = g_env.env_h;
	while(tmp)
	{
		if (tmp != NULL && ft_strncmp(tmp->content, s, custom_len(tmp->content)))
		{
			prev = tmp;
			tmp = tmp->next;
		}
		if (tmp == NULL)
			break;
	}
	prev->next = tmp->next;
	ft_lstdelone(tmp, free);
}