/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_buffer_x_o.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/08 16:53:24 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/10 12:21:26 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

//probleme sur buffer

static void	ft_h(char *str, t_form *form)
{
	if (form->is_h == 1)
	{
		if (ft_atoi(str) != 0)
		{
			if (form->type == 'o')
				ft_add_str_begin(str, "0");
			else if (form->type == 'x')
				ft_add_str_begin(str, "0x");
			else
				ft_add_str_begin(str, "0X");
		}
		else if (ft_atoi(str) == 0)
			ft_add_str_begin(str, " ");
	}
}

void	ft_buffer_x_o(char *str, t_form *form)
{
	int		len;
	char	*s1;

//	printf("je suis H : %d\n", form->is_h);
	s1 = ft_memalloc(form->min);
	ft_h(str, form);
/*	if (form->is_h == 1 && (ft_atoi(str) != 0))
	{
		if (form->type == 'o')
			ft_add_str_begin(str, "0");
		else if (form->type == 'x')
			ft_add_str_begin(str, "0x");
		else
			ft_add_str_begin(str, "0X");
	}
*/	ft_precision(str, form);
	len = ft_strlen(str);
	if (form->min > len)
	{
	//	ft_putstr("ICI!!");
		if (form->is_n == 1)
			ft_add_str_end(str, ft_memset(s1, ' ', (form->min - len)));
		else if ((form->is_z == 1 && form->prec > form->min) || form->prec < 0)
			ft_add_str_begin(str, ft_memset(s1, '0', (form->min - len)));
		else if (form->is_n == 0)
			ft_add_str_begin(str, ft_memset(s1, ' ', (form->min - len)));
	}
	free(s1);
}
