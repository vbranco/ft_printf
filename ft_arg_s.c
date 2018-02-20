/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_arg_s.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 19:51:43 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 19:18:47 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_arg_s(va_list ap, t_form *form)
{
	char	*str;
	char	*tmp;
	wchar_t	*wstr;
	int		len = 0;

	if ((form->type == 's' && form->length == '\0') || (form->type == 'S' &&
				form->length == 'h'))
	{
		tmp = va_arg(ap, char*);
		if (tmp == NULL)
		{
			str = ft_memalloc(7);
			ft_add_str_begin(str, "(null)");
		}
		else
		{
			str = ft_memalloc(ft_strlen(tmp));
			ft_strcat(str, tmp);
		}
	}
	else
	{
		wstr = va_arg(ap, wchar_t*);
		str = ft_memalloc(ft_count_size(wstr) + form->min + 1);
		if ((ft_wstr(wstr, str, form)) == -1)
		{
			free(str);
			return (-1);
		}
	}
	ft_buffer_p_s(str, form);
	write(1, form->buf, ft_strlen(form->buf));
	free(form->buf);
	form->buf = NULL;
	len = write(1, str, ft_strlen(str));
	free(str);//ceci deconne sur teste mixed
	return (len);
}
