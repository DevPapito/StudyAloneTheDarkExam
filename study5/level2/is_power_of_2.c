int is_power_of_2(int n)
{
	return n > 0 && (n & (n - 1)) == 0;
}
