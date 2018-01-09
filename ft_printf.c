/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/12 20:07:34 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/12 20:30:28 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	char		*form;
	int		i;
	int		j;
	char		**tmp;
	char		**param;
	int		nb_args;

	nb_args = ft_count_args(format);//ca sert a connaitre le nombre d'arguments attendus.
	ft_putnbr(nb_args);
	i = 0;
	j = 0;
	form = (char*)format;
	va_start(ap, format);
	while (form)
		form = va_arg(ap, char*);
	va_end(ap);
	va_start(ap, format);
	tmp = ft_recup_params(format);
	free(form);
	param = ft_format_spec(tmp);
	ft_free(tmp);
	while (format[j] != '\n' && format[j])
	{
		while (format[j] != '%')
		{
			ft_putchar(format[j]);
			j++;
		}
		if (ft_is_string(param[i]) == 1)
			ft_putstr(va_arg(ap, char *));
//		if (ft_is_char(param[i]) == 1)
//			ft_putchar(va_arg(ap, char));
//		if (ft_is_numb(param[i]) == 1);
//			ft_putstr(va_arg(ap, char *));
		j = j + ft_strlen(param[i]) + 1;
	}
	va_end(ap);
	if (format[j] == '\n')
		ft_putchar('\n');
	ft_free(param);
	return (1);
}

int		main(int ac, char **av)
{
	char	merde[] = "vitor";
	char	bonjour[] = "bonjour";
	char	encore[] = "et je suis dans le bon chemin :)";
	char	cara = 'z';
	int	nb = 10;

	ft_printf("%s, e mon nom est %s; %s\n",bonjour,  merde, encore);
	ft_printf("%c\n", cara);
	ft_printf("%d\n", nb);
//	sleep(1500);
	return (0);
}
