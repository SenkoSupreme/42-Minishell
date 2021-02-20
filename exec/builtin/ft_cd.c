#include "../../minishell.h"

void    ft_cd(char **argv)
{
    char *cur;
    char *oldcur;
    char saad[1000];
    char saad1[1000];

    cur = getcwd(saad, 200);
    if (!argv[1])
        printf("Invalid Parametres...\n");
    else if (argv[0] && argv[1] && !argv[2])
    {
        if (chdir(argv[1]) == 0)
        {
            oldcur = getcwd(saad1, 200);
            add_element("PWD", oldcur);
            add_element("OLDPWD", cur);
            printf("Directory Changed...\n");
        }
        else
            printf("Error...\n");
    }
    else if (argv[2])
        printf("Too many arguments...\n");
}
