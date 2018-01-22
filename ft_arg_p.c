//en tete

#include "ft_printf.h"

void	ft_arg_p(va_list ap, t_form *form)
{
	char	*str;
	void	*ptr;
	long	nb;

	str = ft_memalloc(20);
	ptr = va_arg(ap, void*);
	nb = (long)ptr;
	ft_convert_base(nb, 16, form, &str);
	write(1, "0x", 2);
	write(1, str, ft_strlen(str));
	free(str);
}
