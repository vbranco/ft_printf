//en tete

#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>

#include <limits.h>

int	main(void)
{
	setlocale(LC_ALL, "");


/*
	printf(" len = %d\n", printf("%lc", 0x4e6));
	printf(" len = %d\n", ft_printf("%lc", 0x4e6));
*/

//	printf(" len = %d\n", printf("%6C et coco %C titi %C tyty", 3250, 0xd800, 'u'));
//	printf(" len = %d\n", ft_printf("%6C et coco %C titi %C tyty", 3250, 0xd800, 'u'));

//	printf(" len = %d\n", printf("%-+-12.7Dt%0 4i %04.2% et %lc titi", 125, 124, 256));
//	printf(" len = %d\n", ft_printf("%-+-12.7Dt%0 4i %04.2% et %lc titi", 125, 124, 256));


//	printf(" len = %d\n", ft_printf("%04.2% et %lc titi", 256));

//	printf(" len = %d\n", printf("%8C et coco %C titi %lc", 3250, 0x11ffff, 'a'));
//	printf(" len = %d\n", ft_printf("%8C et coco %C titi %lc", 3250, 0x11fff, 'a'));



	printf(" len = %d\n", printf("ahello ca%----4c %1c va %10c%-c ??", '\0', '\n', (char)564, 0));
	printf(" len = %d\n", ft_printf("bhello ca%----4c %1c va %10c%-c ??", '\0', '\n', (char)564, 0));



//	sleep(1500);
	return (0);
}
