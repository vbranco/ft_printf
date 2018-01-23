
#include "ft_printf.h"

static void	ft_trans_uni_bit(char ***str, char ***mask)
{
	size_t	i;
	char	*test;
	char	*mas;
	size_t	z;

	i = 0;
	z = 0;
	mas = ft_memalloc(60);
	test = ft_memalloc(60);
	ft_strcpy(mas, **(mask));
	ft_strcpy(test, **(str));
	while (mas[i])
		(i > 5 && i < 8) || (i > 13) ? i++ : test[z] != '\0' ?
		mas[i++] = test[z++] : i++;
	mas = ft_reverse(mas);
	ft_strcpy(**(mask), mas);
	free(mas);
	free(test);
}

static void	ft_modif(long nb, char **hex)
{
	char	c;

	c = 'a' + (nb - 10);
	*(hex[0]) = c;
}

static void	ft_convert_hex(long nb, char ***str)
{
	char	*s;
	long	reste;
	char	*hex;

	hex = ft_memalloc(2);
	s = ft_memalloc(17);
	while (nb > 16)
	{
		reste = nb % 16;
		nb /= 16;
		if (reste > 9)
		{
			ft_modif(reste, &hex);
			s = ft_strcat(s, hex);
		}
		else
			s = ft_strcat(s, ft_itoa(reste));
	}
	if (nb > 9)
	{
		ft_modif(nb, &hex);
		s = ft_strcat(s, hex);
	}
	else
		s = ft_strcat(s, ft_itoa(nb));
	s = ft_reverse(s);
	ft_strcpy(**(str), s);
	free(s);
	free(hex);
}

static void	ft_afficher(char ***str)
{
	char		*s;
	size_t		i;
	unsigned char	c;

	i = 0;
	s = ft_memalloc(ft_strlen(**(str)));
	ft_strcpy(s, **(str));
//	ft_putendl("je suis fonction afficher!!!");
//	ft_putendl(s);
	while (s[i])
	{
		c = 
	}

	c = 0xc3;
	write(1, &c, 1);
	c = 0xa7;
	write(1, &c, 1);
}

void		ft_get_bit(long nb, char **str, char **mask)
{
	long	numb;

	ft_trans_dc_bi(nb, &str);//je recupere la chaine de caracteres avec le bits
//	ft_putendl(*(str));
	ft_trans_dc_bi(49280, &mask);//49280 si le chiffre est compose de moins de 11 bits
	*(str) = ft_reverse(*(str));
//	ft_putendl(*(mask));
	ft_trans_uni_bit(&str, &mask);
//	ft_putendl(*(mask));
	numb = ft_trans_bi_dc(&mask);
	ft_convert_hex(numb, &str);
	ft_putstr("le chiffre decimal : ");
	ft_putnbr(numb);
	ft_putchar('\n');
	ft_putstr("le chiffre hex : ");
	ft_putendl(*(str));
	ft_afficher(&str);
	ft_putnbr(ft_strlen(*(str)));
}
//et ensuite convertir le decimal en hexa avec la fonction deja code
//et ensuite la partager (avec split??) pour envoyer à write
