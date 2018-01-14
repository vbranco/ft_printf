//en tete

#include "ft_printf.h"

int	ft_recup_flag(const char *format, t_form form)
{
	int	i;

	i = 0;
	if (format[i] == '#' || format[i] == '0' || format[i] == '-' ||
		format[i] == '+' || format[i] == ' ')
	{
		form.flag = format[i];
		ft_putchar(form.flag);
		return (1);
	}
	else
	{
		form.flag = 'n';
//		ft_putchar(form.flag);
		return (0);
	}
}
