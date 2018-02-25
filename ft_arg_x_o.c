/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_arg_x_o.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 20:28:25 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 19:37:53 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_size_nbo2(uintmax_t nb, t_form *form)
{
	int		size;
	int		div;

	size = 0;
	if (form->type == 'o')
		div = 8;
	else
		div = 10;
	while (nb > 9)
	{
		size++;
		nb /= div;
	}
	return (size + 1);
}

int		ft_arg_x_o(va_list ap, t_form *form)
{
	uintmax_t	nb2;
	char		*str;
	int		len;

	if (form->type == 'x' || form->type == 'X')
	{
		if (form->length == 'h' && form->elength == 'h')
			nb2 = (unsigned char)va_arg(ap, int);
		else if (form->length == 'h' && form->elength == '\0')
			nb2 = (short unsigned int)va_arg(ap, long);
		else if (form->length == 'j' && form->elength == '\0')
			nb2 = (uintmax_t)va_arg(ap, uintmax_t);
		else if (form->length == 'l' && form->elength == '\0')
			nb2 = (unsigned long)va_arg(ap, long long);
		else if (form->length == 'l' && form->elength == 'l')
			nb2 = (unsigned long long)va_arg(ap, unsigned long long);
		else if (form->length == 'z' && form->elength == '\0')
			nb2 = (size_t)va_arg(ap, size_t);
		else
			nb2 = (unsigned int)va_arg(ap, long);
	}
	else
	{
		if (form->length == 'h' && form->elength == 'h' && form->type == 'o')
			nb2 = (unsigned char)va_arg(ap, int);
		else if (form->length == 'h' && form->elength == '\0')
			nb2 = (short unsigned int)va_arg(ap, long);
		else if (form->length == 'j' && form->elength == '\0')
			nb2 = (uintmax_t)va_arg(ap, uintmax_t);
		else if (form->length == 'l' && form->elength == '\0')
			nb2 = (unsigned long)va_arg(ap, long long);
		else if ((form->length == 'l' && form->elength == 'l') || form->type == 'O')
			nb2 = (unsigned long long)va_arg(ap, unsigned long long);
		else if (form->length == 'z' && form->elength == '\0')
			nb2 = (size_t)va_arg(ap, size_t);
		else
			nb2 = (unsigned int)va_arg(ap, long);
	}
	str = ft_memalloc(ft_size_nbo2(nb2, form) + form->min + form->prec + 2);
	if (form->type == 'x' || form->type == 'X')
		ft_convert_base_uintmax(nb2, 16, form, str);
	else
		ft_convert_base_uintmax(nb2, 8, form, str);
	ft_buffer_x_o(str, form);
	write(1, form->buf, ft_strlen(form->buf));
	free(form->buf);
	form->buf = NULL;
	len = write(1, str,ft_strlen(str));
	free(str);
	return (len);
}
