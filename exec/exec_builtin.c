#include "../minishell.h"

int		exec_builtin(char **cmd, int ret)
{
	if (ret == 1)
		ft_echo(cmd);
	else if (ret == 2)
		printf("hello from cd\n");
	else if (ret == 3)
		ft_pwd();
	// else if (strcmp(cmd, "export") == 0)
	// 	printf("hello from export\n");
	// else if (strcmp(cmd, "unset") == 0)
	// 	printf("hello from unset\n");
	// else if (strcmp(cmd, "env") == 0)
	// 	printf("hello from env\n");
	else if (ret == 7)
		ft_exit(cmd);
	// else
	// 	printf("hello from nothing\n");
	else if (ret == 4)
		printf("hello from export\n");
	else if (ret == 5)
		printf("hello from unset\n");
	else if (ret == 6)
		ft_env(cmd);
	else if (ret == 7)
		printf("hello from exit\n");
	return (0);
}