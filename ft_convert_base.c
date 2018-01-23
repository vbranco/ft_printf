//en tete

#include "ft_printf.h"
//j'ai des fuites de memoire dans une de ces fonctions.
static char	*ft_modif(int nb, t_form *form)
{
	char	c;
	char	*str;

	str = ft_memalloc(2);
	if (nb >= 10 && form->type == 'X')
		c = 'A' + (nb - 10);
	else
		c = 'a' + (nb - 10);
	str[0] = c;
	return (str);
}

void		ft_convert_base(long nb, int base, t_form *form, char **str)
{
	char	*tmp;
	long	reste;
	long	limit;

	tmp = ft_memalloc(17);
	base == 16 ? (limit = 9) : (limit = 8);
	while (nb > base)
	{
		reste = nb % base;
		nb /= base;
		if (reste > limit)
			tmp = ft_strcat(tmp, ft_modif(reste, form));
		else
			tmp = ft_strcat(tmp, ft_itoa(reste));
	}
	if (nb > limit)
		tmp = ft_strcat(tmp, ft_modif(nb, form));
	else
		tmp = ft_strcat(tmp, ft_itoa(nb));
	tmp = ft_reverse(tmp);
	ft_strcat(*(str), tmp);
	free(tmp);
}
