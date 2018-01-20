#include <stdio.h>
#include "libft/libft.h"
#include "ft_printf.h"

/*
int	main()
{
	int	nb;
	int	reste;
	int	res;

	nb = 1000;
	res = nb;
	while (res > 16)
	{
		reste = res % 16;
		res /= 16;
	}
	printf("%d et le reste %d", res, reste);
	return (0);
}
*/

char	*ft_modif(int res)
{
	char	*c;

	c = ft_memalloc(2);
	if (res == 10)
		c[0] = 'A';
	if (res == 11)
		c[0]= 'B';
	if (res == 12)
		c[0] = 'C';
	if (res == 13)
		c[0] = 'D';
	if (res == 14)
		c[0] = 'E';
	if (res == 15)
		c[0] = 'F';
	return (c);
}

int	main()
{
	int	nb;
	int	res;
	int	reste;
	char	*str;

	nb = 10;
	res = nb;
//	str = ft_memalloc(1);
/*	while (res > 16)
	{
		reste = res % 16;
		res /= 16;
		if (reste > 9)
			str = ft_strjoin(str, ft_modif(reste));
		else
			str = ft_strjoin(str, ft_itoa(reste));
	}
	if (res > 9)
	{
		str = ft_strjoin(str, ft_modif(res));
	}
	else
	{
		str = ft_strjoin(str, ft_itoa(res));
	}
	str = ft_reverse(str);
*/	str = ft_convert_base(nb, 8);
	ft_putstr(str);
	free(str);
	return (0);
}