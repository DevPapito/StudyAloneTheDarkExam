#include <stdio.h>

char	*ft_itoa(int nbr);

int main(void)
{
	char *num = ft_itoa(10);
	printf("%s\n", num);
	char *num2 = ft_itoa(-242431510);
	printf("%s\n", num2);
}
