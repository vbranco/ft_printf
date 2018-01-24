/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_convert_base.c                                .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 20:30:35 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 20:32:07 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

//j'ai des fuites de memoire dans une de ces fonctions.

static char	*ft_modif(int nb, t_form *form)
{
	char	c;
	char	*str;

	str = ft_memalloc(2);
	if (nb >= 10 && form->type == 'X')
		c = 'A' + (nb - 10);
	else
		c = 'a' + (nb - 10);
	str[0] = c;
	return (str);
}

void		ft_convert_base(long nb, int base, t_form *form, char **str)
{
	char	*tmp;
	long	reste;
	long	limit;

	tmp = ft_memalloc(17);
	limit = 8;
	base == 16 ? (limit = 9) : 0;
	while (nb > base)
	{
		reste = nb % base;
		nb /= base;
		if (reste > limit)
			tmp = ft_strcat(tmp, ft_modif(reste, form));
		else
			tmp = ft_strcat(tmp, ft_itoa(reste));
	}
	if (nb > limit)
		tmp = ft_strcat(tmp, ft_modif(nb, form));
	else
		tmp = ft_strcat(tmp, ft_itoa(nb));
	tmp = ft_reverse(tmp);
	ft_strcat(*(str), tmp);
	free(tmp);
}
