#include <unistd.h>

static void print_hex(long number, char *base)
{
	if (number >= 16)
		print_hex(number / 16, base);
	char c = base[number % 16];
	write(1, &c, 1);
}

static int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static int is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

static int is_espace(char c)
{
	return (c >= 9 && c <= 13);
}

static long ft_atol(char *str)
{
	long result = 0;
	int signal = 1;

	while (is_space(*str) || is_espace(*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			signal *= -1;
		str++;
	}
	while (*str && is_digit(*str))
	{
		result = (result * 10) + (*str - '0');
		str++;
	}
	return (result * signal);
}

int main(int argc, char  **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	long number = ft_atol(argv[1]);
	if (number < 0)
	{
		write(1, "\n", 1);
		return (0);
	}
	char *base = "0123456789abcdef";
	print_hex(number, base);
	write(1, "\n", 1);
	return (0);
}
