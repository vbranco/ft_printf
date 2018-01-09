




#include "ft_printf.h"

int	ft_is_string(char *param)
{
	int	len;

	len = ft_strlen(param);
	if (param[len - 1] == 's')
		return (1);
	return (0);
}
