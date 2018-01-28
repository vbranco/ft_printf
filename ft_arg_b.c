//en tete

#include "ft_printf.h"

static void	ft_binaire(char *str, long nb)
{
	size_t	i;

	i = 0;
	while (nb > 0)
	{
		if (nb % 2 == 0)
			str[i] = '0';
		else
			str[i] = '1';
		nb /= 2;
		i++;
	}
	str = ft_reverse(str);
}

int	ft_arg_b(va_list ap, t_form *form)
{
	char	*str;
	long	nb;

	(void)form;
	nb = va_arg(ap, long);
	str = ft_memalloc(ft_size_nb(nb));
	ft_binaire(str, nb);
	write(1, str, ft_strlen(str));
	return (ft_strlen(str));
}
