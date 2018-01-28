//en tete

#include "ft_printf.h"

void		ft_buffer_d(char *str, t_form *form)
{
	char	*s1;

	s1 = ft_memalloc(form->min);
	if (form->is_p == 1 && *str != '-')
		ft_add_str_begin(str, "+");
	if (form->is_n == 1 && form->min >= 0)
	{
		if ((size_t)form->min > ft_strlen(str))
		{
			if (form->is_z == 1)
				ft_add_str_end(str, ft_memset(s1, '0',
				(form->min - ft_strlen(str))));
			else
				ft_add_str_end(str, ft_memset(s1, ' ',
				(form->min - ft_strlen(str))));
		}
	}
//	ft_putnbr(form->min);
	if (form->min >= 0)
	{
		if ((unsigned long)form->min > ft_strlen(str))
		{
			ft_memset(s1, ' ', (form->min - ft_strlen(str)));
//			ft_putstr("la taille de s1 : ");
//			ft_putnbr(ft_strlen(s1));
			ft_add_str_begin(str, s1);
//			ft_putstr(str);
//			ft_add_str_begin(str, ft_memset(s1, ' ', (form->min - ft_strlen(str))));
		}
	}
	free(s1);
}
