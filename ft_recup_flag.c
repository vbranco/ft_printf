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
*/	while ((i <= form->size + 1) && format[i])
	{
		if (format[i] == '#')
		{
			form->is_h = 1;
		//	ft_putendl("j'ai un #");
		}
		else if (format[i] == '0')
		{
			form->is_z = 1;
		//	ft_putendl("j'ai un 0");
		}
		else if (format[i] == '-')
		{
			form->is_n = 1;
		//	ft_putendl("j'ai un -");
		}
		else if (format[i] == '+')
		{
			form->is_p = 1;
		//	ft_putendl("j'ai un +");
		}
		else if (format[i] == ' ')
		{
			form->is_s = 1;
		//	ft_putendl("j'ai un ' '");
		}
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
