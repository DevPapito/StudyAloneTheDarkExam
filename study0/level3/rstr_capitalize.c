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

static int is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

static int is_upper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

static void lower(char *word)
{
	while (*word)
	{
		if (is_upper(*word))
			*word += 32;
		word++;
	}
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (1);
	}
	char *word = argv[1];
	char *cpy = word;
	int size = ft_strlen(word) - 1;
	lower(word);
	while (is_space(word[size])) // e special chars
		size--;
	// if caso seja um caracter especial
	word[size] -= 32;
	while (size >= 0)
	{
		if (!is_upper(word[size]))
		{
			if (is_space(word[size - 1]))
				word[size] -= 32;
		}
		size--;
	}
	write(1, word, ft_strlen(cpy));
	write(1, "\n", 1);
	return (0);
}
