//en tete

#include "ft_printf.h"

void	ft_buffer_x_o(char *str, t_form *form)
{
	int	len;
	char	*s1;

	s1 = ft_memalloc(form->min);
	len = ft_strlen(str);
	if (form->is_h == 1)
	{
		if (form->type == 'o')
			ft_add_str_begin(str, "0");
		else if (form->type == 'x')
			ft_add_str_begin(str, "0x");
		else
			ft_add_str_begin(str, "0X");
	}
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
	free(s1);
}
