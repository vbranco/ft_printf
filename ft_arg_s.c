/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_arg_s.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 19:51:43 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 20:26:44 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_arg_s(va_list ap, t_form *form)
{
	char	*str;
	wchar_t	*wstr;
	int		size;

	if (form->type == 's' || (form->type == 'S' && form->length == 'h'))
	{
		str = va_arg(ap, char*);
		write(1, str, ft_strlen(str));
	}
	else
	{
		wstr = va_arg(ap, wchar_t*);
		size = ft_count_size(wstr);
		str = ft_memalloc(size + 1);
		ft_wstr(wstr, str);
		write(1, str, ft_strlen(str));
		free(str);
	}
}
