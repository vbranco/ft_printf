#include "ft_printf.h"

void     ft_d_prec(char *str, t_form *form)
{
	int             len;
	int             i;
	char            *s1;

	i = 0;
	s1 = NULL;
	len = ft_strlen(str);
	if (form->prec == 0 && str[0] == '0')
		str[0] = '\0';
	if (form->prec > len)
	{
		s1 = ft_memalloc(form->prec);
		ft_add_str_begin(str, ft_memset(s1, '0', (form->prec - len)));
	}
	free(s1);
}
