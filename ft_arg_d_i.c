/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_arg_d_i.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 19:45:58 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/10 16:33:20 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_arg_d_i(va_list ap, t_form *form)
{
	int				nb;
	long long		nb2;
	char			*str;
	int				len;

	if ((form->type == 'd' || form->type == 'i') && form->length != 'l' &&
			form->elength != 'l')
	{
		nb = va_arg(ap, int);
		str = ft_memalloc(ft_size_nb(nb) + form->min + form->prec + 2);
		ft_my_itoa(nb, str);
	}
	else
	{
		nb2 = va_arg(ap, long long);
		str = ft_memalloc(ft_size_nb(nb2) + form->min + form->prec + 2);
		ft_my_itoa(nb2, str);
	}
	ft_buffer_d_i(str, form);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}
