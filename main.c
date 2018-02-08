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
*/	wchar_t	str[] = L"la mérdasd";
//	wchar_t	str1[] = L"la mérde ça mec";

//	printf("%4.1ls\n", L"Jambon");
//	ft_printf("%4.1ls\n", "Jambon");

	printf("je suis printf %ls\n", str);
	ft_printf("je suis trintf %ls\n", str);

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
	ft_printf("je n'ai pas de parametres\n");
*/
//	sleep(1500);
	return (0);
}
