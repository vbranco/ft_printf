/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/12 19:37:01 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/10 20:20:10 by vbranco     ###    #+. /#+    ###.fr     */
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
	char			type;
	char			flag;
	char			length;
	char			elength;
}					t_form;

int					ft_printf(const char * format, ...);
void					ft_format(const char *format);
int					ft_recup_type(const char *format, t_form form);
int					ft_recup_flag(const char *format, t_form form);
int					ft_recup_length(const char *format, t_form form);


void					ft_free(char **tmp);

#endif
