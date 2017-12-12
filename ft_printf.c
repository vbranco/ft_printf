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

int		ft_printf(const char *format, ...)
{
	va_list		ap;
	int			nb_arg;
	char		*form;
	int			i;

	nb_arg = 0;
	form = format;
	va_start(ap, format);
	while (form != NULL)
	{
		nb_arg++;
		form = va_arg(ap, char*);
	}
	va_end(ap);
	printf("%s\n", format);
	va_start(ap, format);
	i = 1;
	while (i < nb_arg)
	{
		printf("il faut afficher %s\n", va_arg(ap, char *));
		i++;
	}
}

int		main(int ac, char **av)
{
	ft_printf("merde","autre", NULL);
	return (0);
}
