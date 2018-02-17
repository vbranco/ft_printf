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

/*static void	ft_buff(const char *format, char *str)
{
	int		i;

	i = 0;
}*/

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
			while (*format != '%' && *format)
			{
				write(1, format, 1);
				len++;
				format++;
			}
			if (*format == '%')
			{
				ln = ft_format(format, ap, &size);
				if (ln == -1)
					return (-1);
				else
					len += ln;
				format = format + size;
			}
		}
	}
	return (len);
}
