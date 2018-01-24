/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_wchar.c                                       .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/24 17:33:55 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 20:24:22 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_put2wchar(wchar_t wc, char *str)
{
	str[0] = (wc >> 6) + 0xc0;
	str[1] = (wc & 0x3f) + 0x80;
}

static void	ft_put3wchar(wchar_t wc, char *str)
{
	str[0] = (wc >> 12) + 0xe0;
	str[1] = ((wc >> 6) & 0x3f) + 0x80;
	str[2] = (wc & 0x3f) + 0x80;
}

static void	ft_put4wchar(wchar_t wc, char *str)
{
	str[0] = (wc >> 18) + 0xf0;
	str[1] = ((wc >> 12) & 0x3f) + 0x80;
	str[2] = ((wc >> 6) & 0x3f) + 0x80;
	str[3] = (wc & 0x3f) + 0x80;
}

void		ft_wchar(wchar_t wc, char *str)
{
	if (wc <= 127)
		ft_putchar(wc);
	else if (wc <= 255 && MB_CUR_MAX == 1)
		ft_putchar((char)wc);
	else if (wc > 127 && MB_CUR_MAX > 1)
	{
		if (wc < 0x800)
			ft_put2wchar(wc, str);
		else if (wc < 0x10000)
			ft_put3wchar(wc, str);
		else if (wc < 0x110000)
			ft_put4wchar(wc, str);
	}
}
