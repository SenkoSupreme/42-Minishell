#include "../../minishell.h"

static void    sort_env(t_list **env)
{
    int i;
    int j;
    int size;
    char *str1;
    char *str2;

    i = 0;
    j = 0;
    while (*env)
	{
        str1 = (*env)->content;
        size = ft_strlen(str1);
        while (i < size)
        {
            while (j + i < size)
            {
                (*env) = (*env)->next;
                str2 = (*env)->content;
                if (ft_strcmp(str1[i], str2[j + i]) > 0)
                    j++;
                else
                    
            }
            (*env) = (*env)->next;
            i++;
        }
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
    sort_env(&env);
    while (env)
	{
		if ((start = ft_strchr(env->content, '=')))
            export_update(env->content, start);
		env = env->next;
	}
}