#include "../minishell.h"

int		iter_path(int i, char **ev_args, char **argv)
{
	char		*s;
	struct stat	sbuff;
	
	while(g_env.path[++i])
	{
		s = join_path(g_env.path[i], "/", argv[0]);
		if (stat(s, &sbuff) == 0 && sbuff.st_mode & S_IXUSR)
		{
			execve(s, argv, ev_args);
			free(s);
			free(ev_args);
			return (0);
		}
		else if (stat(s, &sbuff) == 0 && !(sbuff.st_mode & S_IXUSR))
		{
			senko_print("SSHELL: ", s, ": ", "Permission Denied");
			free(ev_args);
			free(s);
			exit(126);
		}
		free(s);
	}
	return (1);
}

int		try_path(char **argv)
{
	char	**ev_args;

	ev_args = list_to_array(g_env.env_h);
	if (!(g_env.path = ft_split(get_path(), ':')))
		return (1);
	if (!iter_path(-1, ev_args, argv))
		return (0);
	free(ev_args);
	return (1);
}

int		sys_redirect(char **argv)
{
	char		**ev_args;
	struct stat	sbuff;
	int			ret;

	ev_args = list_to_array(g_env.env_h);
	ret = stat(argv[0], &sbuff);
	if (S_ISLNK(sbuff.st_mode))
		ret = lstat(argv[0], &sbuff);
	// printf("ret : %d | arv : %s\n", ret, argv[0]);
	check_permissions(ev_args, argv, sbuff, ret);
	free(ev_args);
	if (!ft_strchr(argv[0], '/'))
		if (!try_path(argv))
			return (0);
	if (ret && argv[0] && ft_strchr(argv[0], '/'))
	{
		senko_print("SSHELL: ", argv[0], ": ", strerror(errno));
		return (1);
	}
	if (!get_path() || *get_path() == 0)
		senko_print("SSHELL: ", argv[0], ": ", "No Such File or Directoy"); 
	else
		senko_print("SSHELL: ", argv[0], ": ", "Command not found");
	return (1);
}

void	exec_sys_com(t_command *com)
{
	char **argv;

	argv = list_to_array(com->argv);
	open_red_files(com);
	dup2(com->in_red, 0);
	dup2(com->out_red, 1);
	sys_redirect(argv);
	exit(127);
}