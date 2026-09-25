#include <unistd.h>

static int is_pritable(char c)
{
	return (c >= 32 && c <= 126);
}

static void	ft_putchar(char c)
{
	write(1, &c, 1);
}

static void	print_hex(unsigned int num, char *base)
{
	ft_putchar(base[num / 16]);
	ft_putchar(base[num % 16]);
}

void	print_memory(const void *addr, size_t size)
{
	char *base = "0123456789abcdef";
	unsigned char *naddr = (unsigned char *)addr;
	size_t i = 0;
	while (i < size)
	{
		int j = 0;
		while (j < 16)
		{
			if ((i + j) < size)
				print_hex(naddr[i + j], base);
			else
				write(1, "  ", 2);
			if (j % 2 != 0)
					write(1, " ", 1);
			j++;
		}
		j = 0;
		while (j < 16 && (i + j) < size)
		{
			if (is_pritable(naddr[i + j]))
				write(1, &naddr[i + j], 1);
			else
				write(1, ".", 1);
			j++;
		}
		i += 16;
		write(1, "\n", 1);
	}
}
