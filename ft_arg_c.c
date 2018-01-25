/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_arg_c.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 19:22:22 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 20:30:15 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_arg_c(va_list ap, t_form *form)
{
	char	c;
	char	*str;
	wchar_t	ca;

	str = ft_memalloc(5);
	if (form->type == 'c' || (form->type == 'C' && form->length == 'h'))
	{
		c = (char)va_arg(ap, int);
		str[0] = c;
	}
	if (form->type == 'C' || (form->type == 'c' && form->length == 'l'))
	{
		ca = (wchar_t)va_arg(ap, wint_t);
		ft_wchar(ca, str);
	}
	write(1, str, ft_strlen(str));
	free(str);
	return (ft_strlen(str));
}
