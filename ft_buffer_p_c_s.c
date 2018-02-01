//en tete

#include "ft_printf.h"

void	ft_precision_s(char *str, t_form *form)
{
	int	i;

	i = 0;
	while (i < form->prec)
		i++;
	str[i] = '\0';
}

void	ft_buffer_p_c_s(char *str, t_form *form)
{
	char	*s1;
	int	len;

	len = ft_strlen(str);
	s1 = ft_memalloc(form->min);
	if (form->prec >= 0 && (form->type == 's' || form->type == 'S'))
		ft_precision_s(str, form);
	if (form->min > len)
	{
		if (form->is_n == 1)
			ft_add_str_end(str, ft_memset(s1, ' ',
			(form->min - len)));
		else if (form->is_n == 0)
			ft_add_str_begin(str, ft_memset(s1, ' ',
			(form->min - len)));
	}
	free(s1);
}
