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

static int	ft_size_nbo(intmax_t nb, t_form *form)
{
	int		size;
	int		div;

	size = 0;
	if (nb < 0)
	{
		nb = nb * -1;
		size++;
	}
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

/*static int	ft_checkmax(t_form *form, long max)
{
	if ((form->type == 'x' || form->type == 'X') && form->length == '\0' && )
		return (write(1, "0", 1));
}*/

int		ft_arg_x_o(va_list ap, t_form *form)
{
	intmax_t	nb;
	uintmax_t	nb2;
	char		*str;
	long		max;
	int		len;

	max = 4294967295;
//	ft_checkmax(form, max);
	if (((form->type == 'o' || form->type == 'X' || form->type == 'x') && (form->elength == 'l' || form->length == 'j' || form->length == 'z')) || ((form->type == 'x' || form->type == 'o' || form->type == 'X') && form->length == 'l'))
	{
		nb2 = (unsigned long long)va_arg(ap, unsigned long long);
		str = ft_memalloc(ft_size_nbo2(nb2, form) + form->min + form->prec + 2);
	}
	else
	{
		nb = (long long)va_arg(ap, long long);
		str = ft_memalloc(ft_size_nbo(nb, form) + form->min + form->prec + 2);
	}
	if (form->elength == 'l' || form->length == 'j' || form->length == 'z' || form->length == 'l')
	{
		if (nb2 > (uintmax_t)max)
		{
			if (form->type == 'x' || form->type == 'X')
				ft_convert_base_uintmax(nb2, 16, form, str);
			else
				ft_convert_base_uintmax(nb2, 8, form, str);
		}
		else
		{
			if (form->type == 'x' || form->type == 'X')
				ft_convert_base_uintmax(nb2, 16, form, str);
			else
				ft_convert_base_uintmax(nb2, 8, form, str);
		}
	}
	else
	{
		if (nb > max && ((form->type == 'x' || form->type == 'X') && (form->length == '\0' || form->length == 'h' || form->elength == 'h')))
			return (write(1, "0", 1));
		if (nb < 0 || nb > max)
		{
			if (form->type == 'x' || form->type == 'X')
				ft_convert_base_intmax(nb, 16, form, str);
		}
		else if (nb >= 0)
		{
			if (form->type == 'x' || form->type == 'X')
				ft_convert_base_intmax(nb, 16, form, str);
			else
				ft_convert_base_intmax(nb, 8, form, str);
		}
	}
	ft_buffer_x_o(str, form);
	write(1, form->buf, ft_strlen(form->buf));
	free(form->buf);
	form->buf = NULL;
	len = write(1, str,ft_strlen(str));
	free(str);
	return (len);
}
