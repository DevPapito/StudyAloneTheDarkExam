#include <unistd.h>

static int is_upper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	char *word = argv[1];
	int index = 0;
	while (*word)
	{
		if (is_upper(*word))
			index = *word - 'A';
		else
			index = *word - 'a';
		while (index >= 0)
		{
			write(1, &(*word), 1);
			index--;
		}
		word++;
	}
	write(1, "\n", 1);
	return (0);
}
