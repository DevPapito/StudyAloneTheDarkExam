#include <unistd.h>

void	ft_print_numbers(void)
{
	char ascii = '0';
	while (ascii <= '9')
	{
		write(1, &ascii, 1);
		ascii++;
	}
}
