#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "token.h"
#include <errno.h>
#include "token_defines.h"
//#include "virtual_machine/include/arena.h"

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
#include "vm_params.h"
//		exit (-1);



//void			file_print_dump(tt_file *self)
//{
//	size_t		index;
//	size_t		i;
//	size_t		buffer_len;
//	char    	*buffer;
//	char	    *data;
//	buffer_len = DUMP_LINE_SIZE * 3;
//	buffer = ft_memalloc(buffer_len);
//	data = (char*)self->data;
//	index = 0;
//	i = 0;
//	while (index < MEM_SIZE)
//	{
//		buffer[i] = '0';
//		if (data[index] < 16)
//			ft_uintmaxtostr(&buffer[i + 1], data[index], 16, 0);
//		else
//			ft_uintmaxtostr(&buffer[i], data[index], 16, 0);
//		i += 2;
//		index++;
//		if (!(index % DUMP_LINE_SIZE))
//		{
//			buffer[i] = EOL;
//			i = 0;
//			write(1, buffer, buffer_len);
//		}
//		else
//			buffer[i++] = SPACE;
//	}
//	// (void)vm_singleton(VM_DESTRUCT, 0, NULL);
//}
#include "virtual_machine/include/vm.h"

int         main(int ac, char **av) // DONT FORGET FIX arc CAUSE argc[0] == EXEC FILE NAME
{
    t_vm            *vm;

/*      FIRST TEST      */
//    int             argc = 6;
//    char            *argv[argc];
//    argv[1] = "bee_gees.cor";
//    argv[2] = "-n";
//    argv[3] = "2";
//    argv[4] = "zork.cor";
//    argv[5] = NULL;

/*      SECOND TEST      */
//    int             argc = 8;
//    char            *argv[argc];
//    argv[1] = "bee_gees.cor";
//    argv[2] = "-n";
//    argv[3] = "1";
//    argv[4] = "zork.cor";
//    argv[5] = "--dump";
//    argv[6] = "5000";
//    argv[7] = NULL;
    vm = vm_singleton(VM_INSTANTIATE, ac - 1, av + 1);


//    char *dst = ft_memalloc(8);
//    printf("dst = %s\n", dst);
//    char *src = "12345678";
//    ft_strncpy(dst, src, 8);
//    printf("dst = %s\n", dst);


    return (SUCCESS);
}
