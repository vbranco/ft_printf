//en tete

#include "ft_printf.h"

void	ft_buffer(char *str, t_form *form)
{
	if (form->is_p == 1)
		ft_add_str_begin(str, "+");
}
