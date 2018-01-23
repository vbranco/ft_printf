//en tete

#include "ft_printf.h"

void	ft_arg_x_o(va_list ap, t_form *form)
{
	long		nb;
	char		*str;
	long		max;

	max = 4294967295;
	nb = va_arg(ap, long);
	str = ft_memalloc(20);
	if (nb < 0 || nb > max)
	{
		if (form->type == 'x' || form->type == 'X')
			ft_convert_base(nb, 16, form, &str);
	}
	else if (nb >= 0)
	{
		if (form->type == 'x' || form->type == 'X')
			ft_convert_base(nb, 16, form, &str);
		else
			ft_convert_base(nb, 8, form, &str);
	}
	write(1, str, ft_strlen(str));
	free(str);
}
