/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_precision.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/08 16:51:53 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/10 11:43:32 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_precision(char *str, t_form *form)
{
	int		len;
	char	*s1;
	int		i;

	i = 0;
	len = ft_strlen(str);
	s1 = ft_memalloc(form->prec - len);
	if (form->prec > len)
	{
		ft_add_str_begin(str, ft_memset(s1, '0', (form->prec - len)));
	}
	else
	{
//		ft_putstr("ICI!!");
//		ft_putstr("JE!!");
//		s1 = ft_memalloc(len - form->prec);
//		ft_add_str_begin(str, ft_memset(s1, ' ', (len - form->prec)));
		while ((i < (len - form->prec)) && form->prec > -1)
		{
			str[i] = ' ';
			i++;
		}
	}
	free(s1);
	return (ft_strlen(str));
}
