//
// Created by ikira on 6/21/20.
//

#include <unistd.h>
//#include "token.h"
//#include "lexer.h"
#include "codegen.h"
//#include "libft.h"
//#include "lexer_private.h"
//#include "./parser/expr_private.h"
//#include "parser.h"
//#include "./parser/parser_private.h"
#include "analyser.h"

char        *read_code(int fd)
{
    char    *buf;
    int     chunk;
    int     cur;
    int     limit;

    cur = 0;
    chunk = 1;
    limit = 1;
    if (fd < 0)
        exit (-1);
    if (!(buf = ft_memalloc(chunk * sizeof(char))))
        exit(-1);
    while (read(fd, buf + cur, chunk))
    {
        cur += chunk;
        if (cur == limit)
        {
            if (!(buf = ft_realloc(buf, limit, limit * 2)))
                exit(-1);
            limit *= 2;
        }
    }
    return (buf);
}

void        delete_parsing_structs(void)
{
	analyser_singleton_instance(ANALYSER_DESTRUCT);
	parser_singleton_instance(PARSER_DESTRUCT);
	lexer_singleton_instance(LEXER_DESTRUCT);
}


int main(int ac, char **av)
{
	t_hash_map		*map;
    t_vector		*text;
    t_analyser      *analyser;
	t_vector		vtr;
	int             count = 1;
	/*
	 * count для теста
	 */


//	map = ft_hash_map_ctor(HASH_CONST);
//	ft_vector_init(&vtr);
//	analyser = analyser_singleton_instance(ANALYSER_INSTANTIATE);
//	text = analyse_text(analyser, &vtr, map, (read_code(open(av[1], O_RDONLY))));
//	generate_code(map, text, av[1]);
	/*
	 * цикл для тестов
	 */
	while (count < ac) {
		map = ft_hash_map_ctor(HASH_CONST);
		ft_vector_init(&vtr);
		analyser = analyser_singleton_instance(ANALYSER_INSTANTIATE);
		text = analyse_text(analyser, &vtr, map, (read_code(open(av[count], O_RDONLY))));
		generate_code(map, text, av[count]);
		analyser_singleton_instance(ANALYSER_DESTRUCT);
		++count;
	}
	ft_hash_map_dtor(&map);
	delete_parsing_structs();
	return (SUCCESS);
}
