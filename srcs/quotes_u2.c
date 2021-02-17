#include "../minishell.h"

void	split_args(t_list *lst)
{
	char	*str;
	int		i;
	int		len;
	t_list	*tmp;

	i = 0;
	tmp = lst;
	str = tmp->content;
	while (*str == ' ')
		str++;
	while ((len = word_len(str + i, " ", 0)))
	{
		if (i == 0)
			tmp->content = ft_substr(str, i , len);
		else
		{
			lst_add(tmp, ft_lstnew(ft_substr(str, i, len)));
			tmp = tmp->next;
		}
		i += len;
		while (str[i] && str[i] == ' ')
			i++;
	}
}