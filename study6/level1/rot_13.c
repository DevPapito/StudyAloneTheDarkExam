#include <unistd.h>
#include <stdio.h>

// utils

static int is_alpha(char c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') );
}

static int is_upper(char c)
{
	return (c >= 'A' && c <= 'Z');
}

// libft
static int ft_strlen(char *s)
{
	int i = 0;
	while (s[i])	
		i++;
	return (i);
}

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		write(1, "\n", 1);
		return (0);
	}
	int i = 0;
	char *word = argv[1];
	int upper = 0;
	char c = 0;
	if (ft_strlen(word) == 0)
	{
		write(1, "\n", 1);
		return (0);
	}
	while (word[i])
	{
		if (is_alpha(word[i]))
		{
			if (is_upper(word[i]))
			{
				word[i] += 32;
				upper = 1;
			}
			if (word[i] <= 'm')
				word[i] += 13;
			else
				word[i] -= 13;
			c = word[i];
			if (upper)
			{
				 c = word[i] - 32;
				upper = 0;
			}			
			write(1, &c, 1);
		}
		else
			write(1, &word[i], 1);
		i++;
	}
	write(1, "\n", 1);
	return (0);
}
