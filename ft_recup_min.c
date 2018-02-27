/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_recup_min.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 16:42:01 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 18:20:31 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_wildcard(const char *str, int start, int end)
{
	while ((start < end) && str[start])
	{
		if (str[start] == '*')
			return (1);
		if (str[start] == '.')
			return (0);
		start++;
	}
	return (0);
}

void		ft_recup_min(const char *format, t_form *form, va_list ap)
{
	int		i;

	i = 0;
	while (format[i] && (i < form->size))
	{
		while (format[i] == '+' || format[i] == '-' || format[i] == '#' || format[i] == '0')
			i++;
		if (ft_wildcard(format, i , form->size))
		{
			if (format[i] == '*')
			{
				i++;
				if (format[i] >= '1' && format[i] <= '9')
				{
					format += i;
					form->min = (int)va_arg(ap, int);
					form->min = ft_atoi(format);
				}
				else
				{
					format += i;
					form->min = (int)va_arg(ap, int);
				}
			}
			else
			{
				while (format[i] >= '1' && format[i] <= '9')
					i++;
				format += i;
				form->min = (int)va_arg(ap, int);
			}
			break;
		}
		else
		{
			if (format[i] >= '1' || format[i] <= '9')
			{
				format += i;
				form->min = ft_atoi(format);
				break;
			}
		}
		break;
	}
}
