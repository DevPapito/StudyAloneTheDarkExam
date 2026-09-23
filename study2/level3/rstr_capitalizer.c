#include <unistd.h>

static int is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

static int is_special(char c)
{
	int special0 = c >= 0 && c <= 64;
	int special1 = c >= 91 && c <= 96;
	int special2 = c >= 123 && c <= 127;
	return (special0 || special1 || special2);
}

static int ft_strlen(char *s)
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

static int is_upper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

static int is_lower(char c)
{
	return (c >= 'a' && c <= 'z');
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

static void rstr_capitalize(char *word)
{
	int i = ft_strlen(word);
	lower(word);
	while (is_space(word[i]) || is_special(word[i]))
		i--;
	if (is_lower(word[i]))
		word[i]	-= 32;
	i--;
	while (word[i])
	{
		if (is_space(word[i]))
		{
			if (is_lower(word[i - 1]))
				word[i - 1] -= 32;
		}
		i--;
	}
}

static void print(char *word)
{
	while (*word)
	{
		write(1, &(*word), 1);
		word++;
	}
	write(1, "\n", 1);
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		write(1, "\n", 1);
		return (1);
	}
	int i = 1;
	while (argv[i])
	{
		rstr_capitalize(argv[i]);
		print(argv[i]);
		i++;
	}
	return (0);
}
