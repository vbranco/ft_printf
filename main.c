//en tete

#include "ft_printf.h"
#include <stdio.h>
#include <locale.h>

#include <limits.h>

int	main(void)
{
	setlocale(LC_ALL, "");
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



















//	sleep(1500);
	return (0);
}
