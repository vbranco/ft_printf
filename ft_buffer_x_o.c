//en tete

#include "ft_printf.h"

void	ft_buffer_x_o(char *str, t_form *form)
{
	if (form->is_h == 1)
	{
		if (form->type == 'o')
			ft_add_str_begin(str, "0");
		else if (form->type == 'x')
			ft_add_str_begin(str, "0x");
		else
			ft_add_str_begin(str, "0X");
	}
}
