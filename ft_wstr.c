/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wstr.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 18:44:46 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 20:02:03 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_wstr(wchar_t *wstr, char *str)
{
	size_t	i;
	char	*tmp;

//	ft_putendl("la");
	tmp = ft_memalloc(50);
	i = 0;
	while (wstr[i])
	{
		ft_putendl("la");
		ft_putendl("la");
		ft_wchar(wstr[i], tmp);
		ft_strjoin(str, tmp);
		i++;
	}
}
