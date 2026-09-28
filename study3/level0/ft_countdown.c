#include <unistd.h>

int	main(int argc, char **argv)
{
	(void)argc;
	(void)argv;
	char ascii = '9';
	while (ascii >= '0')
	{
		write(1, &ascii, 1);
		ascii--;
	}
	write(1, "\n", 1);
	return (0);
}
