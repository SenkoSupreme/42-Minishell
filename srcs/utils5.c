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