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

void    ft_add_in_env(char *argv)
{
    char key[200];
    char *value;
    int len;
    int i;
    char    *s;

    value = NULL;
    s = "not a valid identifier\n";
    i = 0;
    value = ft_strchr(argv, '=');
    len = custom_len(argv);
    while (i < len)
    {
        key[i] = argv[i];
        i++;
    }
    key[i] = '\0';
    if (!is_valid_id(key) || argv[0] == '=')
    {
        g_minishell.ret = 1;
        senko_print("SSHEL: export: `", argv, "': ", s);
        return ;
    }
    add_element(key, value + 1);
}

int    ft_export(char **argv)
{
    t_list  *env;
    char    *start;
    int     i;

    i = 1;
    env = g_env.env_h;
    while (argv[i])
        ft_add_in_env(argv[i++]);
    if (!argv[1])
    {
        sort_env(env);
        while (env)
        {
            if ((start = ft_strchr(env->content, '=')))
                export_update(env->content, start);
            env = env->next;
        }
    }
    return (0);
}