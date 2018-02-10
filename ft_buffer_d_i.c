/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_buffer_d_i.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/08 16:54:27 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/10 16:33:19 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_neg(char *str, t_form *form)
{
	char	c;
	int		i;
	int		len;
	char	*s1;

	s1 = ft_memalloc(form->min);
	i = 0;
	c = str[0];
	while (str[i])
	{
		str[i] = str[i +  1];
		i++;
	}
	len = ft_strlen(str);
	if (form->prec > len)
		len = ft_precision(str, form);
	while (len > 0)
	{
		str[len] = str[len - 1];
		len--;
	}
	str[0] = c;
	len = ft_strlen(str);
	if (form->min > len)
	{
		if (form->is_n == 1)
			ft_add_str_end(str, ft_memset(s1, ' ', (form->min - len)));
		else if (form->is_z == 1)
			ft_add_str_begin(str, ft_memset(s1, '0', (form->min - len)));
		else if (form->is_n == 0)
			ft_add_str_begin(str, ft_memset(s1, ' ', (form->min - len)));
	}
}

void		ft_buffer_d_i(char *str, t_form *form)
{
	char	*s1;
	int		len;

	len = ft_strlen(str);
	s1 = ft_memalloc(form->min);
	if (*str == '-')
		ft_neg(str, form);
	else
	{
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
				ft_add_str_end(str, ft_memset(s1, ' ', (form->min - len)));
			else if (form->is_z == 1)
				ft_add_str_begin(str, ft_memset(s1, '0', (form->min - len)));
			else if (form->is_n == 0)
				ft_add_str_begin(str, ft_memset(s1, ' ', (form->min - len)));
		}
	}
	if (form->is_s == 1)
		ft_add_str_begin(str, " ");
	free(s1);
}
