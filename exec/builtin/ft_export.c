#include "../../minishell.h"

static void    export_update(char *start)
{
    int len;
    int i;

    i = 0;
    len = ft_strlen(start);
    ft_putstr_fd("\"", 1);
    while (i < len)
    {
        ft_putchar_fd(start[i], 1);
        i++;
    }
    ft_putstr_fd("\"\n", 1);
}

void    ft_export()
{
    t_list *env;
    char *start;

    env = g_env.env_h;
    while (env)
	{
		if ((start = ft_strchr(env->content, '=')))
		{
            ft_putstr_fd("declare -x ", 1);
            export_update(start);
			// ft_putstr_fd(env->content, 1);
			// ft_putstr_fd("\n", 1);
		}
		env = env->next;
	}
}