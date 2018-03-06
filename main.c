//en tete

#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>

#include <limits.h>

int	main(void)
{
//	setlocale(LC_ALL, "");
/*	wchar_t	s[4];

	s[0] = 'S';
	s[1] = 254;
	s[2] = 'u';
	s[3] = '\0';
*/
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

	printf(" len = %d\n", printf("{%03c}", 0));
	printf(" len = %d\n\n", ft_printf("{%03c}", 0));

	printf(" len = %d\n", printf("{%05s}", "abc"));
	printf(" len = %d\n\n", ft_printf("{%05s}", "abc"));

	printf(" len = %d\n", printf("{%030S}", L"我是一只猫。"));
	printf(" len = %d\n\n", ft_printf("{%030S}", L"我是一只猫。"));

	printf(" len = %d\n", printf("{%05p}", 0));
	printf(" len = %d\n\n", ft_printf("{%05p}", 0));

	printf(" len = %d\n", printf("{%05p}"));
	printf(" len = %d\n\n", ft_printf("{%05p}"));


	printf(" len = %d\n", printf("{%05.Z}", 0));
	printf(" len = %d\n\n", ft_printf("{%05.Z}", 0));

	printf(" len = %d\n", printf("{%05.S}", L"42 c est cool"));
	printf(" len = %d\n\n", ft_printf("{%05.S}", L"42 c est cool"));

	printf(" len = %d\n", printf("{%-15Z}", 123));
	printf(" len = %d\n\n", ft_printf("{%-15Z}", 123));

	printf(" len = %d\n", printf("{%10R}"));
	printf(" len = %d\n\n", ft_printf("{%10R}"));

	printf(" len = %d\n", printf("test %-12i et %--2.4s %24s !\n", 0, NULL, "coco"));
	printf(" len = %d\n\n", ft_printf("test %-12i et %--2.4s %24s !\n", 0, NULL, "coco"));
*/

/*
	printf(" len = %d\n", printf("%*d", 5, 42));
	printf(" len = %d\n\n", ft_printf("%*d", 5, 42));

	printf(" len = %d\n", printf("{%*d}", -5, 42));
	printf(" len = %d\n\n", ft_printf("{%*d}", -5, 42));

	printf(" len = %d\n", printf("{%*d}", 0, 42));
	printf(" len = %d\n\n", ft_printf("{%*d}", 0, 42));

	printf(" len = %d\n", printf("{%*c}", 0, 0));
	printf(" len = %d\n\n", ft_printf("{%*c}", 0, 0));

	printf(" len = %d\n", printf("{%*c}", -15, 0));
	printf(" len = %d\n\n", ft_printf("{%*c}", -15, 0));

	printf(" len = %d\n", printf("{%.*d}", 5, 42));
	printf(" len = %d\n\n", ft_printf("{%.*d}", 5, 42));

	printf(" len = %d\n", printf("{%.*d}", -5, 42));
	printf(" len = %d\n\n", ft_printf("{%.*d}", -5, 42));

	printf(" len = %d\n", printf("{%.*d}", 0, 42));
	printf(" len = %d\n\n", ft_printf("{%.*d}", 0, 42));

	printf(" len = %d\n", printf("{%.*s}", 5, "42"));
	printf(" len = %d\n\n", ft_printf("{%.*s}", 5, "42"));

	printf(" len = %d\n", printf("{%.*s}", -5, "42"));
	printf(" len = %d\n\n", ft_printf("{%.*s}", -5, "42"));

	printf(" len = %d\n", printf("{%.*s}", 0, "42"));
	printf(" len = %d\n\n", ft_printf("{%.*s}", 0, "42"));

	printf(" len = %d\n", printf("{%*s}", 5, 0));
	printf(" len = %d\n\n", ft_printf("{%*s}", 5, 0));

//------
	printf(" len = %d\n", printf("{%3*p}", 10, 0));
	printf(" len = %d\n\n", ft_printf("{%3*p}", 10, 0));

//	printf(" len = %d\n", printf());
//	printf(" len = %d\n\n", ft_printf());

	printf(" len = %d\n", printf("{%3*d}", 0, 0));
	printf(" len = %d\n\n", ft_printf("{%3*d}", 0, 0));

	printf(" len = %d\n", printf("{%*3d}", 0, 0));
	printf(" len = %d\n\n", ft_printf("{%*3d}", 0, 0));

	printf(" len = %d\n", printf("{%*3d}", 5, 0));
	printf(" len = %d\n\n", ft_printf("{%*3d}", 5, 0));

	printf(" len = %d\n", printf("{%05.*d}", -15, 42));
	printf(" len = %d\n\n", ft_printf("{%05.*d}", -15, 42));
*/
/*	printf(" len = %d\n", printf("%.4ls", L"我是一只猫。"));
	printf(" len = %d\n\n", ft_printf("%.4ls", L"我是一只猫。"));

	printf(" len = %d\n", printf("%15.4ls", L"我是一只猫。"));
	printf(" len = %d\n\n", ft_printf("%15.4ls", L"我是一只猫。"));
*/

/*	printf(" len = %d\n", printf("%.2ls",s));
	printf(" len = %d\n\n", ft_printf("%.2ls",s));

	printf(" len = %d\n", printf("{%05.c}", 0));
	printf(" len = %d\n\n", ft_printf("{%05.c}", 0));

	printf(" len = %d\n", printf("{%05.s}", 0));
	printf(" len = %d\n\n", ft_printf("{%05.s}", 0));

	printf(" len = %d\n", printf("{%05.Z}", 0));
	printf(" len = %d\n\n", ft_printf("{%05.Z}", 0));

	printf(" len = %d\n", printf("{%05.S}", L"42 c est cool"));
	printf(" len = %d\n\n", ft_printf("{%05.S}", L"42 c est cool"));
 */
	ft_printf("\n");
	ft_printf("%%\n");
	ft_printf("%d\n", 42);
	ft_printf("%d%d\n", 42, 41);
	ft_printf("%d%d%d\n", 42, 43, 44);
	ft_printf("%ld\n", 2147483647);
	ft_printf("%lld\n", 9223372036854775807);
	ft_printf("%x\n", 505);
	ft_printf("%X\n", 505);
	ft_printf("%p\n", &ft_printf);
	ft_printf("%20.15d\n", 54321);
	ft_printf("%-10d\n", 3);
	ft_printf("% d\n", 3);
	ft_printf("%+d\n", 3);
	ft_printf("%010d\n", 1);
	ft_printf("%hhd\n", 0);
	ft_printf("%jd\n", 9223372036854775807);
	ft_printf("%zd\n", 4294967295);
	ft_printf("%\n");
	ft_printf("%U\n", 4294967295);
	ft_printf("%u\n", 4294967295);
	ft_printf("%o\n", 40);
	ft_printf("%%#08x\n", 42);
	ft_printf("%x\n", 1000);
	ft_printf("%#X\n", 1000);
	ft_printf("%s\n", NULL);
	ft_printf("%S\n", L"ݗݜशব");
	ft_printf("%s%s\n", "test", "test");
	ft_printf("%s%s%s\n", "test", "test", "test");
	ft_printf("%C\n", 15000);

/*	printf("len = %d\n", printf("%p %5p %.2p %.15p %.15p", 5, 4896548, 15694, 0, -1));
//	printf("len = %d\n\n", ft_printf("%p %5p %.2p %.15p %.15p", 5, 4896548, 15694, 0, -1));

	printf("len = %d\n", printf("%50.3s", NULL));
	printf("len = %d\n\n", ft_printf("%50.3s", NULL));

	printf("len = %d\n", printf("%n"));
	printf("len = %d\n\n", ft_printf("%n"));
*/
//	sleep(1500);
	return (0);
}
