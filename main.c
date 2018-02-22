//en tete

#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>

#include <limits.h>

int	main(void)
{
//	setlocale(LC_ALL, "");
	wchar_t	s[4];

	s[0] = 'S';
	s[1] = 256;
	s[2] = 'u';
	s[3] = '\0';

//	printf(" len = %d\n", printf("%d", 42));
//	printf(" len = %d\n", ft_printf("%d", 42));

//	printf(" len = %d\n", printf("%.1ls", s));
//	printf(" len = %d\n", ft_printf("%.1ls", s));

//	printf(" len = %d\n", printf("test %-12i et %--2.4s %24s !\n", 0, NULL, "coco"));
//	printf(" len = %d\n", ft_printf("test %-12i et %--2.4s %24s !\n", 0, NULL, "coco"));

//	printf(" len = %d\n", printf("%X", 4294967296));
//	printf(" len = %d\n", ft_printf("%X", 4294967296));

	printf(" len = %d\n", printf("%+u", 4294967295));
	printf(" len = %d\n", ft_printf("%+u", 4294967295));


	printf(" len = %d\n", printf("% 20.12ld et % 05D% 4.8hi !", 0x11ffaa147, 24, (short)-2345));
	printf(" len = %d\n\n", ft_printf("% 20.12ld et % 05D% 4.8hi !", 0x11ffaa147, 24, (short)-2345));


//	printf(" len = %d\n", printf("%-+-12.7Dt%0 4i %04.2% et %lc titi", 125, 124, 256));
//	printf(" len = %d\n\n", ft_printf("%-+-12.7Dt%0 4i %04.2% et %lc titi", 125, 124, 256));



	printf(" len = %d\n", printf("% 10.5d", 4242));
	printf(" len = %d\n\n", ft_printf("% 10.5d", 4242));

	printf(" len = %d\n", printf("%+12.5d", 140));
	printf(" len = %d\n\n", ft_printf("%+12.5d", 140));

	printf(" len = %d\n", printf("%5d", -42));
	printf(" len = %d\n\n", ft_printf("%5d", -42));

	printf(" len = %d\n", printf("%0+5d", -42));
	printf(" len = %d\n\n", ft_printf("%0+5d", -42));

	printf(" len = %d\n", printf("%-05d", -42));
	printf(" len = %d\n\n", ft_printf("%-05d", -42));

	printf(" len = %d\n", printf("%-5d", -42));
	printf(" len = %d\n\n", ft_printf("%-5d", -42));

	printf(" len = %d\n", printf("%+d", -42));
	printf(" len = %d\n\n", ft_printf("%+d", -42));

	printf(" len = %d\n", printf("% d", -42));
	printf(" len = %d\n\n", ft_printf("% d", -42));

	printf(" len = %d\n", printf("% .0d", 0));
	printf(" len = %d\n\n", ft_printf("% .0d", 0));

	printf(" len = %d\n", printf("% d", 0));
	printf(" len = %d\n\n", ft_printf("% d", 0));

	printf(" len = %d\n", printf("%.5d", -421));
	printf(" len = %d\n\n", ft_printf("%.5d", -421));




//	printf(" len = %d\n", printf("toto et %02u coco %-5lu mimi", 19, (unsigned long)-20));
//	printf(" len = %d\n", ft_printf("toto et %02u coco %-5lu mimi", 19, (unsigned long)-20));





//	printf(" len = %d\n", printf("%6C et coco %C titi %C tyty", 3250, 0xd800, 'u'));
//	printf(" len = %d\n", ft_printf("%6C et coco %C titi %C tyty", 3250, 0xd800, 'u'));

/*	printf(" len = %d\n", printf("%-+-12.7Dt%0 4i %04.2% et %lc titi", 125, 124, 256));
	printf(" len = %d\n", ft_printf("%-+-12.7Dt%0 4i %04.2% et %lc titi", 125, 124, 256));

*/
/*	printf(" len = %d\n", printf("au %04.2% et %c titi", 65));
	printf(" len = %d\n", ft_printf("au %04.2% et %c titi", 65));

	printf(" len = %d\n", printf("%8C et coco %C titi %lc", 3250, 0x11ffff, 'a'));
	printf(" len = %d\n", ft_printf("%8C et coco %C titi %lc", 3250, 0x11ffff, 'a'));


	printf(" len = %d\n", printf("\ntoto et %00009U%-2lu mimi et titi%--14u", 0, (unsigned long)14, 200));
	printf(" len = %d\n", ft_printf("\ntoto et %00009U%-2lu mimi et titi%--14u", 0, (unsigned long)14, 200));
*/






//	printf(" len = %d\n", printf("ahello ca%----4c %1c va %10c%-c ??", '\0', '\n', (char)564, 0));
//	printf(" len = %d\n", ft_printf("bhello ca%----4c %1c va %10c%-c ??", '\0', '\n', (char)564, 0));



//	sleep(1500);
	return (0);
}
