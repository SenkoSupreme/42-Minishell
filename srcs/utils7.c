/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrija <mbrija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/07 15:05:04 by sel-fadi          #+#    #+#             */
/*   Updated: 2021/03/12 17:58:06 by mbrija           ###   ########.fr       */
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

void		execute_hack(int ret, char **argv, t_command *com, int *n)
{
	if ((ret = is_command(argv[0])))
		builtin_coms(com, argv, ret);
	else if (!is_command(argv[0]))
	{
		free(argv);
		system_coms(com, ret, n);
	}
}

t_command	*init_command(int in, int out, int pipe)
{
	t_command *com;

	com = malloc(sizeof(t_command));
	com->argv = NULL;
	com->in_red = in;
	com->out_red = out;
	com->red_files = NULL;
	com->pipe[0] = -1;
	com->pipe[1] = pipe;
	return (com);
}
