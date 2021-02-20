#include "../minishell.h"

void	exec_sys_com(t_command *com)
{
	char **argv;

	argv = list_to_array(com->argv);
	open_red_files(com);
	dup2(com->in_red, 0);
	dup2(com->out_red, 1);
	//redirect
	exit(127);
}