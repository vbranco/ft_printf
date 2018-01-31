//en tete

#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>

int	main(void)
{
	setlocale(LC_ALL, "");
	char	bonjour[] = "bonjour";
//	char	c = 'a';
//	int	nb = 19;
//	int	*ptr = &nb;;
//	wchar_t	ca = L'é';
	wchar_t	str[] = L"la mérde ça mec";

/*	printf("%s vitor, %S, %p\n", bonjour, str, ptr);
	ft_printf("%s vitor, %S, %p\n", bonjour, str, ptr);

	printf("%c\n", c);
	ft_printf("%c\n", c);

	printf("je suis printf %10x\n", 10);
	ft_printf("je suis trintf %10x\n", 10);

	printf("%#x\n", nb);
	ft_printf("%#x\n", nb);
*/
/*	ft_printf("%b\n", nb);

	printf("je suis printf %30p\n", ptr);
	ft_printf("je suis trintf %30p\n", ptr);

	printf("je suis \"C\" printf %-10C\n", ca);
	ft_printf("je suis \"C\" trintf %-10C\n", ca);

	printf("je suis \"c\" printf %-10C\n", c);
	ft_printf("je suis \"c\" trintf %-10C\n", c);
*/
	printf("je suis printf>> %20S\n", str);
	ft_printf("je suis trintf>> %20S\n", str);

	printf("je suis printf>> %20s\n", bonjour);
	ft_printf("je suis trintf>> %20s\n", bonjour);
//	ft_printf("je n'ai pas de parametres\n");

//	sleep(1500);
	return (0);
}
