//en tete

#include "ft_printf.h"

void	ft_add_str_begin(char *s1, char *s2)
{
	char	*tmp;
	size_t	i;

	i = 0;
	tmp = ft_memalloc(ft_strlen(s1) + ft_strlen(s2));
	ft_strcat(tmp, s2);
	ft_strcat(tmp, s1);
	ft_strcpy(s1, tmp);
	free(tmp);
}
