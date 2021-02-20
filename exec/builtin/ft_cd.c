#include "../../minishell.h"

void    ft_cd(char **argv)
{
    if (!argv[1])
        printf("Invalid Parametres...\n");
    else if (argv[0] && argv[1] && !argv[2])
    {
        if (chdir(argv[1]) == 0)
            printf("Directory Changed...\n");
        else
            printf("Error...\n");
    }
    else if (argv[2])
        printf("Too many arguments...\n");
}
