
#include "ft_printf.h"

static int	ft_puissance(int nb, int i)
{
	if (i == 0)
		return (1);
	else
		return (nb * (ft_puissance(nb, i - 1)));
}

int		ft_trans_bi_dc(char ***mask)
{
	char	*test;
	size_t	i;
	long	nb;

	i = 0;
	nb = 0;
	test = ft_memalloc(ft_strlen(**(mask)));
	ft_strcpy(test, **(mask));
	test = ft_reverse(test);
	while (test[i])
	{
		if (test[i] == '1')
		{
			nb += ft_puissance(2, i);
			i++;
		}
		else
			i++;
	}
	free(test);
	return (nb);
}
