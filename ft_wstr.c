/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wstr.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 18:44:46 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/09 19:48:05 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_wstr(wchar_t *wstr, char *str, t_form *form)
{
	size_t	i;
	char	*tmp;
	int		prec;

	prec = form->prec;
	i = 0;
	while (wstr[i])
	{
		tmp = ft_memalloc(65);
		if ((ft_wchar(wstr[i], tmp)) == -1)
			return (-1);
		if ((int)ft_strlen(tmp) > prec && prec > -1)
		{
			ft_strcat(str, "\0");
			break;
		}
		else
			ft_strcat(str, tmp);
		prec--;
		i++;
		free(tmp);
	}
	return (0);
}
