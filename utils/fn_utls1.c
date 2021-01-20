#include "../shell.h"

void	ft_putstr(char const *s)
{
	if (!s)
		return ;
	write(0, s, ft_strlen(s));
}

size_t	ft_strlen(const char *s)
{
	size_t i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strdup(char *s)
{
	int		i;
	int		len;
	char	*p;

	i = 0;
	len = ft_strlen(s);
	p = malloc(len + 1);
	while (s[i])
	{
		p[i] = s[i];
		i++;
	}
	p[i] = 0;
	return (p);
}

char	*ft_strchr(char *s, char c)
{
	int i;

	i = 0;
	while (s[i++])
		if (s[i] == c)
		{
			return (s + i);
		}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int i;
	int j;
	int len1;
	int len2;

	i = 0;
	j = 0;
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	char *p = malloc (len1 + len2 + 1);
	while (i < len1 + len2)
	{
		if (i < len1)
			p[i] = s1[i];
		else
			p[i] = s2[j++];
		i++;
	}
	p[i] = 0;
	return (p);
}
/* ADDONS */
// void *def_not_calloc(size_t size)
// {
// 	void *ptr;

// 	if (!(ptr = malloc(size)))
// 		return NULL;
// 	ft_bzero(ptr, size);
// 	return ptr;
// }


// void	*ft_memcpy(void *dst, const void *src, size_t n)
// {
// 	size_t	i;

// 	i = -1;
// 	while (++i < n)
// 		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
// 	return (dst);
// }

// void *senko_realloc(void *ptr, size_t old_s, size_t new_s)
// {
// 	void *new;

// 	if (!ptr)
// 		return NULL;
// 	if (!(new = def_not_calloc(new_s)))
// 	{
// 		ft_memcpy(new, ptr, old_s < new_s ? old_s : new_s);
// 		free(ptr);
// 		return NULL;
// 	}
	
// }
// void	ft_bzero(void *s, size_t n)
// {
// 	unsigned char *tmp;

// 	tmp = (unsigned char*)s;
// 	while (n--)
// 		*tmp++ = 0;
// }

