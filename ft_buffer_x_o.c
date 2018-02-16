/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_buffer_x_o.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/08 16:53:24 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/16 17:06:52 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

//probleme sur buffer

static void	ft_h(char *str, char *s1, t_form *form)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
//	printf("\nlen : %d\n", len);
/*	if (form->prec > len)
	{
		ft_add_str_begin(str, ft_memset(s1, '0', (form->prec - len)));
	}
*/	if (form->type == 'o' || form->type == 'O')
	{
		if (form->prec > len)
			ft_add_str_begin(str, ft_memset(s1, '0', (form->prec - len)));
		ft_add_str_begin(str, "0");
	}
	else if (form->type == 'x')
	{
		if (form->prec > len)
			ft_add_str_begin(str, ft_memset(s1, '0', (form->prec - len)));
		ft_add_str_begin(str, "0x");
	}
	else if (form->type == 'X')
	{
		if (form->prec > len)
			ft_add_str_begin(str, ft_memset(s1, '0', (form->prec - len)));
		ft_add_str_begin(str, "0X");
	}
}

void	ft_buffer_x_o(char *str, t_form *form)
{
	int		len;
	char	*s1;

	s1 = ft_memalloc(form->min);
	if (form->prec == 0 && str[0] == '0')
	{
		if (form->is_h == 1 && (form->type == 'o' || form->type == 'O'))
			str[0] = '0';
		else
			str[0] = '\0';
	}
	if (form->is_h == 1 && str[0] != '0' && str[0] != '\0')
		ft_h(str, s1, form);
	ft_precision(str, form);
	len = ft_strlen(str);
	if (form->min > len)
	{
		if (form->is_n == 1)
		{
		//	printf("1\n");
			ft_add_str_end(str, ft_memset(s1, ' ', (form->min - len)));
		}
		else if ((form->is_z == 1 && form->min > form->prec))
		{
		//	printf("2\n");
			ft_add_str_begin(str, ft_memset(s1, '0', (form->min - len)));
		}
		else if (form->is_n == 0)
		{
		//	printf("3\n");
			ft_add_str_begin(str, ft_memset(s1, ' ', (form->min - len)));
		}
	}
//	if (form->is_h == 1)
//		ft_h(str, form);
	free(s1);
}
