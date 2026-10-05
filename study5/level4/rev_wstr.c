#include <unistd.h>
#include <stdlib.h>

static int is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
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

static void free_memory(char **split)
{
	int i = 0;
	while (split[i])
	{
		free(split[i]);
		i++;
	}
	free(split);
}

static char *copy_word(char *word, int size)
{
	char *copy;
	int i = 0;

	copy = malloc(size + 1);
	if (!copy)
		return (NULL);
	while (i < size)
	{
		copy[i] = word[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

static char **ft_split(char *str)
{
	char **split;
	int i = 0;
	int start = 0;
	int word = 0;

	split = malloc(sizeof(char *) * (ft_strlen(str) + 1));
	if (!split)
		return (NULL);
	while (str[i])
	{
		while (is_space(str[i]))
			i++;
		if (!str[i])
			break ;
		start = i;
		while (str[i] && !is_space(str[i]))
			i++;
		split[word] = copy_word(str + start, i - start);
		if (!split[word])
		{
			free_memory(split);
			return (NULL);
		}
		word++;
	}
	split[word] = NULL;
	return (split);
}

// programa

static int len_word(char **words)
{
	int i = 0;
	while (words[i])
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
	char *word = argv[1];
	char **words = ft_split(word);
	int length = len_word(words) - 1;
	while (length >= 0)
	{
		write(1, words[length], ft_strlen(words[length]));
		if (length != 0)
			write(1, " ", 1);
		length--;
	}
	write(1, "\n", 1);
	free_memory(words);
	return (0);
}
