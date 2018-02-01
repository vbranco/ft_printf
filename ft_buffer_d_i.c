//en tete

#include "ft_printf.h"
#include <stdio.h>


void		ft_buffer_d_i(char *str, t_form *form)
{
	char	*s1;
	int	len;

	len = ft_strlen(str);
	s1 = ft_memalloc(form->min);
	if (form->is_p == 1 && *str != '-')
		ft_add_str_begin(str, "+");
	if (form->prec > len)
		len = ft_precision(str, form);
	if (form->min > len)
	{
		if (form->is_n == 1)
			ft_add_str_end(str, ft_memset(s1, ' ',
			(form->min - len)));
		else if (form->is_z == 1)
			ft_add_str_begin(str, ft_memset(s1, '0',
			(form->min - len)));
		else if (form->is_n == 0)
			ft_add_str_begin(str, ft_memset(s1, ' ',
			(form->min - len)));
	}
	if (form->is_s == 1)
		ft_add_str_begin(str, " ");
	free(s1);
}
