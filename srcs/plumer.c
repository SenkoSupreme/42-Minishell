#include "../shell.h"

void	safe_free(void **ptr)
{
	if(*ptr == NULL)
	{
		free(*ptr);
		*ptr = NULL;
	}
}