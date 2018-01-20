//en tete

#include "ft_printf.h"

void	ft_arg_x_o(va_list ap, t_form *form)
{
	long		nb;
	int		reste;
	char		*str;
	long		max;

	max = 4294967295;
	nb = va_arg(ap, long);
	str = ft_memalloc(20);
	if (form->type == 'x' || form->type == 'X')
	{
		nb = nb * -1;
		if (nb >= 0 && nb <= 9)
			str = ft_itoa(nb);
		else if (nb > 9)
			ft_convert_base(nb, 16, form, &str);
		else if (nb < 0)
			ft_convert_base((max + 1 - nb), 16, form, &str);
	}
	else if (form->type == 'o' || form->type == 'O')
	{
		if (nb > 0 && nb <= 8)
			str = ft_itoa(nb);
		else if (nb > 8)
			ft_convert_base(nb, 8, form, &str);
	}
	ft_putstr(str);
	free(str);
}
