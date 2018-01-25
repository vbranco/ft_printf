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

	str = ft_memalloc(20);
	ptr = va_arg(ap, void*);
	nb = (long)ptr;
	ft_convert_base(nb, 16, form, str);
	ft_add_str_begin(str, "0x");
	write(1, str, ft_strlen(str));
	free(str);
	return (ft_strlen(str));
}
