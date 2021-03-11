/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec_builtin.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbrija <mbrija@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/02 15:30:48 by mbrija            #+#    #+#             */
/*   Updated: 2021/03/11 15:42:28 by mbrija           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minishell.h"

int		exec_builtin(char **cmd, int ret, t_command *com)
{
	if (ret == 1)
		ft_echo(cmd);
	else if (ret == 2)
		return (ft_cd(cmd));
	else if (ret == 3)
		ft_pwd();
	else if (ret == 4)
		return (ft_export(cmd));
	else if (ret == 5)
		return (ft_unset(cmd));
	else if (ret == 6)
		ft_env(cmd);
	else if (ret == 7)
		return (ft_exit(cmd, com));
	return (0);
}
