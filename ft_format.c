/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_format.c                                 .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/10 17:32:21 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/10 20:24:13 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_format(const char *format)
{
	t_form	form;
	int		i;

	i = 1;
	while (*format)
	{
		while (*format != '%')
		{
			format++;
			if (*format == '%')
/*			while ((format[i] != 's' && format[i] != 'S' && format[i] != 'p' &&
				format[i] != 'd' && format[i] != 'D' && format[i] != 'i' &&
				format[i] != 'o' && format[i] != 'O' && format[i] != 'u' &&
				format[i] != 'U' && format[i] != 'x' && format[i] != 'X' &&
				format[i] != 'c' && format[i] != 'C') && format[i])
			{
				i++;
			}
		}
		form.type = format[i];
		ft_putchar(form.type);
		format += i + 1;*/
			ft_recup_type(format);
	}
}
