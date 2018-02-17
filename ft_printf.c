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

static int	ft_buff(const char *format, int *len)//, char *str)
{
	int		i;
	char	*str;

	i = 0;
	while (format[i] != '%' && format[i])
		i++;
	str = ft_memalloc(i + 1);
	i = 0;
	while (format[i] != '%' && format[i])
	{
		str[i] = format[i];
		i++;
	}
	*len += i;
	write(1, str, ft_strlen(str));
	free(str);
	return (i);
}

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			len;
	int			size;
	int			ln;

	size = 0;
	len = 0; //a supprimer
	va_start(ap, format);
	if (ft_strchr(format, '%') == 0)
		return (write(1, format, ft_strlen(format)));
	else
	{
		while (*format)
		{
			//il faut faire un buffer ici aussi pour
			//me permettre de gerer les erreurs et du coup
			//ne pas afficher le texte
/*			while (*format != '%' && *format)
			{
				write(1, format, 1);
				len++;
				format++;
			}
*/			format += ft_buff(format, &len);//, str);
//			printf("%c", *format);
//			ft_putchar(*(format+1));
			if (*format == '%')
			{
				if ((ln = ft_format(format, ap, &size)) == -1)
		//		if (ln == -1)
				{
					len = -1;
					return (len);
				}
				else
					len += ln;
				format = format + size;
			}
		}
	}
	return (len);
}
