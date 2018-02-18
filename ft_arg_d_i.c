/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_arg_d_i.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 19:45:58 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 20:18:31 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_arg_d_i(va_list ap, t_form *form)
{
	intmax_t			nb;
	uintmax_t			nb2;
	char				*str;
	int					len;

	if ((form->type == 'd' || form->type == 'i') && form->length != 'l' &&
			form->elength != 'l')
	{
		nb = (int)va_arg(ap, int);
		str = ft_memalloc(ft_size_nb(nb) + form->min + form->prec + 2);
		ft_my_itoa(nb, str);
	}
	else if ((form->type == 'u' && (form->length == 'z' || (form->length == 'l' && form->elength == 'l'))))
	{
		nb2 = (unsigned long long)va_arg(ap, unsigned long long);
		str = ft_memalloc(ft_size_nb2(nb2) + form->min + form->prec + 2);
		ft_my_itoa2(nb2, str);
	}
	else if (form->type == 'u' && form->length == 'l')
	{
		nb2 = (unsigned long)va_arg(ap, unsigned long);
		str = ft_memalloc(ft_size_nb2(nb2) + form->min + form->prec + 2);
		ft_my_itoa2(nb2, str);
	}
	else
	{
		nb = (long long)va_arg(ap, long long);
		str = ft_memalloc(ft_size_nb(nb) + form->min + form->prec + 2);
		ft_my_itoa(nb, str);
	}
	ft_buffer_d_i(str, form);
	write(1, form->buf, ft_strlen(form->buf));
	free(form->buf);
	form->buf = NULL;
	len = write(1, str, ft_strlen(str));
	free(str);
	return (len);
}
