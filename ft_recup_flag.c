/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_recup_flag.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/15 17:19:56 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/12 18:19:08 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_recup_flag(const char *format, t_form *form)
{
	int	i;

	i = 0;
	//jeter un oeil a la condition car des fois ca prend l'espace et d'autres fois non
	//bien retester les differents cas de figure
	while ((i < form->size - 1) && format[i])
	{
		if (format[i] == '#')
			form->is_h = 1;
		else if (format[i] == '0')
		{
			if( (format[i - 1] < '0' || format[i - 1] > '9') &&
				(format[i + 1] != '0'))
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
