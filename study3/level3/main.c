#include <stdio.h>

int	*ft_rrange(int start, int end);

int main(void)
{
	int *tab = ft_rrange(1, 3);
	for (int i = 0; i < 3; i++)
		printf("%d ", tab[i]);

	return (0);
}
