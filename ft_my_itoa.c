/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_my_itoa.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/08 16:50:10 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/08 16:50:32 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_my_itoa(int nb, char *tmp)
{
	char	*s;
	size_t	i;
	long	n;

	i = 0;
	n = nb;
	s = ft_memalloc(ft_size_nb(n) + 1);
	if (n < 0)
	{
		s[i] = '-';
		n = n * -1;
		i++;
	}
	while (n > 9)
	{
		s[i] = ((n % 10) + '0');
		n /= 10;
		i++;
	}
	s[i] = ((n % 10) + '0');
	s = ft_reverse(s);
	ft_strcat(tmp, s);
	free(s);
}
