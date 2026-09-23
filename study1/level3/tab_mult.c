#include <unistd.h>

static int is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

static int is_special(char c)
{
	return (c >= 9 && c <= 13);
}

static int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static int ft_atoi(char *s)
{
	int result;
	int signal;

	result = 0;
	signal = 1;
	while (is_space(*s) || is_special(*s))
		s++;
	if (*s == '+' || *s == '-')
	{
		if (*s == '-')
			signal *= -1;
		s++;
	}
	while (*s && is_digit(*s))
	{
		result = (result * 10) + (*s - '0');
		s++;
	}
	return (result * signal);
}

static void ft_putnbr(int n)
{
	if (n < 0)
	{
		n *= -1;
		write(1, "-", 1);
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	char c = n % 10 + '0';
	write(1, &c, 1);
}

int main(int argc, char **argv)
{
	if (argc == 1)
	{
		write(1, "\n", 1);
		return (1);
	}

	int number = 0;
	if (is_digit(argv[1][0]))
		number = ft_atoi(argv[1]);
	int i = 1;
	int result = 0;
	while (i < 10)
	{
		result = i * number;
		char si = i + '0';
		write(1, &si, 1);
		write(1, " x ", 3);
		ft_putnbr(number);
		write(1, " = ", 3);
		ft_putnbr(result);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
