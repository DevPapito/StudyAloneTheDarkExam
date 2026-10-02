#include "list.h"
#include <unistd.h>

// utils

static int is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

static int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

static int is_especial(char c)
{
	return (c >= 9 && c <= 13);
}

static int is_signal(char c)
{
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

// ft_strlen

static int ft_strlen(char *s)
{
	int count = 0;

	while  (*s)
	{
		count++;
		s++;
	}
	return (count);
}

// ft_atol

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

// ft_putnbr

static void ft_putnbr(long nbr)
{
	if (nbr < 0)
	{
		nbr *= -1;
		write(1, "-", 1);
	}
	if (nbr >= 10)
		ft_putnbr(nbr / 10);
	char c = (nbr % 10) + '0';
	write(1, &c, 1);
}

// program

static void	show_error_message(void)
{
	write(1, "Error\n", 6);
}

static long calc(long a, long b, char signal)
{
	if (signal == '+')
		return (a + b);
	else if (signal == '-')
		return (a - b);
	else if (signal == '*')
		return (a * b);
	else if (signal == '/')
		return (a / b);
	else if (signal == '%')
		return (a % b);
	return (0);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		show_error_message();
		return (0);
	}
	char *word = argv[1];
	int i = 0;
	int length = 0;
	char *result;
	int start = 0;
	t_list *node;

	t_list *head = node_init();
	if (!head)
		return (0);
	while (is_space(word[i]))
		i++;
	if (!word[i] && ft_strlen(word) >= 0)
	{
		show_error_message();
		return (0);
	}
	while (word[i])
	{
		if (is_signal(word[i]))
		{
			if (!head && !head->next)
			{
				show_error_message();
				return (0);
			}
			long result = calc(head->next->data, head->data, word[i]);
			pop_front(&head);
			head->data = result;
		}
		if (is_digit(word[i]))
		{
			start = i;
			while (word[i] && is_digit(word[i]))
			{
				length++;
				i++;
			}
			result = malloc(length + 1);
			if (!result)
				return (0);
			int j = 0;
			while (start < i)
			{
				result[j] = word[start];
				j++;
				start++;
			}
			result[j] = '\0';
			if (head->data == -1L)
				head->data = ft_atol(result);
			else
			{
				node = node_init();
				if (!node)
					return (0);
				node->data = ft_atol(result);
				push_front(&head, node);
			}
			length = 0;
			free(result);
			result = NULL;
		}
		else
			i++;
	}
	if (list_len(&head) != 1)
	{
		show_error_message();
		return (0);
	}
	ft_putnbr(head->data);
	destroy_list(&head);
	write(1, "\n", 1);
	return (0);
}
