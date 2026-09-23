char	*ft_itoa(int nbr);

#include <stdio.h>
int main(void)
{
	char *result = ft_itoa(-42);
	printf("%s", result);
	return (0);
}
