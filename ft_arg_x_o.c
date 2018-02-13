/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_arg_x_o.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 20:28:25 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/10 14:43:55 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_arg_x_o(va_list ap, t_form *form)
{
	intmax_t	nb;
	uintmax_t	nb2;
	char		*str;
	long		max;
	int		len;

	max = 4294967295;
	if (form->type == 'o' && (form->elength == 'l' || form->length == 'j'))
	{
		nb2 = (unsigned long long)va_arg(ap, unsigned long long);
		str = ft_memalloc(ft_size_nb2(nb2) + form->min + form->prec + 2);
		printf("i : %d\n", (ft_size_nb2(nb2)));// + form->min + form->prec + 2));
//		printf("nb2 : %jo\n", nb2);
	}
	else
	{
		nb = (long long)va_arg(ap, long long);
		str = ft_memalloc(ft_size_nb(nb) + form->min + form->prec + 2);
		printf("i : %d\n", (ft_size_nb(nb) + form->min + form->prec + 2));
//		printf("nb : %jo\n", nb);
	}
	if (form->elength == 'l' || form->length == 'j')
	{
		if (nb2 > (uintmax_t) max)
		{
			if (form->type == 'x' || form->type == 'X')
				ft_convert_base(nb2, 16, form, str);
			else
				ft_convert_base(nb2, 8, form, str);
		}
		else// if (nb2 >= 0)
		{
//			printf("ici\n");
			if (form->type == 'x' || form->type == 'X')
				ft_convert_base(nb2, 16, form, str);
			else
				ft_convert_base(nb2, 8, form, str);
		}
	}
	else
	{
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
	}
	ft_buffer_x_o(str, form);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}
