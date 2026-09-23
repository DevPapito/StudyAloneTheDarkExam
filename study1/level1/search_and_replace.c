#include <unistd.h>

static int ft_strlen(const char *s)
{
	int count;

	count = 0;
	while (*s)
	{
		count++;
		s++;
	}
	return (count);
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		write(1, "\n", 1);
		return (1);
	}
	char *word = argv[1];
	char *search = argv[2];
	char *replace = argv[3];

	if (ft_strlen(search) > 1 || ft_strlen(replace) > 1)
	{
		write(1, "\n", 1);
		return (1);
	}
	while (*word)
	{
		if (*word == *search)
			write(1, &(*replace), 1);
		else
			write(1, &(*word), 1);
		word++;
	}
	write(1, "\n", 1);
	return (0);
}
