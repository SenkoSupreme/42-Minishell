/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrija <mbrija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:05:04 by sel-fadi          #+#    #+#             */
/*   Updated: 2021/03/08 16:24:37 by mbrija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

void		loop_hack(t_list **prev, t_list **tmp)
{
	(*tmp)->content = quotes_conv((*tmp)->content);
	*prev = *tmp;
	*tmp = (*tmp)->next;
}

void		remove_hack(t_list **av, t_list **prev, t_list **tmp)
{
	if (*av == *tmp)
		*av = lst_remove(tmp, *tmp, free);
	else
		(*prev)->next = lst_remove(tmp, *tmp, free);
}

void		fork_error_hack(void)
{
	senko_print("SSHEL: ", "fork", ": ", strerror(errno));
	exit(128);
}
