/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/12 20:07:34 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 20:24:52 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	int		len;
	int		size;

	len = 0; //a supprime
	size = 0;
	va_start(ap, format);
	if (ft_strchr(format, '%') == 0)
	{
		write(1, format, ft_strlen(format));
		return (ft_strlen(format));
	}
	else
	{
		while (*format)
		{
			if (*format != '%')
			{
				write(1, format, 1);
				format++;
			}
			else
			{
				len = ft_format(format, ap, &size);
			/*	while ((*format != 'c' || *format != 'C' ||
					*format != 's' || *format != 'S' ||
					*format != 'd' || *format != 'D' ||
					*format != 'o' || *format != 'O' ||
					*format != 'u' || *format != 'U' ||
					*format != 'x' || *format != 'X' ||
					*format != 'i' || *format != 'p') && *format)
			*/	ft_putstr("size : ");
				ft_putnbr(size);
				format += size;
			}
		}
	}
	return (len);
}
