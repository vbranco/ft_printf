//en tete

#include "ft_printf.h"
#include <stdio.h>


void		ft_buffer_d(char *str, t_form *form)
{
	char	*s1;

	s1 = ft_memalloc(form->min);
	if (form->is_p == 1 && *str != '-')
		ft_add_str_begin(str, "+");
	if (form->min > (int)ft_strlen(str))
	{
		if (form->is_n == 1)
			ft_add_str_end(str, ft_memset(s1, ' ', (form->min - ft_strlen(str))));
		else if (form->is_z == 1)
		{
			ft_add_str_begin(str, ft_memset(s1, '0', (form->min - ft_strlen(str))));
		}
		else if (form->is_n == 0)
			ft_add_str_begin(str, ft_memset(s1, ' ', (form->min - ft_strlen(str))));
	}
	if (form->is_s == 1)
		ft_add_str_begin(str, " ");
	free(s1);
}
