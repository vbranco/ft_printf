/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_buffer_d_i.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/08 16:54:27 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/10 16:33:19 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_add_signe_neg(char *str, char c)
{
	int		len;

	len = ft_strlen(str);
	while (len > 0)
	{
		str[len] = str[len - 1];
		len--;
	}
	str[0] = c;
}

static void	ft_modif_str(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		str[i] = str[i + 1];
		i++;
	}
}

static void	ft_is_neg(char *str, t_form *form)
{
	int		len;
	char	*s1;

	s1 = ft_memalloc(form->min);
	if (form->min > (int)ft_strlen(str) || form->prec > (int)ft_strlen(str))
	{
		ft_modif_str(str);
	}
	if (form->prec > (int)ft_strlen(str))
	{
		len = ft_precision(str, form);
		ft_add_signe_neg(str, '-');
	}
	len = ft_strlen(str);
	if (form->min > len)
	{
		if (form->is_n == 1)
			ft_add_str_end(str, ft_memset(s1, ' ', (form->min - len)));
		else if (form->is_z == 1 || form->prec > -1)
		{
			ft_add_str_begin(str, ft_memset(s1, '0', (form->min - len - 1)));
			ft_add_signe_neg(str, '-');
		}
		else if (form->is_n == 0)
		{
			ft_add_signe_neg(str, '-');
			ft_add_str_begin(str, ft_memset(s1, ' ', (form->min - len - 1)));
		}
	}
}

void		ft_buffer_d_i(char *str, t_form *form)
{
	char	*s1;
	int		len;

	len = ft_strlen(str);
	s1 = ft_memalloc(form->min);
	if (*str == '-')
	{
//		printf("je suis dans le neg\n");
		ft_is_neg(str, form);
	}
	else
	{
		if (form->prec > len)
		{
	//		printf("je suis dans la precisison\n");
			len = ft_precision(str, form);
		}
		if (form->is_p == 1 && *str != '-')
		{
			ft_add_str_begin(str, "+");
			len++;
		}
//		printf("len : %d\n", len);
		if (form->min > len)
		{
	//		printf("min : %d\n", form->min);
			if (form->is_n == 1)
			{
	//			printf("je suis 1\n");
				ft_add_str_end(str, ft_memset(s1, ' ', (form->min - len)));
			}
			else if (form->is_z == 1)
			{
	//			printf("je suis 2\n");
				ft_add_str_begin(str, ft_memset(s1, '0', (form->min - len)));
			}
			else if (form->is_n == 0)
			{
	//			printf("je suis 3\n");
				ft_add_str_begin(str, ft_memset(s1, ' ', (form->min - len)));
			}
		}
	}
	if (form->is_s == 1 && str[0] != '-' && form->min > (int)ft_strlen(str))
	{
//		printf("je suis IS_S\n");
		ft_add_str_begin(str, " ");
	}
	free(s1);
}
