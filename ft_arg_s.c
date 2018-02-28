/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_arg_s.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/17 19:51:43 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/28 19:45:50 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_print(char *str, t_form *form)
{
	int		len;

	len = 0;
	ft_buffer_s(str, form);
	write(1, form->buf, ft_strlen(form->buf));
	free(form->buf);
	form->buf = NULL;
	len = write(1, str, ft_strlen(str));
	free(str);
	return (len);
}

static int	ft_verif(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] > 126)
			return (0);
		i++;
	}
	return (1);
}

int			ft_arg_s(va_list ap, t_form *form)
{
	char	*str;
	char	*tmp;
	wchar_t	*wstr;

	if ((form->type == 's' && form->length == '\0') || (form->type == 'S' &&
				form->length == 'h' && form->elength == '\0'))
	{
		tmp = va_arg(ap, char*);
		if (tmp == NULL)
		{
			str = ft_memalloc(7);
			ft_add_str_begin(str, "(null)");
		}
		else
		{
			str = ft_memalloc(ft_strlen(tmp) + form->min + form->prec + 2);
			if (ft_verif(tmp) == 0)
			{
				free(str);
				return (-1);
			}
			else
				ft_strcat(str, tmp);
		}
	}
	else
	{
		wstr = va_arg(ap, wchar_t*);
		if (wstr == NULL)
		{
			str = ft_memalloc(7);
			ft_add_str_begin(str, "(null)");
		}
		else
		{
			str = ft_memalloc(ft_count_size(wstr) + form->min + 1);
			if ((ft_wstr(wstr, str, form)) == -1)
			{
				free(str);
				return (-1);
			}
		}
	}
	return (ft_print(str, form));
}

ft_2(char *str

free(str);

ft_1()
char *str

ft_(str)
free(str);
