/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_recup_length.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 17:20:03 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/18 18:31:36 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_recup_length(const char *format, t_form *form)
{
	int	i;

	i = 0;
	while ((i <= form->size) && format[i])
	{
		if (format[i] == 'h')
		{
			form->length = 'h';
			if (format[i + 1] == 'h')
			{
				form->elength = 'h';
				ft_putchar(form->length);
				ft_putchar(form->elength);
			}
			else
				ft_putchar(form->length);
		}
		else if (format[i] == 'l')
		{
			form->length = 'l';
			if (format[i + 1] == 'l')
			{
				form->elength = 'l';
				ft_putchar(form->length);
				ft_putchar(form->elength);
			}
			else
				ft_putchar(form->length);
		}
		else if (format[i] == 'j')
		{
			form->length = 'j';
			ft_putchar(form->length);
		}
		else if (format[i] == 'z')
		{
			form->length = 'z';
			ft_putchar(form->length);
		}
		i++;
	}
}
