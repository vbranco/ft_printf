/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/12 20:07:34 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/17 19:53:46 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int				ft_printf(const char *format, ...)
{
	va_list		ap;
	char		**tmp;
	char		**param;

	va_start(ap, format);
	if (ft_strchr(format, '%') == 0)
	{
		ft_putstr(format);
		return (ft_strlen(format));
	}
	else
	{
		ft_format(format, ap);
	}
	/*
	   while (form)
	   form = va_arg(ap, char*);
	   va_end(ap);
   */	return (1);
}


int		main(int ac, char **av)
{
	char	merde[] = "vitor";
	char	bonjour[] = "bonjour";
	char	encore[] = "et je suis dans le bon chemin :)";
	char	cara = 'V';
	int	nb = 10;

//	printf("%10d\n", 12);
		ft_printf("%s", encore);
	//	ft_printf("%-01.9i merde %1000.5d");
	//	ft_printf("%+ 0i bon %hu jour %+jX et  %#zD et %llxet %%");
	//	ft_printf("E mon nom est bien.");
	//	ft_printf("ici %-s, e mon nom est %+d; % U",bonjour,  merde, encore);
	//	ft_printf("%c", cara);
	//	ft_printf("%d\n", nb);
	//	sleep(1500);
	return (0);
}
