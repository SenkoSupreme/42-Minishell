/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_u2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrija <mbrija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 15:26:53 by mbrija            #+#    #+#             */
/*   Updated: 2021/03/05 14:25:35 by mbrija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char			*replace_env(char *str, char *res, int *i, int len)
{
	char	*tmp;
	char	*var;

	tmp = ft_substr(str, *i, len);
	(*i) += len;
	var = get_var(tmp);
	free(tmp);
	tmp = res;
	res = ft_strjoin(res, var);
	free(var);
	free(tmp);
	return (res);
}

char			*ft_append(char *str, char *res, int *i)
{
	res = ft_strappend(res, str[*i]);
	(*i)++;
	return (res);
}

int				custom_len(char *s)
{
	int len;

	len = 0;
	while (s[len] && s[len] != '=')
		len++;
	return (len);
}
