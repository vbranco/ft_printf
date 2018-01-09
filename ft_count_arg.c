//en tete

#include "ft_printf.h"

int	ft_count_args(const char *format)
{
	int	nb;
	int	i;

	nb = 0;
	i = 0;
	while (format[i])
	{
		if (format[i] == '%')
			nb++;
		i++;
	}
	return (nb);
}
