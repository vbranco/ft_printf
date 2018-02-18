/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_arg_c.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 19:22:22 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 18:32:40 by vbranco     ###    #+. /#+    ###.fr     */
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
	if ((form->type == 'c' && form->length == '\0') || (form->type == 'C' && form->length == 'h'))
	{
		c = (char)va_arg(ap, int);
		str[0] = c;
	}
	if ((form->type == 'C' && form->length == '\0') || (form->type == 'c' && form->length == 'l'))
	{
		ca = (wchar_t)va_arg(ap, wint_t);
		if ((ft_wchar(ca, str)) == -1)
		{
			free(str);
			return (-1);
		}
	}
	ft_buffer_p_c_s(str, form);
	write(1, form->buf, ft_strlen(form->buf));
	free(form->buf);
	form->buf = NULL;
	if (str[0] == '\0' || str[0] == 0)
		len = write(1, "\0", 1);
	else
		len = write (1, str, ft_strlen(str));
	free(str);
	return (len);
}
