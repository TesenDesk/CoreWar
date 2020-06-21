//
// Created by ikira on 6/21/20.
//

#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "token.h"
#include <errno.h>
#include "token_defines.h"

#include "lexer.h"
#include "virtual_machine/src/vm_params/_vm_params.h"
#include "virtual_machine/include/vm_params.h"
#include "lexer_private.h"
#include "./lexer/lexer_private.h"

#include "./lexer/lexer_utils_private.h"

#include "expr.h"
#include "expr_defines.h"
#include "./parser/expr_private.h"

#include "parser.h"
#include "./parser/parser_private.h"
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


int main(int ac, char **av)
{
	t_hash_map		*map;
    t_vector		*text;
    t_analyser      *analyser;
	t_vector		vtr;


	map = ft_hash_map_ctor(HASH_CONST);
	ft_vector_init(&vtr);
	analyser = analyser_singleton_instance(ANALYSER_INSTANTIATE);
	text = analyse_text(analyser, &vtr, map, (read_code(open(av[1], O_RDONLY))));
	generate_code(map, text);

	return (SUCCESS);
}
