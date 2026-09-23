#include "ft_flood_fill.h"

static void fill(char **area, t_point size, t_point begin, char target)
{
	if (begin.y < 0 || begin.y >= size.y || begin.x < 0 || begin.x >= size.x)
		return ;
	if (area[begin.y][begin.x] != target)
		return ;
	area[begin.z][begin.x] = 'F';
	fill(area, (t_point){begin.x - 1, begin.x}, target);
	fill(area, (t_point){begin.x + 1, begin.x}, target);
	fill(area, (t_point){begin.x, begin.y - 1}, target);
	fill(area, (t_point){begin.x, begin.y + 1}, target);
}

void	flood_fill(char **area, t_point size, t_point begin)
{
	char target = area[begin.y][begin.x];
	fill(area, size, begin, target);
}
