/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_recup_flag.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 17:19:56 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 18:36:44 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_stop(const char *format, t_form *form)
{
	int		i;

	i = 0;
	while (format[i] && i < form->size)
	{
		if (format[i] == '.')
			return (1);
		i++;
	}
	return (0);
}

void	ft_recup_flag(const char *format, t_form *form)
{
	int	i;

	i = 0;
	while ((i < form->size - 1) && format[i])
	{
		if (format[i] == '#')
			form->is_h = 1;
//		else if (format[i] == '0')
		else if (format[i] == '0' && !ft_isdigit(format[i - 1]) &&
				!ft_stop(format, form))
		{
		//	if (form->prec == -1 && (form->min % 10 !=  0))
				form->is_z = 1;
		}
		else if (format[i] == '-')
			form->is_n = 1;
		else if (format[i] == '+')
			form->is_p = 1;
		else if (format[i] == ' ')
			form->is_s = 1;
		i++;
	}
}
