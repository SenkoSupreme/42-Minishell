char	*ft_strchr(const char *s, int c)
{
	int	i;
	int j;
    char *str;

	j = 0;
	while (s[j])
		j++;
	i = 0;
	while (i <= j){
		if (s[i] == (char)c)
			return (str);
		else
		{
			str[i] = s[i];
			i++;
		}
	}
	return (str);
}
#include <stdio.h>
int main(){
	printf("[%s]\n",ft_strchr("saad=saad",'='));
	return (0);
}

