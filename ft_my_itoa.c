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

#include <stdio.h>

void	ft_my_itoa(intmax_t nb, char *tmp)
{
	uintmax_t	n;
	char		*s;
	size_t		i;

	i = 0;
	n = (uintmax_t)nb;
	s = ft_memalloc(ft_size_nb2(nb) + 1);
	if (nb < 0 && nb < -9223372036854775807)
	{
		if (nb < 0)
		{
			s[i] = '-';
			i++;
		}
		while (n > 9)
		{
			s[i] = ((n % 10) + '0');
			n /= 10;
			i++;
		}
		s[i] = ((n % 10) + '0');
	}
	else
	{
		if (nb < 0)
		{
			s[i] = '-';
			nb *= -1;
			i++;
		}
		while (nb > 9)
		{
			s[i] = ((nb % 10) + '0');
			nb /= 10;
			i++;
		}
		s[i] = ((nb % 10) + '0');
	}
	s = ft_reverse(s);
	ft_strcat(tmp, s);
	free(s);
}
