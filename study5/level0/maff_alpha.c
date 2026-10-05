#include <unistd.h>

int main(void)
{
	char ascii = 'a';
	int i = 0;
	char c = 0;
	while (ascii <= 'z')
	{
		if (i % 2 == 1)
			c = ascii - 32;
		else
			c = ascii;
		write(1, &c, 1);
		ascii++;
		i++;
	}
	write(1, "\n", 1);
}
