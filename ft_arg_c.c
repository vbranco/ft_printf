/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_arg_c.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 19:22:22 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/17 19:45:45 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_arg_c(va_list ap, t_form *form)
{
	char	c;
	char	*str;
	long	nb;
	char	*mask;

	str = ft_memalloc(2000);
	mask = ft_memalloc(65);
	if (form->type == 'c' || (form->type == 'C' && form->length == 'h'))
	{
		str = ft_memalloc(2);
		c = (char) va_arg(ap, int);
		str[0] = c;
	}
	if (form->type == 'C' || (form->type == 'c' && form->length == 'l'))
	{
		nb = va_arg(ap, long);
//		ft_putnbr(nb);
//		ft_convert_base(nb, 16, form, &str);
		ft_get_bit(nb, &str, &mask);
	}
//	write(1, str, ft_strlen(str));
	free(str);
	free(mask);
}
