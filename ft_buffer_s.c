#include "ft_printf.h"

static void	ft_precision_s(char *str, t_form *form)
{
	int		i;

	i = 0;
	if (form->prec > -1)
	{
		while (i < form->prec)
			i++;
		str[i] = '\0';
	}
}

void	ft_buffer_s(char *str, t_form *form)
{
	char	*s1;
	int		len;

	ft_precision_s(str, form);
	len = ft_strlen(str);
	s1 = ft_memalloc(form->min);
	if (form->min > len)
	{
		if (form->is_n == 1)
			ft_add_str_end(str, ft_memset(s1, ' ', (form->min - len)));
		else if (form->is_z == 1)
			ft_add_str_begin(str, ft_memset(s1, '0', (form->min - len)));
		else if (form->is_n == 0)
			ft_add_str_begin(str, ft_memset(s1, ' ', (form->min - len)));
	}
	free(s1);
}
