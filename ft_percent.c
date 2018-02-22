/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_percent.c                                     .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/02/19 17:16:00 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/02/22 17:41:41 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf.h"

static void    ft_p_min(const char *format, t_form *form)
{
	int             i;

	i = 0;
	while (format[i] && (i < form->size))
	{
		while (format[i] == '+' || format[i] == '-' || format[i] == '#' || format[i] == '0' || format[i] == ' ')
			i++;
		if (format[i] >= '1' || format[i] <= '9')
		{
			format += i;
			form->min = ft_atoi(format);
			break ;
		}
	}
}

static void    ft_p_flag(const char *format, t_form *form)
{
	int     i;

	i = 0;
	while ((i < form->size - 1) && format[i])
	{
		if (format[i] == '#')
			form->is_h = 1;
		else if (format[i] == '0')
		{
			if (form->prec == -1 && (form->min % 10 !=  0))
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

static void    ft_r_type(const char *format, t_form *form)
{
	int     i;

	i = 0;
	while ((format[i] != 's' && format[i] != 'S' && format[i] != 'p' &&
		format[i] != 'd' && format[i] != 'D' && format[i] != 'i' &&
		format[i] != 'o' && format[i] != 'O' && format[i] != 'u' &&
		format[i] != 'U' && format[i] != 'x' && format[i] != 'X' &&
		format[i] != 'c' && format[i] != 'C' && format[i] != 'b' &&
		format[i] != '%') && format[i])
		i++;
	if (format[i] != '%')
		form->type = format[i];
	form->size = i + 2;
}

static int	ft_p(const char *format, t_form *form)
{
	char	*str;
	int	i;
	char	*s1;

	s1 = ft_memalloc(form->min);
	i = 0;
	while (format[i] != '%' && format[i])
		i++;
	str = ft_memalloc(form->min + form->prec + 3);
	ft_strcat(str, "%");
	form->size = i + 2;
	if (form->min > 1)
	{
		if (form->is_n == 1)
			ft_add_str_end(str, ft_memset(s1, ' ', (form->min - 1)));
		else if (form->is_z == 1)
			ft_add_str_begin(str, ft_memset(s1, '0', (form->min - 1)));
		else if (form->is_n == 0)
			ft_add_str_begin(str, ft_memset(s1, ' ', (form->min - 1)));
	}
	free(s1);
	write(1, form->buf, ft_strlen(form->buf));
	free(form->buf);
	form->buf = NULL;
	write (1, str, ft_strlen(str));
	free(str);
	return (ft_strlen(str));
}

int		ft_percent(const char *format, t_form *form)
{
	format++;
/*	if (*format == '\0')
	{
		form->size = 1;
		return (1);
	}
*/	ft_r_type(format, form);
	ft_p_min(format, form);
	ft_p_flag(format, form);
	if (form->type != '\0')
		return (0);
	else
		return (ft_p(format, form));
}