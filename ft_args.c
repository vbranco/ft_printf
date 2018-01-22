/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_args.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 19:19:45 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/17 20:06:45 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_args(t_form *form, va_list ap)
{
	if (form->type == 'c' || (form->type == 'C' && form->length == 'h'))
		ft_arg_c(ap, form);
	if (form->type == 'C' || (form->type == 'c' && form->length == 'l'))
		ft_arg_c(ap, form);
	if (form->type == 's' || (form->type == 'S' && form->length == 'h'))
		ft_arg_s(ap, form);
	if (form->type == 'S' || (form->type == 's' && form->length == 'l'))
		ft_arg_s(ap, form);
	if (form->type == 'd' || form->type == 'D' || form->type == 'i' ||
		form->type == 'u' || form->type == 'U')
		ft_arg_d_i(ap, form);
	if (form->type == 'x' || form->type == 'X' || form->type == 'o' ||
		form->type == 'O')
		ft_arg_x_o(ap, form);
	if (form->type == 'p')
		ft_arg_p(ap, form);;
}
