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
//
//int main(int ac, char**av)
//{
//	av[1] = "/home/ikira/Desktop/core/bee_gees.cor";
//
//
//
//	/*
//	**	Ожидаю для текста по str 10 выражений. В карту попадёт 2, в вектор -- 3
//	*/
//
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
////	int fd = open( av[1], O_RDONLY);
//	int fd = open( "example_text" , O_RDONLY);
//
////	int errsv = errno;
////	printf("somecall() %d, %d\n", errsv, fd);
//	int chunk = 100;
//	int cur = 0;
//
//	while (read(fd,str + cur, chunk))
//		cur += chunk;
//	prs = parser_singleton_instance(PARSER_INSTANTIATE);
////	str =
////			".name	\"Batman\"\n"
////			".comment	\"Batman rules!\"\n"
////			"ld %0, r2\n"
////			"sti r1, %:live, %1\n"
////			"loop:\n"
////			"sti r1, %:live, %1\n"
////			"live:\n"
////			"live %0\n"
////			"ld %0, r2\n"
////			"zjmp %:loop\n";
//	map = ft_hash_map_ctor(HASH_CONST);
//	ft_vector_init(&vtr);
//
////	t_expr *expr1 = parser_form_expr(prs, &str, map, &vtr); // запись в карту
////	t_expr *expr2 = parser_form_expr(prs, &str, map, &vtr);
////	t_expr *expr3 = parser_form_expr(prs, &str, map, &vtr);
//	t_analyser *analyser;
//
//	analyser = analyser_singleton_instance(ANALYSER_INSTANTIATE);
//	printf("|sasadsdddddddddddddddddddddddddddddddddddddddddddd\n");
//	text = analyse_text(analyser, &vtr, map, &str);
//	/*
//	 * ПЕРЕДЕЛАТЬ!!!
//	 */
//	av += 1;
//
//	printf("!state:%d\n", prs->state);
////	int fd2 = open('./bee_gees.cor', 'r');
////	t_vm_params vm_params = vm_pa;
//	t_vm_params *params = vm_params_new(ac, av);
//
//
////	vm_params.id_player_head->content =
//	t_arena *arena = arena_new(params);
//	return (SUCCESS);
//}

int         main()
{
    char     *argv[2];

    argv[0] = "bee_gees.cor";
    argv[1] = "zork.cor";

    vm_params_new(2, argv);

    return (SUCCESS);
}
