/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrija <mbrija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/05 14:08:09 by sel-fadi          #+#    #+#             */
/*   Updated: 2021/03/14 14:49:07 by mbrija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../minishell.h"

int		norme_hack(char **argv, char *cur, t_command *com)
{
	char pwdold[1000];
	char *oldcur;

	if (opendir(argv[1]) && com->pipe[1] == -1 && com->pipe[0] == -1)
	{
		chdir(argv[1]);
		oldcur = getcwd(pwdold, 200);
		add_element("PWD", oldcur);
		add_element("OLDPWD", cur);
	}
	else if (!opendir(argv[1]))
	{
		senko_print("SSHEL :", " cd: ", argv[1],
		" No such file or directory\n");
	}
	return (0);
}

int		ft_cd(char **argv, t_command *com)
{
	char *cur;
	char pwdcur[1000];
	char *str;

	cur = getcwd(pwdcur, 200);
	str = get_var("HOME");
	if (!argv[1] && com->pipe[1] == -1 && com->pipe[0] == -1)
	{
		argv[0] = str;
		chdir(argv[0]);
	}
	else if (argv[0] && argv[1])
		norme_hack(argv, cur, com);
	return (0);
}
