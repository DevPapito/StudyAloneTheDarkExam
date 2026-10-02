#include <unistd.h>

// utils

static int is_prime(long n)
{
	int i = 2;

	if (n <= 1)
		return (0);
	while (i * i <= n)
	{
		if (n % i == 0)
			return (0);
		i++;
	}
	return (1);
}

// ft_atol

static int is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

static int is_especial(char c)
{
	return (c >= 9 && c <= 13);
}

static int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static int ft_atol(char *str)
{
	long result = 0;
	int signal = 1;

	while (is_space(*str) || is_especial(*str))
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

// putnbr

static void ft_putnbr(long n)
{
	if (n >= 10)
		ft_putnbr(n / 10);
	char c = n % 10 + '0';
	write(1, &c, 1);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "0\n", 2);
		return (0);
	}
	long number = ft_atol(argv[1]);
	if (number < 0)
	{
		write(1, "0\n", 2);
		return (0);
	}
	long i = 2;
	long soma = 0;
	while (i <= number)
	{
		if (is_prime(i))
			soma += i;
		i++;
	}
	ft_putnbr(soma);
	write(1, "\n", 1);
	return (0);
}
