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

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*ptr;
	size_t		i;

	i = 0;
	if (s == 0)
		return (NULL);
	if (ft_strlen(s) <= start)
	{
		if (!(ptr = (char *)malloc(1)))
			return (NULL);
		ptr[0] = '\0';
		return (ptr);
	}
	if (!(ptr = (char*)malloc((len + 1) * sizeof(char))))
		return (NULL);
	while (i < len)
	{
		ptr[i++] = s[start++];
	}
	ptr[i] = '\0';
	return (ptr);
}

void	add_back(t_node **list, void *data)
{
	t_node *new;

	new = *list;
	while(new)
		new = new->next;
	new = new_node(data);
	if(!new)
		return ;
}