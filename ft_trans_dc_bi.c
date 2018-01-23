
#include "ft_printf.h"

void	ft_trans_dc_bi(long nb, char ***str)
{
	size_t	i;
	char	*s;

	i = 0;
	s = ft_memalloc(65);
	while (nb > 0)
	{
		if (nb % 2 == 0)
			s[i] = '0';
		else
			s[i] = '1';
		nb /= 2;
		i++;
	}
	ft_strcpy(**(str), s);
	free(s);
}
