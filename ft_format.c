/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_format.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 17:22:45 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/17 20:06:56 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_format(const char *format, va_list ap)
{
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
			ft_init_struct(&form);
			format++;
			ft_recup_type(format, &form);
			ft_recup_flag(format, &form);//jetter un oeil pas bon
			ft_recup_length(format, &form);
			ft_recup_min(format, &form);
			ft_recup_prec(format, &form);
		}
		else
			while (*format != '%' && *format)
				format++;
	}
	ft_args(&form, ap);
}
