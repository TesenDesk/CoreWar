//#include <stdio.h>
//#include <unistd.h>
//#include <fcntl.h>
//#include "token.h"
//#include <errno.h>
#include "token_defines.h"
#include "virtual_machine/include/arena.h"  // changes by cmissy

#include "lexer.h"
#include "virtual_machine/src/vm_params/_vm_params.h"
#include "virtual_machine/include/vm_params.h"
//#include "lexer_private.h"  // changes by cmissy
#include "./lexer/lexer_private.h"

#include "./lexer/lexer_utils_private.h"

#include "expr.h"
#include "expr_defines.h"
#include "./parser/expr_private.h"

#include "parser.h"
#include "./parser/parser_private.h"
#include "analyser.h"
//#include "vm_params.h"

//int main()
//{
//	t_parser		*prs;
//	char			*str = malloc(1000);
//	t_hash_map		*map;
//	t_vector		vtr;
//	t_vector		*text;
//
//	t_arg			*arg;
//	int i = 0;
//	while (i < 1000)
//		str[i++] = 0;
//	int fd = open( "example_text" , O_RDONLY);
//
//	int errsv = errno;
//	printf("somecall() %d, %d\n", errsv, fd);
//	int chunk = 100;
//	int cur = 0;
//
//	while (read(fd,str + cur, chunk))
//		cur += chunk;
//	prs = parser_singleton_instance(PARSER_INSTANTIATE);
//	map = ft_hash_map_ctor(HASH_CONST);
//	ft_vector_init(&vtr);
//
//	t_analyser *analyser;
//
//	analyser = analyser_singleton_instance(ANALYSER_INSTANTIATE);
//	printf("|sasadsdddddddddddddddddddddddddddddddddddddddddddd\n");
//	text = analyse_text(analyser, &vtr, map, &str);
//	printf("!state:%d\n", prs->state);
//	t_vm_params *params = vm_params_new(ac, av);
//
//	t_arena *arena = arena_new(params);
//	return (SUCCESS);
//}

#include "virtual_machine/include/file.h"

//static void 	print_file(tt_file *self)
//{
//    printf("data_name = %s\n", file_data_name(self));
//    printf("data_comment = %s\n", file_data_comment(self));
//    printf("is valid = %d\n", file_data_check_valid(self));
//
//}
//
//int     main(int c, char **v)
//{
//    tt_file     *file;
//
//    file = file_new("bee_gees.cor");
//    print_file(file);
//    return (SUCCESS);
//}

//void                print_vmp_player(t_vmp_player *self)
//{
//
//}
//#include "_vmp_player.h"
//#include "carriage.h"
#include "player.h"
int                 main()
{
//    t_carriage      *carriage;
//    carriage = carriage_new(pla);
    t_vmp_player    *vmpPlayer;
    t_player        *player;

    vmpPlayer = vmp_player_new(1, "bee_gees.cor");
    player = player_new(vmpPlayer);
    arena_new();
}