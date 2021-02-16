#include "../minishell.h"

char		**list_to_array(t_list *lst)
{
	char	*av;
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