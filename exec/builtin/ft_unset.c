#include "../../minishell.h"

void ft_unset(char **argv)
{
    t_list *env;
    char key[200];
    char *value;
    int i;
    int len;

    value = NULL;
    i = 0;
    env = g_env.env_h;
    value = ft_strchr(argv[1], '=');
    len = custom_len(argv[1]);
    while (i < len)
    {
        key[i] = argv[1][i];
        printf("[%c]\n", argv[1][i]);
        i++;
    }
    printf("[Value ---> %s]\n", value);
    printf("[Key ---> %s]\n", key);
    delete_node(key);
}