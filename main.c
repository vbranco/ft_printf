//en tete

#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>

int	main(void)
{
	setlocale(LC_ALL, "");
//	char	bonjour[] = "bonjour";
//	char	c = 'a';
	int	nb = 19;
//	int	*ptr = &nb;;
//	wchar_t	ca = L'é';
//	wchar_t	str[] = L"la mérde ça mec";

/*	printf("%s vitor, %S, %p\n", bonjour, str, ptr);
	ft_printf("%s vitor, %S, %p\n", bonjour, str, ptr);

	printf("%c\n", c);
	ft_printf("%c\n", c);
*/
//	printf("je suis printf %100d\n", nb);
//	ft_printf("je suis ft_printf %100d\n", nb);

	printf("%#X\n", nb);
	ft_printf("%#X", nb);

/*	ft_printf("%b\n", nb);

	printf("%p\n", ptr);
	ft_printf("%p\n", ptr);

	printf("%C\n", ca);
	ft_printf("%C\n", ca);

	printf("%S\n", str);
	ft_printf("%S\n", str);

	ft_printf("je n'ai pas de parametres\n");

	//sleep(1500);
*/	return (0);
}
