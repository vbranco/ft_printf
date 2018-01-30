//en tete

#include "ft_printf.h"

void	ft_add_str_end(char *s1, char *s2)
{
	char	*tmp;

	tmp = ft_memalloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	ft_strcpy(tmp, s1);
	ft_strcat(tmp, s2);
	ft_strcpy(s1, tmp);
	free(tmp);
}
