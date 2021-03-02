/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env_u2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrija <mbrija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 15:26:53 by mbrija            #+#    #+#             */
/*   Updated: 2021/03/02 15:26:54 by mbrija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

char	*replace_env(char *str, char *res, int *i, int len)
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

