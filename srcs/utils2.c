#include "../minishell.h"

t_list	*array_to_list(char **arr)
{
	t_list *head;
	int i;

	i = 0;
	head = NULL;
	while (arr[i])
	{
		ft_lstadd_back(&head, ft_lstnew(ft_strdup(arr[i])));
		i++;
	}
	return (head);
}

int		env_len(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '=')
	{
		if (s[i] == '+' && s[i + 1] == '=')
			return (i);
		i++;
	}
	return i;
}

t_list	*list_chr(t_list *head, char *s)
{
	t_list	*cur;
	int		len;

	if (!s)
		return (NULL);
	len = env_len(s);
	cur = head;
	while (cur)
	{
		if(!ft_strncmp(s, cur->content, len) 
		&& (*(((char *)cur->content) + len) == '=' 
		|| *(((char *)cur->content) + len) == '\0'))
		return (cur);
		cur = cur->next;
	}
	return (NULL);
}

int		end_pipe()
{
	int i;

	i = ft_strlen(g_minishell.input) - 1;
	while (i >= 0 && g_minishell.input[i] == ' ')
		i--;
	if (i >= 0 && is_on_char(g_minishell.input, i,  "|"))
		return (1);
	return (0);
}

int		is_command(char *s)
{
	if (senko_equal_str(s, "echo"))
		return (1);
	if (senko_equal_str(s, "cd"))
		return (2);
	if (senko_equal_str(s, "pwd"))
		return (3);
	if (senko_equal_str(s, "export"))
		return (4);
	if (senko_equal_str(s, "unset"))
		return (5);
	if (senko_equal_str(s, "env"))
		return (6);
	if (senko_equal_str(s, "exit"))
		return (7);
	return (0);
}