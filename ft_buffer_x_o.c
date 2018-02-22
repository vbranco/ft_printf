/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_buffer_x_o.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/08 16:53:24 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/22 20:10:45 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"
/*
static void	ft_h(char *str, char *s1, t_form *form)
{
	int	i;
	int	len;

	i = 0;
	len = ft_strlen(str);
	if (form->type == 'o' || form->type == 'O')
	{
		if (form->prec > len)
			ft_add_str_begin(str, ft_memset(s1, '0', (form->prec - len)));
		if (form->prec != (int)ft_strlen(str) || str[0] != '0')
			ft_add_str_begin(str, "0");
	}
	else if (form->type == 'x')
	{
		if (form->prec > len)
			ft_add_str_begin(str, ft_memset(s1, '0', (form->prec - len)));
		ft_add_str_begin(str, "0x");
	}
	else if (form->type == 'X')
	{
		if (form->prec > len)
			ft_add_str_begin(str, ft_memset(s1, '0', (form->prec - len)));
		ft_add_str_begin(str, "0X");
	}
}

void	ft_buffer_x_o(char *str, t_form *form)
{
	int		len;
	char	*s1;

	s1 = ft_memalloc(form->min);
	if (form->prec == 0 && str[0] == '0')
	{
		if (form->is_h == 1 && (form->type == 'o' || form->type == 'O'))
			str[0] = '0';
		else
			str[0] = '\0';
	}
	if (form->is_h == 1 && str[0] != '0' && str[0] != '\0')
		ft_h(str, s1, form);
	ft_precision(str, form);
	len = ft_strlen(str);
	if (form->min > len)
	{
		if (form->is_n == 1)
		{
			ft_add_str_end(str, ft_memset(s1, ' ', (form->min - len)));
		}
		else if ((form->is_z == 1 && form->min > form->prec))
		{
			ft_add_str_begin(str, ft_memset(s1, '0', (form->min - len)));
			if ((form->type == 'x' || form->type == 'X') && (str[ft_strlen(str) - 2] == 'x' || str[ft_strlen(str) - 2] == 'X'))
			{
				str[1] = str[ft_strlen(str) - 2];
				str[ft_strlen(str) - 2] = str[0];
			}
		}
		else if (form->is_n == 0)
		{
			ft_add_str_begin(str, ft_memset(s1, ' ', (form->min - len)));
		}
	}
	free(s1);
}*/

static int	ft_space(char *str, t_form *form)
{
	if (form->is_s == 1)
	{
		ft_add_str_begin(str, " ");
		return (1);
	}
	return (0);
}

static void	ft_prec(char *str, t_form *form)
{
	int		len;
	int		i;
	char	*s1;

	i = 0;
	s1 = NULL;
	len = ft_strlen(str);
	if (form->prec == 0 && str[0] == '0')
		str[0] = '\0';
	if (form->prec > len)
	{
		s1 = ft_memalloc(form->prec);
		ft_add_str_begin(str, ft_memset(s1, '0', (form->prec - len)));
	}
	free(s1);
}

void		ft_buffer_x_o(char *str, t_form *form)
{
	int		len;
	char	*s1;
	char	c[3];

	if (form->type == 'o' || form->type == 'O')
	{
		c[0] = '0';
		c[1] = '\0';
	}
	if (form->type == 'x' || form->type == 'X')
	{
		c[0] = '0';
		c[2] = '\0';
		if (form->type == 'x')
			c[1] = 'x';
		else
			c[1] = 'X';
	}
	ft_prec(str, form);
	s1 = ft_memalloc(form->min);
	len = ft_strlen(str);
	if (form->is_h == 1)
		form->min -= 2;
	if (form->min > len)
	{
		if (form->is_n == 1)
		{
			if (form->is_h == 1)
			{
				ft_add_str_begin(str, c);
				len--;
			}
			ft_add_str_end(str, ft_memset(s1, ' ', (form->min - len)));
		}
		else if (form->is_z == 1)
		{
			ft_add_str_begin(str, ft_memset(s1, '0', (form->min - len)));
			if (form->is_h == 1)
				ft_add_str_begin(str, c);
			ft_space(str, form);
		}
		else if (form->is_n == 0)
		{
	//		printf("str : %s\n", str);
			if (form->is_h == 1)
			{
				len--;
				ft_add_str_begin(str, c);
			}
			ft_add_str_begin(str, ft_memset(s1, ' ', (form->min - len)));
		}
	}
	else if (form->is_h == 1 && str[0] != '0')
	{
		ft_add_str_begin(str, c);
	}
}
