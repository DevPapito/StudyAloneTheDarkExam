#include <stdio.h>
#include <unistd.h>

unsigned char	swap_bits(unsigned char octet);

void	print_bits(unsigned char octet)
{
	int i = 7;
	while (i >= 0)
	{
		if (i == 3)
			write(1, "_", 1);
		if ((octet >> i) & 1)
			write(1, "1", 1);
		else
			write(1, "0", 1);		
		i--;
	}
	write(1, "\n", 1);
}

int	main(void)
{
	unsigned char res = swap_bits(65);
	print_bits(65);
	print_bits(res);
	printf("%d\n",res);
	return (0);
}
