/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_printf.h                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/12/12 19:37:01 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2017/12/12 20:30:31 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include "libft/libft.h"

int		ft_printf(const char * format, ...);
char		**ft_recup_params(const char *format);
char		**ft_format_spec(char **recup);
int		ft_is_string(char *param);
int		ft_is_numb(char *param);
int		ft_is_char(char *param);
void		ft_free(char **tmp);
int		ft_count_args(const char *format);

#endif
