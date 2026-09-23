#include <unistd.h>

static int ft_strlen(const char *s)
{
	int count;

	count = 0;
	while (*s)
	{
		s++;
		count++;
	}
	return (count);
}

int	main(int argc, char **argv)
{
	if (argc == 1)
	{
		write(1, "\n", 1);
		return (1);
	}
	write(1, argv[1], ft_strlen(argv[1]));
	write(1, "\n", 1);
	return (0);
}
