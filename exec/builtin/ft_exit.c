#include "../../minishell.h"

static int	ft_strisnum(const char *str)
{
	int	i;

	i = 0;
	if (str == NULL)
		return (0);
	if (str[0] == '-')
		i++;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

void	ft_exit(char **cmd)
{
	ft_putstr_fd("exit\n", 2);
	if (cmd[2])
	{
		g_minishell.ret = 1;
		ft_putendl_fd("minishell: exit: too many arguments", 2);
	}
	else if (cmd[0] && ft_strisnum(cmd[1]) == 0)
	{
		g_minishell.ret = 255;
		senko_print("minishell: ", "exit :", cmd[1], ": numeric argument required\n");
	}
	else if (cmd[1])
		g_minishell.ret = ft_atoi(cmd[1]);
	else
		g_minishell.ret = 0;
}