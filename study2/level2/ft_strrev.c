static int ft_strlen(char *s)
{
	int count;

	count = 0;
	while (*s)
	{
		s++;
		count++;
	}
	return (count);
}

char	*ft_strrev(char *str)
{
	int len = ft_strlen(str);
	int start = 0;
	char c = 0;

	while (str[start] && start != len / 2)
	{
		c = str[(len - 1) - start];
		str[(len - 1) - start] = str[start];
		str[start] = c;
		start++;
	}
	return (str);
}
