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

/*/--------------testes qui ne passent pas-----------
	printf(" len = %d\n", printf("%2c", 0));
	printf(" len = %d\n\n", ft_printf("%2c", 0));

	printf(" len = %d\n", printf("%"));
	printf(" len = %d\n\n", ft_printf("%"));

	printf(" len = %d\n", printf("% Zoooo"));
	printf(" len = %d\n\n", ft_printf("% Zoooo"));

	printf(" len = %d\n", printf("{%}"));
	printf(" len = %d\n\n", ft_printf("{%}"));


//probleme sur ce test!!-----------
//	printf(" len = %d\n", printf("%-+-12.7Dt%0 4i %04.2% et %lc titi", 125, 124, 256));
//	printf(" len = %d\n\n", ft_printf("%-+-12.7Dt%0 4i %04.2% et %lc titi", 125, 124, 256));
//--------------------------------

	printf(" len = %d\n", printf("{%S}", NULL));
	printf(" len = %d\n\n", ft_printf("{%S}", NULL));
*/

/*	printf(" len = %d\n", printf("%#08x", 42));
	printf(" len = %d\n\n", ft_printf("%#08x", 42));

	printf(" len = %d\n", printf("%#.0x", 1));
	printf(" len = %d\n\n", ft_printf("%#.0x", 1));

	printf(" len = %d\n", printf("%6o", 01423));
	printf(" len = %d\n\n", ft_printf("%6o", 01423));

	printf(" len = %d\n", printf("%03o", 0));
	printf(" len = %d\n\n", ft_printf("%03o", 0));

	printf(" len = %d\n", printf("%-12o", 01423));
	printf(" len = %d\n\n", ft_printf("%-12o", 01423));

	printf(" len = %d\n", printf("coco et %-#-#--24O titi%#012o", 12, -874));
	printf(" len = %d\n\n", ft_printf("coco et %-#-#--24O titi%#012o", 12, -874));

	printf(" len = %d\n", printf("test%#.4o et %02o %0#14.0o!!", 012, 036, 12587499));
	printf(" len = %d\n\n", ft_printf("test%#.4o et %02o %0#14.0o!!", 012, 036, 12587499));

	printf(" len = %d\n", printf("t%04.2o%#2oet %#-8.3o titi", 0, 0, 0));
	printf(" len = %d\n\n", ft_printf("t%04.2o%#2oet %#-8.3o titi", 0, 0, 0));

	printf(" len = %d\n", printf("t %#7.5X%0006.2x et %lX!", 0xab, 0x876, 0xff11ff11ff1));
	printf(" len = %d\n\n", ft_printf("t %#7.5X%0006.2x et %lX!", 0xab, 0x876, 0xff11ff11ff1));

	printf(" len = %d\n", printf("cc%#.4X et %#0012x %#04hX !!", 0xaef, 0xe, (unsigned short)0));
	printf(" len = %d\n\n", ft_printf("cc%#.4X et %#0012x %#04hX !!", 0xaef, 0xe, (unsigned short)0));

	printf(" len = %d\n", printf("toto %##.0xet %#.X%###.1x", 0, 0, 0));
	printf(" len = %d\n\n", ft_printf("toto %##.0xet %#.X%###.1x", 0, 0, 0));

	printf(" len = %d\n", printf("%0#10.0x %0#x", 12345, 0));
	printf(" len = %d\n\n", ft_printf("%0#10.0x %0#x", 12345, 0));

	printf(" len = %d\n", printf("%hd", 32768));
	printf(" len = %d\n\n", ft_printf("%hd", 32768));

	printf(" len = %d\n", printf("%u", -1));
	printf(" len = %d\n\n", ft_printf("%u", -1));

	printf(" len = %d\n", printf("%u", 4294967296));
	printf(" len = %d\n\n", ft_printf("%u", 4294967296));

	printf(" len = %d\n", printf("%D", 0xff11ff11ff88));
	printf(" len = %d\n\n", ft_printf("%D", 0xff11ff11ff88));

	printf(" len = %d\n", printf("%U", 4294967296));
	printf(" len = %d\n\n", ft_printf("%U", 4294967296));

	printf(" len = %d\n", printf("%lld", -9223372036854775808));
	printf(" len = %d\n\n", ft_printf("%lld", -9223372036854775808));

	printf(" len = %d\n", printf("%jd", -9223372036854775808));
	printf(" len = %d\n\n", ft_printf("%jd", -9223372036854775808));

	printf(" len = %d\n", printf("%2c", 0));
	printf(" len = %d\n\n", ft_printf("%2c", 0));


	printf(" len = %d\n", printf("%x", -42));
	printf(" len = %d\n\n", ft_printf("%x", -42));

	printf(" len = %d\n", printf("%X", -42));
	printf(" len = %d\n\n", ft_printf("%X", -42));
*/
	printf(" len = %d\n", printf("%O", LONG_MAX));
	printf(" len = %d\n\n", ft_printf("%O", LONG_MAX));


















//	printf(" len = %d\n", printf("%.1ls", s));
//	printf(" len = %d\n", ft_printf("%.1ls", s));

//	printf(" len = %d\n", printf("test %-12i et %--2.4s %24s !\n", 0, NULL, "coco"));
//	printf(" len = %d\n", ft_printf("test %-12i et %--2.4s %24s !\n", 0, NULL, "coco"));

//	printf(" len = %d\n", printf("%X", 4294967296));
//	printf(" len = %d\n", ft_printf("%X", 4294967296));

//	printf(" len = %d\n", printf("%+u", 4294967295));
//	printf(" len = %d\n", ft_printf("%+u", 4294967295));


//	printf(" len = %d\n", printf("% 20.12ld et % 05D% 4.8hi !", 0x11ffaa147, 24, (short)-2345));
//	printf(" len = %d\n\n", ft_printf("% 20.12ld et % 05D% 4.8hi !", 0x11ffaa147, 24, (short)-2345));


//	printf(" len = %d\n", printf("%-+-12.7Dt%0 4i %04.2% et %lc titi", 125, 124, 256));
//	printf(" len = %d\n\n", ft_printf("%-+-12.7Dt%0 4i %04.2% et %lc titi", 125, 124, 256));

/*

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
*/



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
