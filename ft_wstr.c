/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wstr.c                                        .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 18:44:46 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/28 19:09:22 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_size(wchar_t c)
{
	if (c <= 127)
		return (1);
	else if (c < 0x800)
		return (2);
	else if (c < 0x10000)
		return (3);
	else
		return (4);
}

int		ft_wstr(wchar_t *wstr, char *str, t_form *form)
{
	size_t	i;
	char	*tmp;
	int		prec;
	int		size;

	size = 0;
	prec = form->prec;
	i = 0;
	while (wstr[i])
	{
		tmp = ft_memalloc(65);
		size += ft_size(wstr[i]);//modifier les 2 lignes pour passer curqui_test
		if (size > form->prec && form->prec > -1)
			break ;
		if ((ft_wchar(wstr[i], tmp)) == -1)
		{

			if ((int)i == form->prec)
				break ;
			free(tmp);
			return (-1);
		}
		if ((int)ft_strlen(tmp) > prec && prec > -1)
		{
			free(tmp);
			ft_strcat(str, "\0");
			break ;
		}
		else
			ft_strcat(str, tmp);
		prec--;
		i++;
		free(tmp);
	}
	return (0);
}
