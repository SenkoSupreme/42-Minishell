/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrija <mbrija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/19 17:44:43 by mbrija            #+#    #+#             */
/*   Updated: 2021/03/08 16:05:40 by mbrija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "../minishell.h"

void	ft_lstiter(t_list *lst, void (*f)(void*, void*), void *para)
{
	t_list	*element;

	element = lst;
	if (element)
	{
		while (element != NULL)
		{
			f(element->content, para);
			if (g_minishell.ret == 1)
				break;
			element = element->next;
		}
	}
}
