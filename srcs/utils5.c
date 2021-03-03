/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrija <mbrija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 15:29:49 by mbrija            #+#    #+#             */
/*   Updated: 2021/03/03 19:03:11 by mbrija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char			**list_to_array(t_list *lst)
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
	return (av);
}

char			*last_com_return(char *res, int *i)
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

char			*ft_append(char *str, char *res, int *i)
{
	res = ft_strappend(res, str[*i]);
	(*i)++;
	return (res);
}

int		custom_len(char *s)
{
	int len;

	len = 0;
	while (s[len] && s[len] != '=')
		len++;
	return (len);
}

void			ft_lstclear_one_if(t_list **list, void *ref,
		int (*f)(), void (*del)(void*))
{
	t_list	*next;
	t_list	*prev;
	int		n;

	if (!list || !*list || !f || !del)
		return ;
	n = custom_len((*list)->content);
	if (!f((*list)->content, ref, n) && (prev = *list))
	{
		*list = prev->next;
		ft_lstdelone(prev, del);
		return ;
	}
	prev = *list;
	next = (*list)->next;
	while (prev)
	{
		n = custom_len(next->content);
		if (next && !f(next->content, ref, n) && (prev->next = next->next))
		{
			ft_lstdelone(next, del);
			next = prev->next;
			return ;
		}
		prev = prev->next;
		if (next->next)
			next = next->next;
	}
}
