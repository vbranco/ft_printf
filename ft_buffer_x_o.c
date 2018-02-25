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

static int	ft_zero(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		if (str[i] != '0')
			return (0);
		i++;
	}
	return(1);
}

static int	ft_space(char *str, t_form *form)
{
	if (form->is_s == 1)
	{
		ft_add_str_begin(str, " ");
		return (1);
	}
	return (0);
}

static void	ft_prec(char *str, char *c, t_form *form)
{
	int		len;
	int		i;
	char	*s1;

	i = 0;
	s1 = NULL;
	len = ft_strlen(str);
	if (str[0] == '0')
		form->zero = 1;
	if (form->prec == 0 && str[0] == '0')
	{
		if (form->is_h == 1 && (form->type == 'o' || form->type == 'O'))
			str[0] = '0';
		else
			str[0] = '\0';
	}
	if (form->prec > len)
	{
		s1 = ft_memalloc(form->prec);
		ft_add_str_begin(str, ft_memset(s1, '0', (form->prec - len)));
		if ((form->type == 'x' || form->type == 'X') && form->is_h == 1 && !ft_zero(str))
			ft_add_str_begin(str, c);
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
	ft_prec(str, c, form);
	s1 = ft_memalloc(form->min);
	len = ft_strlen(str);
	if (form->is_h == 1)
	{
		if ((form->type == 'x' || form->type == 'X') && !ft_zero(str))
			form->min -= 2;
		else
			if (str[0] != '0')
				form->min--;
	}
	if (form->min > len)
	{
		if (form->is_n == 1)
		{
			if (form->is_h == 1 && (size_t)form->prec > ft_strlen(str))
				ft_add_str_begin(str, c);
			ft_add_str_end(str, ft_memset(s1, ' ', (form->min - len)));
		}
		else if (form->is_z == 1)
		{
			ft_add_str_begin(str, ft_memset(s1, '0', (form->min - len)));
			if (form->is_h == 1 && !ft_zero(str))
				ft_add_str_begin(str, c);
			ft_space(str, form);
		}
		else if (form->is_n == 0)
		{
			if (form->is_h == 1 && str[0] != '0')
				ft_add_str_begin(str, c);
			ft_add_str_begin(str, ft_memset(s1, ' ', (form->min - len)));
		}
	}
	else if (form->is_h == 1 && str[0] != '0' && form->zero == 0)
		ft_add_str_begin(str, c);
}
