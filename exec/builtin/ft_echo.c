#include "../../minishell.h"

// static void ft_putstr_fd(char *s, int fd)
// {
//     int i;

//     i = 0;
//     if (s == NULL)
//         return;
//     while (s[i] != '\0')
//     {
//         write(fd, &s[i], 1);
//         i++;
//     }
// }

// static int nb_args(t_env *node, int *n_option)
// {
//     int size;

//     t_node *tmp = node->simpletokens;
//     size = 0;
//     while (tmp)
//     {
//         size++;
//         if (strcmp(tmp->data, "-n") == 0)
//             *n_option = 1;
//         tmp = tmp->next;
//     }
//     free(tmp);
//     return (size);
// }

// void ft_echo(char *cmd)
// {
//     int i;
//     int n_option;

//     n_option = 0;
//     i = nb_args(cmd, &n_option);
//     node->simpletokens = node->simpletokens->next;
//     if (i > 1)
//     {
//         if (n_option)
//             node->simpletokens = node->simpletokens->next;
//         while (node->simpletokens)
//         {
//             ft_putstr_fd(node->simpletokens->data, 1);
//             node->simpletokens = node->simpletokens->next;
//         }
//     }
//     if (n_option == 0)
//         write(1, "\n", 1);
//     // return (1);
// }






// static void ft_putstr_fd(char *s, int fd)
// {
//     int i;

//     i = 0;
//     if (s == NULL)
//         return;
//     while (s[i] != '\0')
//     {
//         write(fd, &s[i], 1);
//         i++;
//     }
// }

// static	int		nb_args(char **args)
// {
// 	int		size;

// 	size = 0;
// 	while (args[size])
// 		size++;
// 	return (size);
// }

// int				ft_echo(char **args)
// {
// 	int		i;
// 	int		n_option;

// 	i = 1;
// 	n_option = 0;
// 	if (nb_args(args) > 1)
// 	{
// 		while (args[i] && strcmp(args[i], "-n") == 0)
// 		{
// 			n_option = 1;
// 			i++;
// 		}
// 		while (args[i])
// 		{
// 			ft_putstr_fd(args[i], 1);
// 			if (args[i + 1] && args[i][0] != '\0')
// 				write(1, " ", 1);
// 			i++;
// 		}
// 	}
// 	if (n_option == 0)
// 		write(1, "\n", 1);
// 	return (1);
// }

static int     n_skip(char *s)
{
    int i;
    i = 1;
    if (s[0] != '-')
        return (0);
    while (s[i])
    {
        if (s[i] != 'n')
            return (0);
        i++;
    }
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