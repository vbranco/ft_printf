//en tete

#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>

#include <limits.h>

int	main(void)
{
	setlocale(LC_ALL, "");


/*	printf(" len = %d\n", printf("%lc", 0x40501));
	printf(" len = %d\n", ft_printf("%lc", 0x40501));

	printf(" len = %d\n", printf("%lc", 0x4e6));
	printf(" len = %d\n", ft_printf("%lc", 0x4e6));

	printf(" len = %d\n", printf("%.5s", "coco et titi"));
	printf(" len = %d\n", ft_printf("%.5s", "coco et titi"));


	printf(" len = %d\n", printf("%12%"));
	printf(" len = %d\n", ft_printf("%12%"));
*/
	printf(" len = %d\n", printf("titi % +---12.5% et%%%0004% et %+1%"));
	printf(" len = %d\n", ft_printf("titi % +---12.5% et%%%0004% et %+1%"));


//	sleep(1500);
	return (0);
}
