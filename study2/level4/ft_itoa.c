#include <stdlib.h>

static int count_digits(long n)
{
	if (n == 0)
		return (0);
	return (1 + count_digits(n / 10));
}

static int get_len(long n)
{
	if (n == 0)
		return (1);
	if (n < 0)
		return (1 + count_digits(--n));
	return (count_digits(n));
}

char	*ft_itoa(int nbr)
{
	char *result;
	int len;
	long n = 0;

	n = nbr;
	len = get_len(n);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (n == 0)
	{
		result[0] = '0';
		return (result);
	}
	if (n < 0)
	{
		n *= -1;
		result[0] = '-';
	}
	while (n > 0)
	{
		result[--len] = n % 10 + '0';
		n /= 10;
	}
	return (result);
}
