#include <unistd.h>

static int ft_strlen(const char *str)
{
	int count;

	count = 0;
	while (*str)
	{
		str++;
		count++;
	}
	return (count);
}

int main(int argc, char **argv)
{
	if (argc != 3)
	{
		write(1, "\n", 1);
		return (1);
	}
	char *arg1 = argv[1];
	char *arg2 = argv[2];
	int size = ft_strlen(arg1);
	int length = 0;
	char *pa = arg1;
	while (*arg2)
	{
		if (*arg2 == *arg1)
		{
			arg1++;
			length++;
		}
		arg2++;
	}
	int i = 0;
	if (length < size)
	{
		write(1, "\n", 1);
		return (1);
	}
	write(1, pa, ft_strlen(pa));
	write(1, "\n", 1);
	return (0);
}
