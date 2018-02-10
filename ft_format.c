/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_format.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 17:22:45 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/10 12:35:50 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_format(const char *format, va_list ap, int *size)
{
	t_form	form;
	int		len;

	len = 0;
	if (*format == '%' && *(format + 1) == '%')
	{
		ft_putchar('%');
		format += 2;
	}
	if (*format == '%')
	{
		ft_init_struct(&form);
		format++;
		ft_recup_type(format, &form);
		ft_recup_flag(format, &form);
		ft_recup_length(format, &form);
		ft_recup_min(format, &form);
		ft_recup_prec(format, &form);
		len = ft_args(&form, ap);
		*size = form.size;
	}
//	else
//		while (*format != '%' && *format)
//			format++;
	return (len);
}
