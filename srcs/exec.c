#include "../minishell.h"

static	int	senko_wait()
{
	int ret;
	int	pid;

	pid = wait(&ret);
	if (WIFEXITED(ret))
		if (g_minishell.last_cmd == pid)
			g_minishell.ret = WEXITSTATUS(ret);
	g_minishell.fork_p = 0;
	return (pid);
}

static	int	init_exec(t_command *com, int *n, char ***av)
{
	if (!com || !com->argv || com->in_red == -1 || com->out_red == -1)
		return (1);
	if (com->in_red == 0)
	{
		while((*n)--)
			senko_wait();
		n = 0;
	}
	convert_argv_env(&com->argv, NULL, NULL);
	*av = list_to_array(com->argv);
	return (0);
}

static	void builtin_coms(t_command *com, char **argv, int ret)
{
	int in;
	int out;

	g_minishell.last_cmd = ret;
	in = dup(0);
	out = dup(1);
	dup2(com->in_red, 0);
	dup2(com->out_red, 1);
	// g_minishell.ret =  int - > treat builtin com ! takes (**argv, int com id) 
	dup2(in, 0);
	dup2(out, 1);
	if (com->in_red != 0)
		close(com->in_red);
	if (com->out_red != 1)
		close(com->out_red);
	free(argv);
}

void	exec_commands()
{
	t_list		*lst;
	t_command	*com;
	int			ret;
	char		**argv;
	int			n;

	lst = g_minishell.com_head;
	n = 0;
	while(lst != NULL)
	{
		open_red_files(com = lst->content);
		if (init_exec(com, &n, &argv) && ((lst = lst->next) || 1))
			continue;
		if ((ret = is_command(argv[0])))
			builtin_coms(com, argv, ret);
		else
		{
			free(argv);
			// system coms  void -> (command, int ret, int *n)
		}
		lst = lst->next;
	}
	while (n--)
		senko_wait();
	free_red_files();
}