#include <unistd.h>
#include <stdio.h>

// utils

static int is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

static int is_lower(char c)
{
	return (c >= 'a' && c <= 'z');
}

static int is_upper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

static void lower(char *s)
{
	while (*s)
	{
		if (is_upper(*s))
			*s += 32;
		s++;
	}
}

static void str_capitalizer(char *s)
{
	while (is_space(*s))
		s++;
	if (is_lower(*s))
		*s -= 32;
	while (*s)	
	{
		if (is_space(*s))
		{
			if ((*(s + 1)) && is_lower(*(s + 1)))
				(*(s + 1)) -= 32;
		}
		s++;
	}
}

static void print(char *s)
{
	while (*s)
	{
		write(1, &(*s), 1);
		s++;
	}
	write(1, "\n", 1);
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	int i = 1;
	while (argv[i])	
	{
		lower(argv[i]);
		str_capitalizer(argv[i]);
		print(argv[i]);
		i++;
	}
	return (0);
}
