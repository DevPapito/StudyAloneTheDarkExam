#include <unistd.h>

// utils

static int is_flag(char c)
{
	return (c == '-');
}

static int is_alpha(char c)
{
	return (c >= 'a' && c <= 'z');
}

// program

static void ft_set_bits(unsigned int *flag, char code)
{
	*flag = *flag | 1 << code;
}

static void show_options(void)
{
	char ascii = 'a';
	write(1, "options: ", 9);
	while (ascii <= 'z')
	{
		write(1, &ascii, 1);
		ascii++;
	}
	write(1, "\n", 1);
}

static void show_message_error(void)
{
	write(1, "Invalid Option\n", 15);
}

static int find_invalid_char(char **argv)
{
	int i = 1;
	while (argv[i])
	{
		int j = 0;
		while (argv[i][j])
		{
			if (!is_alpha(argv[i][j]) && !is_flag(argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static int find_invalid_command(char **argv)
{
	int i = 1;
	while (argv[i])
	{
		if (argv[i][0] != '-')
			return (1);
		if (!is_alpha(argv[i][0 + 1]))
			return (1);
		i++;
	}
	return (0);
}

static int find_flag(char **argv)
{
	int i = 1;
	while (argv[i])
	{
		int j = 0;
		while (argv[i][j])
		{
			if (argv[i][j] == 'h')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static void options(char *word, unsigned int *flag)
{
	char code = 0;
	while (*word)
	{
		if (is_flag(*word))
			word++;
		code = *word - 'a';
		ft_set_bits(flag, code);
		word++;
	}
}

static void print_bits(unsigned int *flag)
{
	int i = 31;
	while (i >= 0)
	{
		if (i == 23)
			write(1, " ", 1);
		else if (i == 15)
			write(1, " ", 1);
		else if (i == 7)
			write(1, " ", 1);
		if ((*flag >> i) & 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		i--;
	}
	write(1, "\n", 1);
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		show_options();
		return (0);
	}
	unsigned int flag = 0;
	int i = 1;
	if (find_invalid_char(argv) || find_invalid_command(argv))
	{
		show_message_error();
		return (0);
	}
	if (find_flag(argv))
	{
		show_options();
		return (0);
	}
	while (argv[i])
	{
		options(argv[i], &flag);
		i++;
	}
	print_bits(&flag);
	return (0);
}
