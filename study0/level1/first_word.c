#include <unistd.h>

static int	is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	char *word = argv[1];
	while (is_space(*word))
		word++;
	while (*word)
	{
		if (is_space(*word))
			break ;
		write(1, &(*word), 1);
		word++;
	}
	write(1, "\n", 1);
	return (0);
}
