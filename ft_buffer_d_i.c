/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_buffer_d_i.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/08 16:54:27 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/10 15:53:57 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_buffer_d_i(char *str, t_form *form)
{
	char	*s1;
	int		len;

	len = ft_strlen(str);
	s1 = ft_memalloc(form->min);
	if (form->prec > len)
		len = ft_precision(str, form);
	if (form->is_p == 1 && *str != '-')
	{
		ft_add_str_begin(str, "+");
		len++;
	}
	if (form->min > len)
	{
		if (form->is_n == 1)
			ft_add_str_end(str, ft_memset(s1, ' ',
			(form->min - len)));
		else if (form->is_z == 1)
			ft_add_str_begin(str, ft_memset(s1, '0',
			(form->min - len)));
		else if (form->is_n == 0)
			ft_add_str_begin(str, ft_memset(s1, ' ',
			(form->min - len)));
	}
	if (form->is_s == 1)
		ft_add_str_begin(str, " ");
	free(s1);
}
