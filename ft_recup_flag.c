/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_recup_flag.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 17:19:56 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/15 20:24:24 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_recup_flag(const char *format, t_form *form)
{
	int	i;

	i = 0;
/*	ft_putstr("form.size = ");
	ft_putnbr(form->size);
	ft_putchar('\n');
*/	while ((i <= form->size) && format[i])//j'ai un souci, la variable form->size vaut 0 alors que quand j'affiche depuis la fonction recup_type elle affiche bien la bonne valeur
	{
		if (format[i] == '#')
			form->is_h = 1;
		else if (format[i] == '0')
		{
			if ((format[i - 1] < '0' || format[i - 1] > '9') &&
				(format[i + 1] < '0' ||  format[i + 1] > '9'))
				form->is_z = 1;
		}
		else if (format[i] == '-')
			form->is_n = 1;
		else if (format[i] == '+')
			form->is_p = 1;
		else if (format[i] == ' ')
			form->is_s = 1;
		i++;
	}

	if (form->is_h == 1)
		ft_putchar('#');
	if (form->is_z == 1)
		ft_putchar('0');
	if (form->is_n == 1)
		ft_putchar('-');
	if (form->is_p == 1)
		ft_putchar('+');
	if (form->is_s == 1)
		ft_putchar(' ');
}
