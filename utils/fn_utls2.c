#include "../shell.h"

int 	senko_getchar(void)
{
	char	buf[1];
    int		n; 
	
	n = read(0, buf, 1);

    if(n < 1)
        return (-1);

    return (buf[0]);
}

char	*ft_substr(char const *s, int start, int end)
{
	char		*sub;
	size_t		i;
	int			len;

	if(!s)
		return NULL;
	len = ft_strlen(s);
	if (start > (int)len || end < 0)
		return ft_strdup("");
	start = start < 0 ? 0 : start;
	end = end >= len ? len : end;
	if (!(sub = malloc(end - start + 1)))
		return NULL;
	i = 0;
	while (start < end && s[start])
	{
		sub[i] = s[start];
		i++;
		start++;
	}
	sub[start] = '\0';
	return sub;
}
int		array_is_index(int index, t_array *array)
{
	int i;

	i = 0;
	while (i < array->size)
		if (index == array->array[i])
			return 1;
		else
			i++;
	return 0;
}

char	*senko_substr(char const *s, int start, int end, t_array *skip_index)
{
	char	*sub;
	short	skip_num;
	size_t	i;
	int		len;

	if(!s)
		return(NULL);
	len = ft_strlen(s);
	if (start > (int)len || end < 0)
		return (ft_strdup(""));
	start = start < 0 ? 0 : start;
	end = end >= len ? len : end;
	skip_num = 0;
	if (skip_index != NULL)
	{
		while (skip_num < skip_index->size && skip_index->array[skip_num] != -1)
			skip_num ++;
	}
	if (!(sub = malloc(end - start + 1 - skip_num)))
		return NULL;
	i = 0;
	while (start < end && s[start])
	{
		if (array_is_index(start, skip_index) == 0)
		{
			sub[i] = s[start];
			i++;
			start++;
		}
		else
			start++;
	}
	sub[start] = '\0';
	return (sub);
}

int		line_is_empty(char *line)
{
	if(line[0] == '\n' && line[1] == 0)
		return 1;
	return 0;
}

char 	*skip_white_spaces(char *line)
{
	size_t i = 0;

	while(i <= ft_strlen(line))
	{
		if (line[i] == ' ' || line[i] == '\t')
			i++;
		else
			break;
	}
	return line + i; 
}

int	ft_strcmp(const char *s1, const char *s2)
{
	int i;
	size_t n;

	n = ft_strlen(s1);
	i = -1;
	if (s1 == NULL || s2 == NULL)
	if(n < ft_strlen(s2))
		return -1;
	while ((size_t)++i < n)
		if (((unsigned char)s1[i] - (unsigned char)s2[i]) != 0
				|| s1[i] == 0 || s2[i] == 0)
			return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	return (0);
}