/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/12 19:37:01 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/17 20:06:53 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

typedef struct		s_form
{
	int				size;
	char			type;
	char			length;
	char			elength;
	int				is_h;
	int				is_z;
	int				is_n;
	int				is_p;
	int				is_s;
	int				min;
	int				prec;
}					t_form;

int					ft_printf(const char * format, ...);
/*
** Parsing
*/
void				ft_format(const char *format, va_list ap);
void				ft_init_struct(t_form *form);
void				ft_recup_type(const char *format, t_form *form);
void				ft_recup_flag(const char *format, t_form *form);
void				ft_recup_length(const char *format, t_form *form);
void				ft_recup_min(const char *format, t_form *form);
void				ft_recup_prec(const char *format, t_form *form);
/*
** Recup type
*/
void				ft_args(t_form *form, va_list ap);//recuperer le type
void				ft_arg_c(va_list ap, t_form *form);
void				ft_arg_s(va_list ap, t_form *form);
void				ft_arg_d_i(va_list ap, t_form *form);
void				ft_arg_x_o(va_list ap, t_form *form);
void				ft_arg_p(va_list ap, t_form *form);
void				ft_convert_base(long nb, int base, t_form *form, char **str);

void					ft_free(char **tmp);

#endif
