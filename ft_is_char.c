



#include "ft_printf.h"

int	ft_is_char(char	*param)
{
	int	len;

	len = ft_strlen(param);
	if (param[len - 1] == 'c')
		return (1);
	return (0);
}
