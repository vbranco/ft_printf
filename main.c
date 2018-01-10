/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   main.c                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: vbranco <marvin@le-101.fr>                 +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2018/01/10 17:00:11 by vbranco      #+#   ##    ##    #+#       */
/*   Updated: 2018/01/10 17:00:16 by vbranco     ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "ft_printf/ft_printf.h"
#include <locale.h>

int		main(int argc, char **argv)
{
	setlocale(LC_ALL, "");
	t_spec	spec;
	char				c = 'Z';
	int					i = -32767;
	int					ix = 255;
	long				z = 0;
	long int			l = 2147483647;
	long long			ll = 9223372036854775807;
	unsigned int		ui = 65535;
	unsigned long int	ul = 4294967295;
	unsigned long long	ull = 18446744073709551614U;
	short				sh = 32767;
	size_t				zu = 4294967296;
	intmax_t			imt = 18446744073709551614U;
	char				*str;
	char				*str2;
	int					*p = &ix;
	wchar_t	s[4];
	s[0] = 0x53;
	s[1] = 0xD800;
	s[2] = 0x81000;
	s[3] = '\0';
	wchar_t	t[4];
	t[0] = 'S';
	t[1] = 256;
	t[2] = 'u';
	t[3] = '\0';

	printf(" len = %d\n",        printf("t%04.2o%#2oet %#-8.3o titi", 0, 0, 0));
	printf(" len = %d\n\n\n", ft_printf("t%04.2o%#2oet %#-8.3o titi", 0, 0, 0));

	printf(" len = %d\n",    printf("toto %.o et %#.o et %#.1o et %#.3o !", 0, 0, 0, 0));
	printf(" len = %d\n", ft_printf("toto %.o et %#.o et %#.1o et %#.3o !", 0, 0, 0, 0));

	printf(" len = %d\n",    printf("toto %.x et %#.x et %#.1x et %#.3x !", 0, 0, 0, 0));
	printf(" len = %d\n", ft_printf("toto %.x et %#.x et %#.1x et %#.3x !", 0, 0, 0, 0));

	printf(" len = %d\n",    printf("%#b", 42));
	printf(" len = %d\n", ft_printf("%#b", 42));

	printf(" len = %d\n",    printf("%4.1ls", L"Jambon"));
	printf(" len = %d\n", ft_printf("%4.1ls", L"Jambon"));

	printf(" len = %d\n",    printf("{%-30ls}", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B"));
	printf(" len = %d\n", ft_printf("{%-30ls}", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B"));

	printf(" len = %d\n",    printf("{% S}", L"(null)"));
	printf(" len = %d\n", ft_printf("{% S}", L"(null)"));

	printf(" len = %d\n",    printf("@main_ftprintf: %####0000 33..12..#d\n", 256));
	printf(" len = %d\n", ft_printf("@main_ftprintf: %####0000 33..12..#d\n", 256));

	printf(" len = %d\n",    printf("@main_ftprintf: %###-#0000 33...12..#0+0d", 256));
	printf(" len = %d\n", ft_printf("@main_ftprintf: %###-#0000 33...12..#0+0d", 256));

	printf(" len = %d\n",    printf("%#10.5x", 255));
	printf(" len = %d\n", ft_printf("%#10.5x", 255));

	printf(" len = %d\n",    printf("%#10.5x", 0));
	printf(" len = %d\n", ft_printf("%#10.5x", 0));

	printf(" len = %d\n",    printf("%10.5x", 0));
	printf(" len = %d\n", ft_printf("%10.5x", 0));

	printf(" len = %d\n",    printf("%#.o", 42));
	printf(" len = %d\n", ft_printf("%#.o", 42));

	printf(" len = %d\n",    printf("%10.5o", 255));
	printf(" len = %d\n", ft_printf("%10.5o", 255));

	printf(" len = %d\n", printf("%#10o", 255));
	printf(" len = %d\n", ft_printf("%#10o", 255));

	printf(" len = %d\n", printf("%#10.5o", 0));
	printf(" len = %d\n", ft_printf("%#10.5o", 0));

	printf(" len = %d\n", printf("%10.5o", 0));
	printf(" len = %d\n", ft_printf("%10.5o", 0));

	printf(" len = %d\n", printf("%#10o", 0));
	printf(" len = %d\n", ft_printf("%#10o", 0));

	printf(" len = %d\n", printf("%-10Zeubi"));
	printf(" len = %d\n", ft_printf("%-10Zeubi"));

	printf(" len = %d\n", printf("|% 3ld|", l));
	printf(" len = %d\n", ft_printf("|% 3ld|", l));

	printf(" len = %d\n", printf("%15.4S", L"我是一只猫。"));
	printf(" len = %d\n", ft_printf("%15.4S", L"我是一只猫。"));

	printf(" len = %d\n", printf("%.4S", L"我是一只猫。"));
	printf(" len = %d\n", ft_printf("%.4S", L"我是一只猫。"));

	printf(" len = %d\n", printf("%S", L"我"));
	printf(" len = %d\n", ft_printf("%S", L"我"));

	printf(" len = %d\n",    printf("{%030S}", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B"));
	printf(" len = %d\n", ft_printf("{%030S}", L"ÊM-M-^QÊM-^XØ‰∏M-ÂM-^O™ÁM-^L´„M-M-^B"));

	printf(" len = %d\n",    printf("{%.*s}", -5, "42"));
	printf(" len = %d\n", ft_printf("{%.*s}", -5, "42"));

	printf(" len = %d\n",    printf("%o", 42));
	printf(" len = %d\n", ft_printf("%o", 42));

	printf(" len = %d\n",    printf("%.0o", 0));
	printf(" len = %d\n", ft_printf("%.0o", 0));

	printf(" len = %d\n",    printf("%#.o", ix));
	printf(" len = %d\n", ft_printf("%#.o", ix));

	printf(" len = %d\n",    printf("%#.0o", 0));
	printf(" len = %d\n", ft_printf("%#.0o", 0));

	printf(" len = %d\n",    printf("%20lld", ll));
	printf(" len = %d\n", ft_printf("%20lld", ll));

	printf(" len = %d\n", printf("|%#02jX|", imt));
	printf(" len = %d\n", ft_printf("|%#02jX|", imt));

	printf(" len = %d\n", printf("%#.x %#.0x", 0, 0));
	printf(" len = %d\n", ft_printf("%#.x %#.0x", 0, 0));

	printf(" len = %d\n", printf("%#.o %#.0o", 0, 0));
	printf(" len = %d\n", ft_printf("%#.o %#.0o", 0, 0));

	printf(" len = %d\n", printf("%5lx", l));
	printf(" len = %d\n", ft_printf("%5lx", l));

	printf(" len = %d\n", printf("%-#15lo", l));
	printf(" len = %d\n", ft_printf("%-#15lo", l));

	printf(" len = %d\n", printf("%.*d", 10, i));
	printf(" len = %d\n", ft_printf("%.*d", 10, i));

	printf(" len = %d\n", printf("%.0ld", l));
	printf(" len = %d\n", ft_printf("%.0ld", l));

	printf(" len = %d\n", printf("%9.*lo", 6, l));
	printf(" len = %d\n", ft_printf("%9.*lo", 6, l));

	printf(" len = %d\n", printf("|%c|", 0));
	printf(" len = %d\n", ft_printf("|%c|", 0));

	printf(" len = %d\n", printf("%-9c", c));
	printf(" len = %d\n", ft_printf("%-9c", c));

	printf(" len = %d\n", printf("%s", str2));
	printf(" len = %d\n", ft_printf("%s", str2));

	printf(" len = %d\n", printf("%9s", str2));
	printf(" len = %d\n", ft_printf("%9s", str2));

	printf(" len = %d\n", printf("%-9.3s", str2));
	printf(" len = %d\n", ft_printf("%-9.3s", str2));

	printf(" len = %d\n", printf("%.3s", NULL));
	printf(" len = %d\n", ft_printf("%.3s", NULL));

	printf(" len = %d\n", printf("%C", L'猫'));
	printf(" len = %d\n", ft_printf("%C", L'猫'));

	printf(" len = %d\n", printf("%S", L"中文!"));
	printf(" len = %d\n", ft_printf("%S", L"中文!"));

	printf(" len = %d\n", printf("%S", L"猫猫"));
	printf(" len = %d\n", ft_printf("%S", L"猫猫"));


	printf(" len = %d\n",    printf("a%Sb%sc%S", L"我", "42", L"猫"));
	printf(" len = %d\n", ft_printf("a%Sb%sc%S", L"我", "42", L"猫"));

	printf("len = %d\n",    printf("%C", L'ͳ'));
	printf("len = %d\n", ft_printf("%C", L'ͳ'));

/*
**  CAS D'ERREUR
*/
	printf("\n\n*********CAS D'ERREUR*********\n\n");

	printf(" len = %d\n",    printf("%-+-12.7Dt%0 4i %04.2% et %lc titi", 125, 124, 256));
	printf(" len = %d\n", ft_printf("%-+-12.7Dt%0 4i %04.2% et %lc titi", 125, 124, 256));

	printf(" len = %d\n",    printf("%-12ls next", s));
	printf(" len = %d\n", ft_printf("%-12ls next", s));

	printf(" len = %d\n",    printf("%ls", t));
	printf(" len = %d\n", ft_printf("%ls", t));

	printf(" len = %d\n",    printf("%8C et coco %C titi %lc", 3250, 0x11ffff, 'a'));
	printf(" len = %d\n", ft_printf("%8C et coco %C titi %lc", 3250, 0x11ffff, 'a'));

	printf(" len = %d\n",    printf("%9ls %S", s, (wchar_t *)'a'));
	printf(" len = %d\n", ft_printf("%9ls %S", s, (wchar_t *)'a'));

//	sleep(1500);
	return (0);
}
