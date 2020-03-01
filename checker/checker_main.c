#include "label_checker.h"


void		print_map_of_label_words(t_hash_map *map_of_label_words)
{
	size_t		i;

	i = 0;
	while (i < map_of_label_words->arr_size)
	{
		if (map_of_label_words->data[i] != NULL)
			ft_key
		i++;
	}
}

int			main(int argc, char **argv)
{
	t_hash_map		*map_of_label_words;
	t_hash_map		*map_of_label_ptrs;
	t_vector		added_label_ptrs;
	int				i;
	size_t			len;

	map_of_label_words = create_hashmap(HASH_CONST);
	map_of_label_ptrs = create_hashmap(HASH_CONST);
	ft_vector_init(&added_label_ptrs);
	i = argc;
	i = 1;
	while (argv[i])
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
	print_map_of_label_words(map_of_label_words);
	// print_map_of_label_ptrs(map_of_label_words);
	return (0);
}