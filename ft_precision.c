//en tete

#include "ft_printf.h"

int	ft_precision(char *str, t_form *form)
{
	int	len;
	char	*s1;

	len = ft_strlen(str);
	s1 = ft_memalloc(form->prec - len);
	ft_add_str_begin(str, ft_memset(s1, '0', (form->prec - len)));
	free(s1);
	return (ft_strlen(str));
}
