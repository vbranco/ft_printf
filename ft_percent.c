//en tete

#include "ft_printf.h"

static int	ft_p(const char *format, t_form *form)
{
	char	*str;
	int	i;
//	int	z;

	i = 0;
	while (format[i])
		i++;
	str = ft_memalloc(form->min + form->prec + 3);
	ft_strcat(str, "%");
	form->size = i;
	return (write (1, str, ft_strlen(str)));
}

int		ft_percent(const char *format, t_form *form)
{
	ft_recup_type(format, form);
	ft_recup_length(format, form);
	ft_recup_min(format, form);
	ft_recup_prec(format, form);
	ft_recup_flag(format, form);
	if (form->type != '\0')
		return (0);
	else
		return (ft_p(format, form));

}
