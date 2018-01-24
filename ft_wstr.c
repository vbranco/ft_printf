/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wstr.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 18:44:46 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 20:24:26 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_wstr(wchar_t *wstr, char *str)
{
	size_t	i;
	char	*tmp;

	i = 0;
	while (wstr[i])
	{
		tmp = ft_memalloc(65);
		ft_wchar(wstr[i], tmp);
		ft_strcat(str, tmp);
		i++;
		free(tmp);
	}
}
