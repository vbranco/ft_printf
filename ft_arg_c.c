/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_arg_c.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 19:22:22 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/08 16:57:56 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_arg_c(va_list ap, t_form *form)
{
	char	c;
	char	*str;
	wchar_t	ca;
	int		len;

	str = ft_memalloc(4 + form->min + 1);
	if (form->type == 'c' || (form->type == 'C' && form->length == 'h'))
	{
		c = (char)va_arg(ap, int);
		str[0] = c;
	}
	if (form->type == 'C' || (form->type == 'c' && form->length == 'l'))
	{
//		printf("ici\n");
		ca = (wchar_t)va_arg(ap, wint_t);
		ft_wchar(ca, str);
	}
	ft_buffer_p_c_s(str, form);
	if (str[0] == '\0')
		len = 1;
	else
		len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}
