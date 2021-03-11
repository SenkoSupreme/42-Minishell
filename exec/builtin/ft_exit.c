/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrija <mbrija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:08:21 by sel-fadi          #+#    #+#             */
/*   Updated: 2021/03/11 16:05:51 by mbrija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int		ft_exit(char **argv, t_command *com)
{
	char	*s;

	s = "numeric argument required\n";
	if (com && com->pipe[1] == -1 && com->pipe[0] == -1)
		write(2, "exit\n", 5);
	if (!com || !argv || !argv[1])
		if (com->pipe[1] == -1 && com->pipe[0] == -1)
			exit(g_minishell.ret);
	if (!is_number(argv[1]))
	{
		senko_print("SSHEL: exit ", argv[1], " :", s);
		if (com->pipe[1] == -1 && com->pipe[0] == -1)
			exit(255);
	}
	else if (ptr_strlen(argv) > 2)
	{
		senko_print("SSHELL: ", "exit: ", NULL, "too many arguments\n");
		return (1);
	}
	exit_value(0, argv, com);
	return (0);
}
