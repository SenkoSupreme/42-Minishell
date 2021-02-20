#include "../../minishell.h"

static void    sort_env(t_list *env)
{
    t_list *tmp;
    t_list *cur;

    tmp = NULL;
    while (env)
	{
        cur = env->next;
        while (cur)
        {
            if (ft_strcmp(env->content, cur->content) > 0)
            {
                tmp = env->content;
                env->content = cur->content;
                cur->content= tmp;
            }
            cur = cur->next;
        }
        env = env->next;
	}
}

static void    export_update(char *str ,char *start)
{
    int len;
    int i;

    i = 0;
    len = ft_strlen(start);
    ft_putstr_fd("declare -x ", 1);
    while (str[i])
        if (str[i] != '=')
            ft_putchar_fd(str[i++], 1);
        else
            break;
    i = 1;
    ft_putstr_fd("=\"", 1);
    while (i < len)
        ft_putchar_fd(start[i++], 1);
    ft_putstr_fd("\"\n", 1);
}

void    ft_export()
{
    t_list *env;
    char *start;

    env = g_env.env_h;
    sort_env(env);
    while (env)
	{
		if ((start = ft_strchr(env->content, '=')))
            export_update(env->content, start);
		env = env->next;
	}
}