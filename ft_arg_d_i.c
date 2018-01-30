/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_arg_d_i.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 19:45:58 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 20:28:15 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_arg_d_i(va_list ap, t_form *form)
{
	int				nb;
	unsigned int	nb2;
	char			*str;

	if (form->type == 'd' || form->type == 'i' || form->type == 'D')
	{
		nb = va_arg(ap, int);
		str = ft_memalloc(ft_size_nb(nb) + form->min + 1);
		ft_my_itoa(nb, str);
		ft_buffer_d(str, form);
	}
	else
	{
		nb2 = va_arg(ap, unsigned int);
		str = ft_memalloc(ft_size_nb(nb2) + form->min + 1);
		ft_my_itoa(nb2, str);
		ft_buffer_d(str, form);
	}
	write(1, str, ft_strlen(str));
	free(str);
	return (ft_strlen(str));
}
