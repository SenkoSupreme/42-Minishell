#include "../../minishell.h"

static int     n_skip(char *s)
{
    int i;
    i = 1;
    if (s[0] == '-' && s[1] == '\0')
        return (0);
    if (s[0] != '-')
        return (0);
    while (s[i])
    {
        if (s[i] != 'n')
            return (0);
        i++;
    }
    // printf("[%c] ---- [%c]\n", s[0], s[1]);
    return (1);
}

void    ft_echo(char **argv)
{
    int i;
    int n_opt;
    n_opt = 0;
    if (!argv[1])
    {
        ft_putstr_fd("\n", 1);
        return ;
    }
    i = 1;
    while (argv[i] && n_skip(argv[i]))
    {
        n_opt = 1;
        i++;
    }
    while (argv[i])
    {
        ft_putstr_fd(argv[i], 1);
        i++;
        if (argv[i])
            ft_putstr_fd(" ", 1);
    }
    if (!n_opt)
        ft_putstr_fd("\n", 1);
}