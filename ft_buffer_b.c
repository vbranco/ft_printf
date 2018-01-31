//en tete

#include "ft_printf.h"

void	ft_buffer_b(char *str, t_form *form)
{
	char	*s1;
	int	len;

	len = ft_strlen(str);
	s1 = ft_memalloc(form->min);
	if (form->min > len)
	{
		if (form->is_z == 1)
			ft_add_str_begin(str, ft_memset(s1, '0',
			(form->min - len)));
	}
	free(s1);
}
