


#include "ft_printf.h"

char		**ft_recup_params(const char *format)
{
	char	**tmp;
	int	i;

	i = 0;
	while (format[i] != '%')
		i++;
	format = format + i;
	tmp = ft_strsplit(format, '%');
	return (tmp);
}
