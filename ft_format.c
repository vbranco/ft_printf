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
	int	i;
	t_form	form;

	while (*format)
	{
		if (*format == '%' && *(format + 1) == '%')
		{
			ft_putchar('%');
			format += 2;
		}
		if (*format == '%')
		{
			format ++;
			i = (ft_recup_flag(format, form));
			format += i;
			i = (ft_recup_length(format, form));
			format += i;
			i = (ft_recup_type(format, form));
			format += i;
		}
		else
		{
			while (*format != '%' && *format)
				format++;
		}
	}
}
