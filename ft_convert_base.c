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

/*static void	ft_my_itoa(int nb, char *tmp)
{
	char	*s;
	size_t	i;

	i = 0;
	s = ft_memalloc(ft_size_nb(nb) + 1);
	if (nb < 0)
	{
		s[i] = '-';
		nb = nb * -1;
		i++;
	}
	while (nb > 9)
	{
		s[i] = ((nb % 10) + '0');
		nb /= 10;
		i++;
	}
	s[i] = ((nb % 10) + '0');
	s = ft_reverse(s);
	ft_strcat(tmp, s);
	free(s);
}*/

static void	ft_modif(int nb, char *tmp, t_form *form)
{
	char	c;
	char	*s;

	s = ft_memalloc(2);
	if (nb >= 10 && form->type == 'X')
		c = 'A' + (nb - 10);
	else
		c = 'a' + (nb - 10);
	s[0] = c;
	ft_strcat(tmp, s);
	free(s);
}

void		ft_convert_base(long nb, int base, t_form *form, char *str)
{
	char	*tmp;
	long	reste;
	long	limit;

	tmp = ft_memalloc(100);
	limit = 8;
	base == 16 ? (limit = 9) : 0;
	while (nb > base)
	{
		reste = nb % base;
		nb /= base;
		if (reste > limit)
			ft_modif(reste, tmp, form);
		else
			ft_my_itoa(reste, tmp);
	}
	if (nb > limit)
		ft_modif(nb, tmp, form);
	else
		ft_my_itoa(nb, tmp);
	tmp = ft_reverse(tmp);
	ft_strcat(str, tmp);
	free(tmp);
}
