#include "../minishell.h"

char	*replace_env(char *str, char *res, int *i, int len)
{
	char	*tmp;
	char	*var;

	tmp = ft_substr(str, *i, len);
	(*i) += len;
	var = get_var(tmp);
	free(tmp);
	tmp = res;
	res = ft_strjoin(res, var);
	free(var);
	free(tmp);
	return (res);
}
