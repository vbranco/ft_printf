/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/12 19:37:01 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/24 20:29:26 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"
# include <wchar.h>

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
int				ft_format(const char *format, va_list ap, int *size);
void				ft_init_struct(t_form *form);
void				ft_recup_type(const char *format, t_form *form);
void				ft_recup_flag(const char *format, t_form *form);
void				ft_recup_length(const char *format, t_form *form);
void				ft_recup_min(const char *format, t_form *form);
void				ft_recup_prec(const char *format, t_form *form);
/*
** Recup type
*/
int				ft_args(t_form *form, va_list ap);
int				ft_arg_c(va_list ap, t_form *form);
int				ft_arg_s(va_list ap, t_form *form);
int				ft_arg_d_i(va_list ap, t_form *form);
int				ft_arg_x_o(va_list ap, t_form *form);
int				ft_arg_p(va_list ap, t_form *form);
/*
** fonctions de modif pour recuperer une chaine de caracteres
*/
void				ft_convert_base(long nb, int base, t_form *form, char *str);
void				ft_wchar(wchar_t wc, char *str);
void				ft_wstr(wchar_t *wstr, char *str);
int					ft_count_size(wchar_t *wstr);
void				ft_my_itoa(int nb, char *tmp);
void				ft_add_str_begin(char *s1, char *s2);
/*
** Buffer
*/
void				ft_buffer(char *str, t_form *form);
#endif
