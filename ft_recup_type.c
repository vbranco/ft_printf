//en tete

#include "ft_printf.h"

int	ft_recup_type(const char *format)
{
	t_form	form;
	int	i;

	i = 1;
	while ((format[i] != 's' && format[i] != 'S' && format[i] != 'p' &&
		format[i] != 'd' && format[i] != 'D' && format[i] != 'i' &&
		format[i] != 'o' && format[i] != 'O' && format[i] != 'u' &&
		format[i] != 'U' && format[i] != 'x' && format[i] != 'X' &&
		format[i] != 'c' && format[i] != 'C') && format[i])
		i++;
	form.type = format[i];
	ft_putchar(form.type);
	return (format + i + 1);
}
