#include "shell.h"

/* this is here for norm shit 
void shell_loop(void)
{

}*/

char *read_line(void)
{
	int buff_size;
	int pos;
	int c;
	char *buffer;

	buff_size = 1024;
	pos = 0;
	buffer = malloc(sizeof(char) * buff_size);

	//protection 

	while (1)
	{
		c = senko_getchar();
		if (c == EOF || c == '\n')
		{
			buffer[pos] = '\0';
			return buffer;	
		}
		else 
			buffer[pos] = c;
		pos++;
		if (pos >= buff_size)
		{
			buff_size += 1024;
			buffer = malloc(sizeof(char) * buff_size);
			//protection
		}
	}

	return buffer;
}

int	shell_loop(t_env *env)
{
	int 	ret;
	char	*cleanLine;

	ft_putstr("\033[1;3;4;33;41m Union_of_Senko_Shell_Republicans \033[0m$> ");
	cleanLine = read_line();
	env->input->line = skip_white_spaces(cleanLine);
	if(!env->input->line)
		return -1;
	else if (line_is_empty(env->input->line))
		return 0;
	printf("  ~ initial buffer : > %s\n", env->input->line);
	ret = tokenise(env);
	//exec
	//free
	return 0;
}

int main(int ac, char **av, char **ev)
{
	t_env	env;

	env.input = initiate(ac, av, ev);

	// t_node *lst = NULL;

	// char *tmp;
	// char *tmp1;
	// tmp = "hell on earth";
	// tmp1 = "hell on fire";

	// add_at_the_end(&lst, tmp);
	// add_at_the_end(&lst, tmp1);
	// while (lst)
	// {
	// 	printf("  ~ added : > %s\n", (char*)lst->data);
	// 	lst = lst->next;
	// }
	

	while (1) //Read-Eval-Print-L
	{
		if(shell_loop(&env))
			break;
	}
	//free
	return (0);
}