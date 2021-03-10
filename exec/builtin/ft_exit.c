/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrija <mbrija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:08:21 by sel-fadi          #+#    #+#             */
/*   Updated: 2021/03/10 12:57:35 by mbrija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int		ft_exit(char **argv)
{
	char	*s;

	s = "numeric argument required\n";
	if (g_minishell.n_pipes < 1)
		write(2, "exit\n", 5);
	if (!argv || !argv[1])
		exit(g_minishell.ret);
	if (!is_number(argv[1]))
	{
		senko_print("SSHEL: exit ", argv[1], " ", s);
		if (g_minishell.n_pipes < 1)
			exit(255);
	}
	else if (ptr_strlen(argv) > 2)
	{
		senko_print("SSHELL: ", "exit: ", NULL, "too many arguments\n");
		return (1);
	}
	if (g_minishell.n_pipes == 0)
		exit_value(0, argv);
	return (0);
}
