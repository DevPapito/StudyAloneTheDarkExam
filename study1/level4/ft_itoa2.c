#include <stdlib.h>

static void len_int(int nbr, int *len)
{
	(*len)++;
	if (nbr < 0)
	{
		nbr *= -1;
		(*len)++;
	}
	if (nbr >= 10)
		len_int(nbr / 10, len);
}

char	*ft_itoa(int nbr)
{
	char	*result;
	int	len = 0;

	if (nbr == -2147483648)
		return ("-2147483648");
	len_int(nbr, &len);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	result[len + 1] = '\0';

	if (nbr == 0)
	{
		result[0] = '0';
		return (result);
	}
	if (nbr < 0)
	{
		nbr *= -1;
		result[0] = '-';
	}
	while (nbr)
	{
		result[--len] = nbr % 10 + '0';
		nbr /= 10;
	}
	if (nbr > 0)
		result[0] = nbr % 10 + '0';
	return (result);
}
