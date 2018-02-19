/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_arg_p.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 20:26:50 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 19:42:08 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_arg_p(va_list ap, t_form *form)
{
	char		*str;
	void		*ptr;
	uintmax_t	nb;
	int			len;

	ptr = va_arg(ap, void*);
	nb = (long)ptr;
	str = ft_memalloc(ft_size_nb(nb) + form->min + 1);
	ft_convert_base_uintmax(nb, 16, form, str);
	ft_add_str_begin(str, "0x");
	ft_buffer_p_s(str, form);
	len = ft_strlen(str);
	write(1, form->buf, ft_strlen(form->buf));
	free(form->buf);
	form->buf = NULL;
	write(1, str, len);
	free(str);
	return (len);
}
