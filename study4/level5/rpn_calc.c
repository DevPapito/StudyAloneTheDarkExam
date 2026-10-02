#include "rpn_calc.h"

// utils

static int is_especial(char c)
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

static int is_signal(char c)
{
	return (c == '+' || c == '-' || c == '/' || c == '%' || c == '*');
}

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

// atoi

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

// Message

static void	show_error()
{
	write(1, "Error\n", ft_strlen("Error\n"));
}

// stack
static void push(char *stack, int *top, char digit)
{
	stack[*top] = digit;
	(*top)++;
}

static void pop(int *top)
{
	(*top)--;
}

// ft_ltoa

static long count_digit(long nbr)
{
	if (nbr == 0)
		return (0);
	return (1 + count_digit(nbr / 10));
}

static long get_len(long nbr)
{
	if (nbr == 0)
		return (1);
	if (nbr < 0)
		return (1 + count_digit(-nbr));
	return (count_digit(nbr));
}

static char *ft_ltoa(long nbr)
{
	char *result;
	long len = 0;
	len = get_len(nbr);
	result = malloc(len + 1);
	if (result)
		return (NULL);
	result[len] = '\0';
	if (nbr == 0)
	{
		result[0] = '0';
		return (result);
	}
	if (nbr < 0)
	{
		nbr *= -1;
		result[0] = '-';
	}
	while (nbr > 0)
	{
		result[--len] = (nbr % 10) + '0';
		nbr /= 10;
	}
	return (result);
}

// calc

static long calc(long a, long b, char signal)
{
	if (signal == '-')
		return (a - b);
	else if (signal == '+')
		return (a + b);
	else if (signal == '/')
		return (a / b);
	else if (signal == '%')
		return (a % b);
	else if (signal == '*')
		return (a * b);
}

int main(int argc, char **argv)
{
	char stack[4026];
	int top = 0;

	if (argc != 2)
	{
		show_error();
		return (0);
	}
	char *word = argv[1];
	int i = 0;

	while (is_space(word[i]))
		i++;
	while (word[i])
	{
		if (is_space(word[i]))
			i++;
		if (is_signal(word[i]))
		{
			if (is_digit(stack[top - 2]) && is_digit(stack[top - 1])) // em linked list esse sera o problema, principalmente uma simplismente encadeada
			{ // Em listas encadeadas ter que fazer uma funcao auxiliar especifica
				long number0 = ft_atol(stack[top - 2]);
				long number1 = ft_atol(stack[top - 1]);

				stack[top - 2] = ft_ltoa(calc(number0, number1)); // problema usando uma stack estatica
				pop(&top);
			}
			i++;
		}
		else if (is_digit(word[i]))
			push(stack, &top);
		else
		{
			show_error();
			return (0);
		}
		i++;
	}
	return (0);
}
