





#include "ft_printf.h"

int	ft_arg(const char *format, ...)
{
	va_list		ap;
	int		nb_arg;
	char		*form;
	int		i;

	nb_arg = 0;
	form = format;
	va_start(ap, format);
	while (form != NULL
}
