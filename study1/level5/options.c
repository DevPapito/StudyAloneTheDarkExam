#include <unistd.h>

static int is_valid_flag(char c)
{
	return (c == '-');
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

static int is_flag_option(char *word)
{
	if (is_valid_flag(*word))
	{
		word++;
		while (*word)
		{
			if (*word == 'h')
				return (1);
			word++;
		}
	}
	return (0);
}

static void show_option(void)
{
	write(1, "options: ", ft_strlen("options: "));
	char ascii = 'a';
	while (ascii <= 'z')
	{
		write(1, &ascii, 1);
		ascii++;
	}
	write(1, "\n", 1);
}

static void show_invalid(void)
{
	write(1, "Invalid Option", ft_strlen("Invalid Option"));
	write(1, "\n", 1);
}

static int is_upper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

static int is_lower(char c)
{
	return (c >= 'a' && c <= 'z');
}

static void	ft_set_bit(unsigned int *num, unsigned int index)
{
	unsigned int n = 1 << index;
	*num = *num | n;
}

static int	options(char *word, unsigned int *flag)
{
	char *cpy = word;
	unsigned int bit = 0;

	while (*word)
	{
		if (!is_lower(*word))
			return (0);
		word++;
	}
	word = cpy;
	while (*word)
	{
		unsigned int index = *word - 'a';
		ft_set_bit(flag, index);
		word++;
	}
	return (1);
}

static void print_bits(unsigned int num)
{
	int index = 31;

	while (index >= 0)
	{
		if (index == 23)
			write(1, " ", 1);
		if (index == 14)
			write(1, " ", 1);
		if (index == 7)
			write(1, " ", 1);
		if ((num >> index) & 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);
		index--;
	}
	write(1, "\n", 1);
}

int main(int argc, char **argv)
{
	unsigned int flag = 0;
	if (argc == 1)
	{
		show_option();
		return (1);
	}
	int i = 1;

	while (argv[i])
	{
		if (is_flag_option(argv[i]))
		{
			show_option();
			return (1);
		}
		i++;
	}
	i = 1;
	while (argv[i])
	{
		if (is_valid_flag(argv[i][0]))
		{
			if (ft_strlen(argv[i]) == 1)
			{
				show_invalid();
				return (1);
			}
			argv[i]++;
			if (!options(argv[i], &flag))
			{
				show_invalid();
				return (1);
			}
		}
		else
		{
			show_invalid();
			return (1);
		}
		i++;
	}
	print_bits(flag);
	return (0);
}
