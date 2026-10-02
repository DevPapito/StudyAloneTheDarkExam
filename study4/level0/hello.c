#include <unistd.h>

static int ft_strlen(char *s)
{
	int count = 0;
	while (*s)
	{
		count++;
		s++;
	}
	return (count);
}

int main(void)
{
	write(1, "Hello World!\n", ft_strlen("Hello World!\n"));
	return (0);
}
