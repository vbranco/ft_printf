


#include "ft_printf.h"

char	**ft_format_spec(char **recup)
{
	int	i;
	int	j;
	char	**params;

	i = 0;
	while (recup[i++]);
	if (!(params = (char**)malloc(sizeof(char*) * (i))))
		return (NULL);
	i = 0;
	while (recup[i])
	{
		j = 0;
		while (recup[i][j] != ' ' && recup[i][j] != ',' && recup[i][j])
			j++;
		params[i] = ft_strsub(recup[i] , 0, j);
		i++;
	}
	params[i] = 0;
	return (params);
}
