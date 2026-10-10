#include <unistd.h>
#include <stdlib.h>

#include <stdio.h>

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

static int is_space(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

// ft_split

static char *copy_word(char *s, int size)
{
	char *str;
	int i = 0;

	str = malloc(size);
	if (!str)
		return (NULL);
	while (i < size)
	{
		str[i] = s[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char **ft_split(char *s)
{
	char **split;
	int i = 0;
	int start = 0;
	int word = 0;

	split = malloc(sizeof(char *) * (ft_strlen(s) + 1));
	if (!split)
		return (NULL);
	while (s[i])
	{
		while(is_space(s[i]))
			i++;
		if (!s[i])
			break ;
		start = i;
		while(s[i] && !is_space(s[i]))
			i++;
		split[word] = copy_word(s + start, i - start);
		if (!split[word]) // funcao de limpeza interna
			return (NULL);
		word++;
	}
	split[word] = NULL;
	return (split);
}

// program

static int len_words(char **words)
{
	int i = 0;
	while (words[i])
		i++;
	return (i);
}

static void print(char *s)
{
	while (*s)
	{
		write(1, &(*s), 1);
		s++;
	}
}

static void clear_words(char **words)
{
	int i = 0;
	while (words[i])
		free(words[i]);
	free(words);
}

int main (int argc, char **argv)
{
	if (argc == 1)
	{
		write(1, "\n", 1);
		return (0);
	}
	char *word = argv[1];
	char **words = ft_split(word);
	if (!words)
		return (0);
	int length = len_words(words) - 1;
	int copy = length;
	while (length >= 0)
	{
		print(words[length]);
		if (length != 0)
			write(1, " ", 1);
		length--;
	}
	while (copy >= 0)
	{
		free(words[copy]);
		copy--;
	}
	free(words);
	write(1, "\n", 1);
	return (0);
}
