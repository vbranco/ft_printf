/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_buffer_p_s.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/19 19:33:36 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/19 19:33:43 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_precision_s(char *str, t_form *form)
{
	int		i;

	i = 0;
	if (form->prec > -1)
	{
		while (i < form->prec)
			i++;
		str[i] = '\0';
	}
}

void	ft_buffer_p_s(char *str, t_form *form)
{
	char	*s1;
	int		len;

//	ft_putendl("ici");
	ft_precision_s(str, form);
	len = ft_strlen(str);
	s1 = ft_memalloc(form->min);
//	printf("\nstr : %s\n", str);
	if (form->is_n == 1 && form->min > len)
	{
//		printf("min : %d\n", form->min);
//		printf("is_n : %d\n", form->is_n);
		ft_add_str_end(str, ft_memset(s1, ' ', (form->min - len)));
	}
	else if (form->is_n == 0 && form->min > len)
	{
//		printf("min : %d\n", form->min);
//		printf("is_n : %d\n", form->is_n);
		ft_add_str_begin(str, ft_memset(s1, ' ', (form->min - len)));
	}
//	printf("\nstr : %s\n", str);
//	printf("len : %zu\n", ft_strlen(str));
	free(s1);
}
