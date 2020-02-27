#include "libft.h"

void		print_vert(t_keystr_avl_t *vert)
{
	printf("============ label_name = %s ============\n", vert->pair->key);
	printf("label_content = %s\n", vert->pair->content);
	printf("==========================================\n");
}

void		print_hashmap(t_hash_map *map)
{
	size_t		i;

	i = 0;
	while (i < map->map_size)
	{
		if (map->data[i] != NULL)
		{
			ft_keystr_avl_tree_traversal(map->data[i], print_vert);
		}
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