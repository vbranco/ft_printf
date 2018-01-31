/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_arg_x_o.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 20:28:25 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 20:28:37 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_arg_x_o(va_list ap, t_form *form)
{
	long		nb;
	char		*str;
	long		max;

	max = 4294967295;
	nb = va_arg(ap, long);
	str = ft_memalloc(ft_size_nb(nb) + form->min + 1);
	if (nb < 0 || nb > max)
	{
		if (form->type == 'x' || form->type == 'X')
			ft_convert_base(nb, 16, form, str);
	}
	else if (nb >= 0)
	{
		if (form->type == 'x' || form->type == 'X')
			ft_convert_base(nb, 16, form, str);
		else
			ft_convert_base(nb, 8, form, str);
	}
	ft_buffer_x_o(str, form);
	write(1, str, ft_strlen(str));
	free(str);
	return (ft_strlen(str));
}
