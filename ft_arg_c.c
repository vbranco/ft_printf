/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_arg_c.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 19:22:22 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 20:00:04 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_test(t_form *form)
{
	if ((form->type == 'c' && form->length == '\0') || (form->type == 'C' &&
				form->length == 'h'))
		return (1);
	else if ((form->type == 'C' && form->length == '\0') || (form->type == 'c'
				&& form->length == 'l'))
		return (2);
	return (0);
}

int			ft_arg_c(va_list ap, t_form *form)
{
	char	c;
	char	*str;
	wchar_t	ca;
	int		len;

	str = ft_memalloc(4 + form->min + 1);
	if (ft_test(form) == 1)
	{
		c = (char)va_arg(ap, int);
		str[0] = c;
	}
	if (ft_test(form) == 2)
	{
		ca = (wchar_t)va_arg(ap, wint_t);
		if ((ft_wchar(ca, str)) == -1)
		{
			free(str);
			return (-1);
		}
	}
	write(1, form->buf, ft_strlen(form->buf));
	free(form->buf);
	form->buf = NULL;
	len = ft_buffer_c(str, form);
	write(1, str, ft_strlen(str));
	if (form->zero == 1)
		write(1, "\0", 1);
	free(str);
	return (len);
}
