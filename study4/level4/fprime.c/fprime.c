#include <unistd.h>

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

static long ft_atol(char *str)
{
	long result = 0L;
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

static void ft_putnbr(long number)
{
	if (number >= 10)
		ft_putnbr(number / 10);
	char c = (number % 10) + '0';
	write(1, &c, 1);
}

int main(int argc, char **argv)
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
	if (number == 1)
	{
		write(1, "1\n", 2);
		return (0);
	}
	int i = 2;
	int flag = 0;
	while (i <= number)
	{
		if (number % i == 0)
		{
			if (flag)
			{
				write(1, "*", 1);
				flag = 0;
			}
			else
			{
				ft_putnbr(i);
				number /= i;
				flag = 1;
			}
		}
		else
			i++;
	}
	write(1, "\n", 1);
	return (0);
}
