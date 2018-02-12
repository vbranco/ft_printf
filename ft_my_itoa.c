/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_my_itoa.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/08 16:50:10 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 19:40:06 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_my_itoa(intmax_t nb, char *tmp)
{
	char		*s;
	size_t		i;

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
}
