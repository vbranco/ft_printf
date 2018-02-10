/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_recup_min.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 16:42:01 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/10 13:31:55 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_recup_min(const char *format, t_form *form)
{
	int		i;

	i = 0;
	while (format[i] && (i < form->size))
	{
		while (format[i] == '+' || format[i] == '-' || format[i] == '#' || format[i] == '0')
			i++;
	/*	if (format[i] == '0')
		{
			if (format[i + 1] >= '1' || format[i + 1] <= '9')
			{
				format += i;
				form->min = ft_atoi(format);
				break ;
			}
		}
		else*/ if (format[i] >= '1' || format[i] <= '9')
		{
			format += i;
			form->min = ft_atoi(format);
			break ;
		}
	}
}
