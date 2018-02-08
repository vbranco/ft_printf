/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wstr.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 18:44:46 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/08 16:46:30 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void		ft_wstr(wchar_t *wstr, char *str, t_form *form)
{
	size_t	i;
	char	*tmp;
	int		prec;

	prec = form->prec;
	i = 0;
	while (wstr[i] && prec >= 0)
	{
		tmp = ft_memalloc(65);
		ft_wchar(wstr[i], tmp);
		if ((int)ft_strlen(tmp) > prec)
			ft_strcat(str, "\0");
		else
			ft_strcat(str, tmp);
		prec--;
		i++;
		free(tmp);
	}
}
