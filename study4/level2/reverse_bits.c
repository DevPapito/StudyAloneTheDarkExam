unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char mask = 0;
	int i = 7;
	while (i >= 0)
	{
		mask = (mask << 1) | (octet & 1);
		octet >>= 1;
		i--;
	}
	return (mask);
}
