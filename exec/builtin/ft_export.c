#include "../../minishell.h"

static void    export_update(char **str, char *start)
{
    int len;

    len = ft_strlen(*str);
    ft_putstr_fd("\"", 1);
    while (++(*start) <= len)
    {
        ft_putstr_fd(str[*start], 1);
    }
    ft_putstr_fd("\"\n", 1);
}

void    ft_export()
{
    t_list *env;
    char *start;

    start = 0;
    env = g_env.env_h;
    while (env)
	{
		if ((start = ft_strchr(env->content, '=')))
		{
            ft_putstr_fd("declare -x ", 1);
            export_update(env->content, &start);
			// ft_putstr_fd(env->content, 1);
			// ft_putstr_fd("\n", 1);
		}
		env = env->next;
	}
}