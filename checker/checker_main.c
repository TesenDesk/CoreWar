#include "label_checker.h"

// void		test_maps(t_hash_map *map_of_label_words,
// 			t_hash_map *map_of_label_ptrs, t_vector *added_label_ptrs,
// 			char **argv, int argc)
// {
// 	int		i;

// 	i = 1;
// 	while (i < argc)
// 	{
// 		if ()
// 		++i;
// 	}
// }

int			main(int argc, char **argv)
{
	t_hash_map		*map_of_label_words;
	t_hash_map		*map_of_label_ptrs;
	t_vector		added_label_ptrs;
	int				i;
	size_t			len;

	map_of_label_words = create_hashmap(HASH_CONST);
	map_of_label_ptrs = create_hashmap(HASH_CONST);
	i = 1;
	while (i < argc)
	{
		len = ft_strlen(argv[i]);
		if (label_checker_put_to_map_label_ptr(&map_of_label_ptrs,
		&added_label_ptrs, (char const**)&argv[i], len) == FAILURE)
			printf("problems with map_of_label_ptrs\n argv[i] == \"%s\"\n", argv[i]);
		if (label_checker_put_to_map_label_word(&map_of_label_words, (char const**)&argv[i],
		len) == FAILURE)
			printf("problems with map_of_label_words\n argv[i] == \"%s\"\n", argv[i]);
		++i;
	}
	// test_maps(map_of_label_words, map_of_label_ptrs, &added_label_ptrs, argv, argc);
	return (0);
}