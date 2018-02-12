//en tete

#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>

int	main(void)
{
	setlocale(LC_ALL, "");
/*	char	bonjour[] = "bonjour";
	char	c = 'a';
	int	nb = 19;
	int	*ptr = &nb;;
	wchar_t	ca = L'é';
*/	wchar_t	str[] = L"Jambon";
//	wchar_t	str1[] = L"la mérde ça mec";

	printf(" len = %d\n", printf("toto et %02u coco %-5lu mimi", 19, (unsigned long)-20));
	printf(" len = %d\n", ft_printf("toto et %02u coco %-5lu mimi", 19, (unsigned long)-20));



//	printf(" len = %d\n",        printf("t%04.2o", 0));
//	printf(" len = %d\n\n", ft_printf("t%04.2o", 0));

//	printf(" len = %d\n",        printf("t%#2oet", 0));
//	printf(" len = %d\n\n", ft_printf("t%#2oet", 0));

//	printf(" len = %d\n",        printf("et %#-8.3o titi", 0));
//	printf(" len = %d\n\n", ft_printf("et %#-8.3o titi", 0));

//	printf(" len = %d\n", printf("t%04.2o%#2oet", 0, 0));
//	printf(" len = %d\n\n", ft_printf("t%04.2o%#2oet", 0, 0));

/*	printf(" len = %d\n", printf("%08i", -71));
	printf(" len = %d\n", ft_printf("%08i", -71));

	printf(" len = %d\n", printf("%5d", -741));
	printf(" len = %d\n", ft_printf("%5d", -741));

	printf(" len = %d\n", printf("%.5d", -421));
	printf(" len = %d\n", ft_printf("%.5d", -421));

	printf(" len = %d\n", printf("%.2i", -10));
	printf(" len = %d\n", ft_printf("%.2i", -10));

	printf(" len = %d\n", printf("%-2i", -7));
	printf(" len = %d\n", ft_printf("%-2i", -7));

	printf(" len = %d\n", printf("%00+10.4d", 0));
	printf(" len = %d\n", ft_printf("%00+10.4d", 0));

	printf(" len = %d\n", printf("%0d", -579));
	printf(" len = %d\n", ft_printf("%0d", -579));

	printf(" len = %d\n", printf("% 20.12ld et % 05D% 4.8hi !", 0x11ffaa147, 24,  (short)-2345));
	printf(" len = %d\n", ft_printf("% 20.12ld et % 05D% 4.8hi !", 0x11ffaa147, 24,  (short)-2345));
*/
//	printf(" len = %d\n", printf("% 05D", 24));
//	printf(" len = %d\n", ft_printf("% 05D", 24));



//	printf(" len = %d\n", printf("toto%.0d et %+.i et  %   .0D !!!", 0, 0, 0));
//	printf(" len = %d\n", ft_printf("toto%.0d et %+.i et  %   .0D !!!", 0, 0, 0));

//	printf(" len = %d\n", printf("%+12.5d\n", 140));
//	printf(" len = %d\n", ft_printf("%+12.5d\n", 140));

//	printf(" len = %d\n", printf("t%04.2o %#2oet %#-8.3o titi", 0, 1, 0));
//	printf(" len = %d\n\n", ft_printf("t%04.2o %#2oet %#-8.3o titi", 0, 1, 0));
/*
	printf("%4.1ls\n", L"Jambon");
	ft_printf("%4.1ls\n", L"Jambon");

	printf("%4.1ls\n", str);
	ft_printf("%4.1ls\n", str);
*/
/*	printf("printf %.1s vitor, %.1S, %.1p\n", bonjour, str, ptr);
	ft_printf("trintf %.1s vitor, %.1S, %.1p\n", bonjour, str, ptr);

	printf("je suis printf %-10x\n", 10);
	ft_printf("je suis trintf %-10x\n", 10);

	printf("%c\n", c);
	ft_printf("%c\n", c);

	printf("je suis printf %10x\n", 10);
	ft_printf("je suis trintf %10x\n", 10);

	printf("%#x\n", nb);
	ft_printf("%#x\n", nb);

	ft_printf("%b\n", nb);

	printf("je suis printf %30p\n", ptr);
	ft_printf("je suis trintf %30p\n", ptr);

	printf("je suis \"C\" printf %-10C\n", ca);
	ft_printf("je suis \"C\" trintf %-10C\n", ca);

	printf("je suis \"c\" printf %-10C\n", c);
	ft_printf("je suis \"c\" trintf %-10C\n", c);

	printf("je suis printf>> %20S\n", str);
	ft_printf("je suis trintf>> %20S\n", str);

	printf("je suis printf>> %20s\n", bonjour);
	ft_printf("je suis trintf>> %20s\n", bonjour);
	printf(" len = %d\n", printf("je n'ai pas de parametres"));
	printf(" len = %d\n", ft_printf("je n'ai pas de parametres"));
*/
//	sleep(1500);
	return (0);
}
