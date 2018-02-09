/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_arg_s.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 19:51:43 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/09 19:48:24 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_arg_s(va_list ap, t_form *form)
{
	char	*str;
	char	*tmp;
	wchar_t	*wstr;
	int		len;

	if ((form->type == 's' && form->length == '\0') || (form->type == 'S' &&
				form->length == 'h'))
	{
		tmp = va_arg(ap, char*);
		str = ft_memalloc(ft_strlen(tmp));
		ft_strcat(str, tmp);
	}
	else
	{
		wstr = va_arg(ap, wchar_t*);
		str = ft_memalloc(ft_count_size(wstr) + form->min + 1);
		ft_wstr(wstr, str, form);
	}
	ft_buffer_p_c_s(str, form);
	len = ft_strlen(str);
	write(1, str, len);
	free(str);
	return (len);
}
