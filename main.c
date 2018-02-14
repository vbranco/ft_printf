//en tete

#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>

#include <limits.h>

int	main(void)
{
	setlocale(LC_ALL, "");
/*	char	bonjour[] = "bonjour";
	char	c = 'a';
	int	nb = 19;
	int	*ptr = &nb;;
	wchar_t	ca = L'é';
	wchar_t	str[] = L"Jambon";
//	wchar_t	str1[] = L"la mérde ça mec";
*/
//	printf(" len = %d\n", printf("%llo", (unsigned long long)-127));
//	printf(" len = %d\n", ft_printf("%llo", (unsigned long long)-127));

//	printf("%lu\n\n", sizeof(unsigned long long));

//	printf(" len = %d\n", printf("%llX", (unsigned long long)0xaaffee1199667));
//	printf(" len = %d\n", ft_printf("%llX", (unsigned long long)0xaaffee1199667));

//	printf(" len = %d\n", printf("%.0x", 0));
//	printf(" len = %d\n", ft_printf("%.0x", 0));

	printf(" len = %d\n", printf("t %#7.5X%0006.2x et %lX!", 0xab, 0x876, 0xff11ff11ff1));
	printf(" len = %d\n", ft_printf("t %#7.5X%0006.2x et %lX!", 0xab, 0x876, 0xff11ff11ff1));


//	sleep(1500);
	return (0);
}
