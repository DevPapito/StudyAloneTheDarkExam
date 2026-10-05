#include <unistd.h>

static void ft_putnbr(int number)
{
	if (number >= 10)
		ft_putnbr(number / 10);
	char c = (number % 10) + '0';
	write(1, &c, 1);
}

int main(void)
{
	int i = 1;
	while (i <= 100)
	{
		int tree = i % 3 == 0;
		int five = i % 5 == 0;
		int both = tree + five;

		if (both == 2)
			write(1, "fizzbuzz", 8);
		else if (tree)
			write(1, "fizz", 4);
		else if (five)
			write(1, "buzz", 4);
		else
			ft_putnbr(i);
		write(1, "\n", 1);
		i++;
	}
	return (0);
}
