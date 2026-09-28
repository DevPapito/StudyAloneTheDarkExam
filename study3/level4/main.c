#include <stdlib.h>
#include <stdio.h>

char	*moment(unsigned int duration);

int main(void)
{
	char *result = moment(4294967295);
	printf("%s\n", result);
	free(result);
	return (0);
}
