#include <stdlib.h>

static int count(int start, int end)
{
	int count = 1;
	if (end < 0)
		end *= -1;
	while (start < end)
	{
		count++;
		start++;
	}
	return (count);
}

int	*ft_rrange(int start, int end)
{
	int length = count(start, end);
	int *tab = malloc(sizeof(int) * length);
	int negative = 0;
	int i = 0;
	if (!tab)
		return (NULL);
	if (end < 0)
	{
		end *= -1;
		negative = 1;
	}
	while (end >= start)
	{
		if (negative)
			tab[i] = end * -1;
		else
			tab[i] = end;
		end--;
		i++;
	}
	return (tab);
}
