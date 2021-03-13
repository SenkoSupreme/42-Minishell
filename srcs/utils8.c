/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils8.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrija <mbrija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/13 19:17:42 by mbrija            #+#    #+#             */
/*   Updated: 2021/03/13 19:17:46 by mbrija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int			export_hack(t_list *curr, char *argv, int len)
{
	if ((size_t)len == ft_strlen(argv))
	{
		while (curr)
		{
			if (!ft_strncmp(curr->content, argv, len))
				return (1);
			curr = curr->next;
		}
	}
	return (0);
}
