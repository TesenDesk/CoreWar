#include "libft.h"

void		print_hashmap(t_hash_map *map)
{
	size_t		i;

	i = 0;
	while (i < HASH_CONST)
	{
		if (map->)
	}
}

int			main(int c, char **v)
{
	t_hash_map		*map;
	int				i;

	map = create_hashmap(HASH_CONST);
	i = 1;
	while (i < c)
		label_checker_put_to_map(&map, v[i]);
	print_hashmap(map);
	return (0);
}