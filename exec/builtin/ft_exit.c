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
    int ret;

    ret = 0;
	// mini->exit = 1;
	ft_putstr_fd("exit\n", 2);
    // printf("[%s]  ----  [%s]\n",cmd[0], cmd[1]);
	// cmd[0] ? ft_putendl_fd("❤️", 2) : ft_putendl_fd("💚", 2);
	if (cmd[0] && cmd[1])
	{
		// mini->ret = 1;
        ret = 1;
		ft_putendl_fd("minishell: exit: too many arguments", 2);
	}
	else if (cmd[0] && ft_strisnum(cmd[0]) == 1)
	{
		// mini->ret = 255;
        ret = 255;
		ft_putstr_fd("minishell: exit: ", 2);
		ft_putstr_fd(cmd[0], 2);
		ft_putendl_fd(": numeric argument required", 2);
	}
	else if (cmd[0])
		ret = ft_atoi(cmd[0]);
	else
		ret = 0;
}