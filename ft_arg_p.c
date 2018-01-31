/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_arg_p.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 20:26:50 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 20:27:27 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_arg_p(va_list ap, t_form *form)
{
	char	*str;
	void	*ptr;
	long	nb;

	ptr = va_arg(ap, void*);
	nb = (long)ptr;
	str = ft_memalloc(ft_size_nb(nb) + form->min + 1);
	ft_convert_base(nb, 16, form, str);
	ft_add_str_begin(str, "0x");
	ft_buffer_p_c_s(str, form);
	write(1, str, ft_strlen(str));
	free(str);
	return (ft_strlen(str));
}
