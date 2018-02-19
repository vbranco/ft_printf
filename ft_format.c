/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_format.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 17:22:45 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 17:49:04 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_format(const char *format, va_list ap, int *size, t_form *form)
{
	int		len;

	len = 0;
	ft_init_struct(form);
	if ((len = ft_percent(format, form)) != 0)
	{
		*size = form->size;
		return (len);
	}
	ft_init_struct(form);
	if (*format == '%')
	{
		format++;
		ft_recup_type(format, form);
		ft_recup_length(format, form);
		ft_recup_min(format, form);
		ft_recup_prec(format, form);
		ft_recup_flag(format, form);
		if ((len = (ft_args(form, ap))) == -1)
			return (-1);
		*size = form->size;
	}
	return (len);
}
