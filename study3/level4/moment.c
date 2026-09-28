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

static char *ft_strcpy(char *dst, char *src, int start)
{
	int i = start;
	int j = 0;
	while (src[j])
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (dst);
}

// ltoa

static int count_num(long n)
{
	if (n == 0)
		return (0);
	return (1 + count_num(n / 10));
}

static int get_len(long n)
{
	if (n == 0)
		return (1);
	if (n < 0)
		return (1 + count_num(-n));
	return (count_num(n));
}

static char	*ft_ltoa(unsigned int nbr)
{
	char	*result;
	int len;
	long n = nbr;
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

char	*moment(unsigned int duration)
{
	char	*word;

	long minute = 60L;
	long hour = minute * 60L;
	long day = hour * 24L;
	long month = day * 30L;
	long time = 0;

	if (duration >= month)
	{
		word = " months ";
		time = duration / month;
		if (time == 1)
			word = " month ";
	}
	else if (duration >= day)
	{
		word = " days ";
		time = duration / day;
		if (time == 1)
			word = " day ";
	}
	else if (duration >= hour)
	{
		word = " hours ";
		time = duration / hour;
		if (time == 1)
			word = " hour ";
	}
	else if (duration >= minute)
	{
		word = " minutes ";
		time = duration / minute;
		if (time == 1)
			word = " minute ";
	}
	else
	{
		time = duration;
		word = " seconds ";
		if (time == 1)
			word = " second ";
	}

	char *digit = ft_ltoa(time);
	int len_digit = ft_strlen(digit);
	int len_word = ft_strlen(word);
	int len_ago = ft_strlen("ago.");
	char *result = malloc(len_word + len_digit + len_ago + 1);
	if (!result)
		return (NULL);
	result[len_word + len_digit + len_ago] = '\0';
	ft_strcpy(result, digit, 0);
	ft_strcpy(result, word, len_digit);
	ft_strcpy(result, "ago.", len_word + len_digit);
	free(digit);
	return (result);
}
