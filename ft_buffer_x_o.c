/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_buffer_x_o.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/08 16:53:24 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/10 14:43:50 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

//probleme sur buffer

static void	ft_h(char *str, t_form *form)
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
}

void	ft_buffer_x_o(char *str, t_form *form)
{
	int		len;
	char	*s1;

	s1 = ft_memalloc(form->min);
	if (form->is_h == 1)
		ft_h(str, form);
	ft_precision(str, form);
	len = ft_strlen(str);
	if (form->min > len)
	{
		if (form->is_n == 1)
		{
			printf("1\n");
			ft_add_str_end(str, ft_memset(s1, ' ', (form->min - len)));
		}
		else if ((form->is_z == 1 && form->prec > form->min))// || form->prec < 0)
		{
			printf("2\n");
			ft_add_str_begin(str, ft_memset(s1, '0', (form->min - len)));
		}
		else if (form->is_n == 0)
		{
			printf("3\n");
			ft_add_str_begin(str, ft_memset(s1, ' ', (form->min - len)));
		}
	}
	free(s1);
}
