/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/12 19:37:01 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/15 20:24:12 by vbranco     ###    #+. /#+    ###.fr     */
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
}					t_form;

int					ft_printf(const char * format, ...);
void				ft_format(const char *format);
void				ft_recup_type(const char *format, t_form *form);
void				ft_recup_flag(const char *format, t_form *form);
void				ft_recup_length(const char *format, t_form *form);
void				ft_init_struct(t_form *form);


void					ft_free(char **tmp);

#endif
