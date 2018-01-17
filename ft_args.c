/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_args.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 19:19:45 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/17 19:53:51 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_args(t_form *form, va_list ap)
{
	char	c;
	char	*str;

	if (form->type == 'c')
		c = ft_arg_c(ap);
	if (form->type == 'd' || form->type == 'i')
		str = ft_arg_d_i(ap);
	if (form->type == 's')
		str = ft_arg_s(ap);
	ft_putstr(str);
//	ft_putchar(c);
}
