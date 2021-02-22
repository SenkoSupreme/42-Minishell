#include "../minishell.h"

char	*get_from_env(char *s)
{
	t_list *cur;

	cur = g_env.env_h;
	while (cur)
	{
		if (ft_strncmp(cur->content, s, ft_strlen(s)))
			return (cur->content + ft_strlen(s) + 1);
		cur = cur->next;
	}
	return (NULL);
}