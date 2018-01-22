/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_arg_d_i.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 19:45:58 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/17 19:51:35 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_arg_d_i(va_list ap, t_form *form)
{
	int		nb;
	unsigned int	nb2;
	char	*str;

	if (form->type == 'd' || form->type == 'i' || form->type == 'D')
	{
		nb = va_arg(ap, int);
		str = ft_itoa(nb);
	}
	else if (form->type == 'u' || form->type == 'U')
	{
		nb2 = va_arg(ap, unsigned int);
		str = ft_itoa(nb2);
	}
}
