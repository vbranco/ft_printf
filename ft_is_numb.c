



#include "ft_printf.h"

int	ft_is_numb(char *param)
{
	int	len;

	len = ft_strlen(param);
	if (param[len - 1] == 'd')
		return (1);
	return (0);
}
