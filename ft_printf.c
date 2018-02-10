/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/12 20:07:34 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/10 14:20:41 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			len;
	int			size;

	size = 0;
	len = 0; //a supprimer
	va_start(ap, format);
	if (ft_strchr(format, '%') == 0)
		return (write(1, format, ft_strlen(format)));
	else
	{
		while (*format)
		{
			while (*format != '%' && *format)
			{
				write(1, format, 1);
				len++;
				format++;
			}
			if (*format == '%')
			{
				len += ft_format(format, ap, &size);
				format = format + size;
			}
		}
	}
	return (len);
}
