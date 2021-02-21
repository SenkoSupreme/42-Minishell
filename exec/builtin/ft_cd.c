#include "../../minishell.h"

void    ft_cd(char **argv)
{
    char *cur;
    char *oldcur;
    char pwdcur[1000];
    char pwdold[1000];
    int i=0;

    cur = getcwd(pwdcur, 200);
    if (!argv[1])
    {
        argv[0] = "~/";
        printf("%s\n", argv[0]);
        i = chdir(argv[0]);
        printf("%d\n", i);

    }
    else if (argv[0] && argv[1] && !argv[2])
    {
        if (chdir(argv[1]) == 0)
        {
            oldcur = getcwd(pwdold, 200);
            add_element("PWD", oldcur);
            add_element("OLDPWD", cur);
            printf("Directory Changed...\n");
        }
        else
            senko_print("cd: ", "no such file or directory: ", argv[1], "\n");
    }
    else if (argv[3])
        ft_putstr_fd("cd: too many arguments\n", 2);
    else if (argv[2] && !argv[3])
        senko_print("cd: ", "string not in pwd: ", argv[1], "\n");
}
