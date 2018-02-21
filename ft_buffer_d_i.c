/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_buffer_d_i.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/08 16:54:27 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/20 20:26:46 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

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

//----------------------------------------------------------------------------------------
//modif du 20/02

static int		ft_space(char *str, t_form *form)
{
	if (form->is_s == 1 && str[0] != '-')
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
	char		*s1;

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

static void	ft_neg(char *str, t_form *form)
{
	char	*s1;
	int		len;

	s1 = NULL;
	ft_modif_str(str);
	len = ft_strlen(str);
	if (form->prec > len)
	{
		s1 = ft_memalloc(form->prec);
		ft_add_str_begin(str, ft_memset(s1, '0', (form->prec - len)));
		free(s1);
	}
	len = ft_strlen(str);
	if (form->min > len)
	{
		len += ft_space(str, form);
		len++;
		s1 = ft_memalloc(form->min);
		if (form->is_n == 1)
		{
			ft_add_str_begin(str, "-");
			ft_add_str_end(str, ft_memset(s1, ' ', (form->min - len)));
		}
		else if (form->is_z == 1)
		{
			ft_add_str_begin(str, ft_memset(s1, '0', (form->min - len)));
			ft_add_str_begin(str, "-");
		}
		else if (form->is_n == 0)
		{
			ft_add_str_begin(str, "-");
			ft_add_str_begin(str, ft_memset(s1, ' ', (form->min - len)));
		}
		free(s1);
	}
	else
		ft_add_str_begin(str, "-");
}

static void	ft_signe(char *str, t_form *form)
{
	char	*s1;
	char	c[2];
	int		len;

	s1 = ft_memalloc(form->min);
	c[0] = '\0';
	c[1] = '\0';
	if (str[0] == '-')
		ft_neg(str, form);
	else
		ft_prec(str, form);
	len = ft_strlen(str);
	if ((form->is_n == 1 && str[0] == '-') || form->is_p == 1)
	{
		if (form->is_n == 1 && str[0] == '-')
			c[0] = '-';
		else
			c[0] = '+';
		if (!ft_strchr(str, '-'))
				form->min--;
	}
//	len = ft_strlen(str);
	if (form->min > len)
	{
		if (form->is_n == 1)
		{
			ft_add_str_begin(str, c);
			ft_add_str_end(str, ft_memset(s1, ' ', (form->min - len)));
		}
		else if (form->is_z == 1)
		{
			ft_add_str_begin(str, ft_memset(s1, '0', (form->min - len)));
			ft_add_str_begin(str, c);
		}
		else if (form->is_n == 0)
		{
			ft_add_str_begin(str, c);
			ft_add_str_begin(str, ft_memset(s1, ' ', (form->min - len)));
		}
	}
	else
		ft_space(str, form);
	if (c[0] == '-' && !ft_strchr(str, '-'))
		ft_add_str_begin(str, "-");
	else if (c[0] == '+' && !ft_strchr(str, '-') && !ft_strchr(str, '+'))
		ft_add_str_begin(str, "+");
	free(s1);
}

//---------------------------------------------------------------------------------------

void		ft_buffer_d_i(char *str, t_form *form)
{
	int		len;

	len = ft_strlen(str);
	if (form->is_s == 1 && form->is_p == 1)
		form->is_s = 0;
	if (form->is_z == 1 && form->is_n == 1)
		form->is_z = 0;
	ft_signe(str, form);
}
