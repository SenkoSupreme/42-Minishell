#include "../minishell.h"

static	char	*senko_getcwd()
{
	char 	*cwd;
	char	*home;
	char	*res;
	int		len;

	cwd = getcwd(NULL, 0);
	home = get_var("HOME");
	len = ft_strlen(home);
	res = "~";
	if (len && ft_strncmp(home, cwd, len) == 0)
	{
		free(home);
		home = ft_substr(cwd, len, ft_strlen(cwd) - len);
		res = ft_strjoin(res, home);
	}
	else
		res = getcwd(NULL, 0);
	free(home);
	free(cwd);
	return (res);
}

void			prompt(char *type)
{
	char *cwd;

	if (!type)
	{
		cwd = senko_getcwd();
		senko_print(CBLU, cwd, " ", NULL);
		senko_print(g_minishell.ret ? CRED : CGRN, "> ", RESET, NULL);
		free(cwd);
	}
	else if (senko_equal_str(type, "|"))
		ft_putstr_fd("pipe > ", 2);
}