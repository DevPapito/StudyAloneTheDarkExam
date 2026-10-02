#include <unistd.h>
#include <stdlib.h>

// utils

static int ft_strlen(char *s)
{
	int count = 0;
	while (*s)
	{
		count++;
		s++;
	}
	return (count);
}

// ft_atol

static int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static int is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

static int is_especial(char c)
{
	return (c >= 9 && c <= 13);
}

static long ft_atol(char *str)
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

// ft_ltoa

static long count_digit(long n)
{
	if (n == 0)
		return (0);
	return (1 + count_digit(n / 10));
}

static long get_len(long n)
{
	if (n == 0)
		return (1);
	if (n < 0)
		return (1 + count_digit(-n));
	return (count_digit(n));
}

static char	*ft_ltoa(long n)
{
	long len = 0;
	char *result;

	len = get_len(n);
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	result[len] = '\0';
	if (n == 0)
	{
		result[0] = '0';
		return (result);
	}
	if (n < 0)
	{
		n *= -1;
		result[0] = '-';
	}
	while (n > 0)
	{
		result[--len] = (n % 10) + '0';
		n /= 10;
	}
	return (result);
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
		char c = 1 + '0';
		write(1, &c, 1);
		write(1, "\n", 1);
		return (0);
	}
	int i = 2;
	int flag = 0;
	char *result;
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
				result = ft_ltoa(i);
				write(1, result, ft_strlen(result));
				free(result);
				flag = 1;
				number /= i;
			}
		}
		else
			i++;
	}
	write(1, "\n", 1);
	return (0);
}
