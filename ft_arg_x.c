//en tete

#include "ft_printf.h"

char	*ft_arg_x(va_list ap, t_form *form)
{
	unsigned int	nb;
	int		res;
	int		reste;
	char		*str;

	nb = va_arg(ap, unsigned int);
	if (nb >= 0 && nb <= 9)
		str = ft_itoa(nb);
	else if (nb > 9)
	{
		res = nb;
		while (res > 16)
		{
			reste = res % 16;
			res /= 16;
		}
		str = ft_itoa(res);
		str = ft_strjoin(str, ft_itoa(reste));
	}
	else
	{
	}
	return (str);
}
