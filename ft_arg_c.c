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

char	*ft_arg_c(va_list ap, t_form *form)
{
	char	c;
	char	*str;

	if (form->type == 'c')
	{
		str = ft_memalloc(2);
		c = (char) va_arg(ap, int);
		str[0] = c;
		return (str);
	}
	if (form->type == 'C')
	{
	}
}
