//en tete

#include "ft_printf.h"

int	ft_recup_length(const char *format, t_form form)
{
	int	i;

	i = 0;
	while ((format[i] != 'h' && format[i] != 'l' && format[i] != 'j' &&
		format[i] != 'z') && format[i])
		i++;
	(format[i] == '\0') ? i = 0 : 0;
	if (format[i] == 'h')
	{
		form.length = 'h';
		if (format[i + 1] == 'h')
		{
			form.elength = 'h';
			ft_putchar(form.length);
			ft_putchar(form.elength);
			return (i + 1);
		}
		ft_putchar(form.length);
	}
	if (format[i] == 'l')
	{
		form.length = 'l';
		if (format[i + 1] == 'l')
		{
			form.elength = 'l';
			ft_putchar(form.length);
			ft_putchar(form.elength);
			return (i + 1);
		}
		ft_putchar(form.length);
	}
	if (format[i] == 'j')
	{
		form.length = 'j';
		ft_putchar(form.length);
	}
	if (format[i] == 'z')
	{
		form.length = 'z';
		ft_putchar(form.length);
	}
	return (i);
}
