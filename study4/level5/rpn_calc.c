#include <unistd.h>
#include "stack.h"

// utils

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
	return (c == '+' || c == '-' || c == '*' || c == '/' || c == '%');
}

static int is_espace(char c)
{
	return (c >= 9 && c <= 13);
}

// ft_libft

static long ft_atol(char *str, size_t *i)
{
	long result = 0L;
	int signal = 1;

	while (is_space(str[*i]) || is_espace(str[*i]))
		(*i)++;
	if (str[*i] == '+' || str[*i] == '-')
	{
		if (str[*i] == '-')
			signal *= -1;
		(*i)++;
	}
	while (str[*i] && is_digit(str[*i]))
	{
		result = (result * 10L) + (str[*i] - '0');
		(*i)++;
	}
	return (result * signal);
}

static void ft_putnbr(long number)
{
	if (number < 0)
	{
		number *= -1;
		write(1, "-", 1);
	}
	if (number >= 10)
		ft_putnbr(number / 10);
	char c = (number % 10) + '0';
	write(1, &c, 1);
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

// program rpn_calc

static void	show_message_error(void)
{
	write(1, "Error\n", 6);
}

static int is_invalid_char(char *word)
{
	int i = 0;

	while (word[i])
	{
		if (!is_digit(word[i]) && !is_space(word[i]) && !is_signal(word[i]))
			return (1);
		i++;
	}
	return (0);
}

static long calc(long a, long b, char signal, int *error)
{
	if (signal == '+')
		return (a + b);
	else if (signal == '-')
		return (a - b);
	else if (signal == '*')
		return (a * b);
	else if (signal == '/')
	{
		if (b == 0)
		{
			*error = 1;
			return (-1);
		}
		return (a / b);
	}
	else if (signal == '%')
	{
		if (b == 0)
		{
			*error = 1;
			return (-1);
		}
		return (a % b);
	}
	return (0);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		show_message_error();
		return (0);
	}
	t_node *stack;
	char	*word;
	size_t	i = 0;
	int count_space = 0;

	word = argv[1];
	stack = node_init();
	if (!stack)
		return (0);
	if (is_invalid_char(word))
	{
		show_message_error();
		destroy_stack(&stack);
		return (0);
	}
	while (is_space(word[i]))
	{
		count_space++;
		i++;
	}
	if (ft_strlen(word) == count_space)
	{
		show_message_error();
		destroy_stack(&stack);
		return (0);
	}
	while (word[i])
	{
		if (is_signal(word[i]))
		{
			if (word[i + 1] && is_digit(word[i + 1]))
			{
				long number = ft_atol(word, &i);

				if (stack->data == -1)
					stack->data = number;
				else
				{
					t_node *node = node_init();
					node->data = number;
					push_front(&stack, node);
				}
			}
			else
			{
				if (!stack->next || !stack)
				{
					show_message_error();
					destroy_stack(&stack);
					return (0);
				}
				int error = 0;
				stack->next->data = calc(stack->next->data, stack->data, word[i], &error);
				if (error)
				{
					show_message_error();
					destroy_stack(&stack);
					return (0);
				}
				pop_front(&stack);
				i++;
			}
		}
		else if (is_digit(word[i]))
		{
			long number = ft_atol(word, &i);

			if (stack->data == -1)
				stack->data = number;
			else
			{
				t_node *node = node_init();
				node->data = number;
				push_front(&stack, node);
			}
		}
		else
			i++;
	}
	if (stack->next)
		show_message_error();
	else
	{
		ft_putnbr(stack->data);
		write(1, "\n", 1);
	}
	destroy_stack(&stack);
	return (0);
}
