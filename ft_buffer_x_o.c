/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_buffer_x_o.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/08 16:53:24 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/14 20:29:32 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

//probleme sur buffer

static void	ft_h(char *str, t_form *form)
{
	if (str[0] != '0')
	{
		if (form->type == 'o' || form->type == 'O')
			ft_add_str_begin(str, "0");
		else if (form->type == 'x')
			ft_add_str_begin(str, "0x");
		else if (form->type == 'X')
			ft_add_str_begin(str, "0X");
	}
}

void	ft_buffer_x_o(char *str, t_form *form)
{
	int		len;
	char	*s1;

//manque gerer les largueurs de champ avec l'ajout de "0x"
//avec l'ajout de "0x" ca me fait perdre 2 cases en len.
//je pense aussi que je ne gere pas bien les priorites entre le min et prec

	s1 = ft_memalloc(form->min);
	if (form->is_h == 1)
		ft_h(str, form);
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
	free(s1);
}
