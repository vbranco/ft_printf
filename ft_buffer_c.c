/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_buffer_c.c                                    .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/19 19:34:32 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 20:00:06 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_buffer_c(char *str, t_form *form)
{
	int		len;
	char	*s1;
	int		ln;

	len = ft_strlen(str);
	s1 = ft_memalloc(form->min);
	ln = 0;
	if (form->is_n == 1 && form->min > len)
	{
		if (str[0] == '\0')
			ln = write(1, "\0", 1);
		ft_add_str_end(str, ft_memset(s1, ' ', (form->min - len - ln)));
	}
	else if (form->is_n == 0 && form->min > len)
	{
		if (str[0] == '\0')
		{
			form->zero = 1;
			ln++;
			ft_add_str_begin(str, ft_memset(s1, ' ', (form->min - len - ln)));
		}
		else
			ft_add_str_begin(str, ft_memset(s1, ' ', (form->min - len)));
	}
	else if (str[0] == '\0')
		ln = write(1, "\0", 1);
	return (ft_strlen(str) + ln);
}
