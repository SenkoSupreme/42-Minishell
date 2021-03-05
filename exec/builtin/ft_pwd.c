#include "../../minishell.h"

int		ft_pwd(void)
{
	char	pwd[4000];

	if (getcwd(pwd, 100))
	{
		ft_putendl_fd(pwd, 1);
		return (1);
	}
	else
		return (0);
}
