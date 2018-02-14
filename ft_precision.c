/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_precision.c                                   .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/08 16:51:53 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/14 19:28:43 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

int		ft_precision(char *str, t_form *form)
{
	int		len;
	char	*s1;
	int		i;

	i = 0;
	len = ft_strlen(str);
	s1 = ft_memalloc(form->prec);
//	printf("prec : %d\n", form->prec);
	if (form->prec > len)
	{
//		printf("ici?\n");
		ft_add_str_begin(str, ft_memset(s1, '0', (form->prec - len)));
	}
/*	else
	{
		while ((i < (len - form->prec)))// && form->prec > -1)
		{
//			printf("ici?\n");
			str[i] = ' ';
			i++;
		}
	}
*/
//	else if (form->prec == 0)
//		str[0] = '\0';
	free(s1);
	return (ft_strlen(str));
}
