#include <unistd.h>

// atoi

static int is_special(char c)
{
	return (c >= 9 && c <= 13);
}

static int is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
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

// putnbr

static void ft_putnbr(int n)
{
	if (n < 0)
	{
		write(1, "-", 1);
		n *= -1;
	}
	if (n >= 10)
		ft_putnbr(n / 10);
	char c = n % 10 + '0';
	write(1, &c, 1);
}

static int calc(int num1, char op, int num2)
{
	if (op == '+')
		return (num1 + num2);
	else if (op == '-')
		return (num1 - num2);
	else if (op == '*')
		return (num1 * num2);
	else if (op == '/')
		return (num1 / num2);
	else if (op == '%')
		return (num1 % num2);
	return (0);
}

int main(int argc, char **argv)
{
	if (argc != 4)
	{
		write(1, "\n", 1);
		return (1);
	}
	char *st1 = argv[1];
	char *op = argv[2];
	char *st2 = argv[3];

	int num1 = ft_atoi(st1);
	int num2 = ft_atoi(st2);

	int result = calc(num1, *op, num2);
	ft_putnbr(result);
	write(1, "\n", 1);
	return (0);
}
