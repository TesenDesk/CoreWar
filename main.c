#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include "token.h"
#include <errno.h>
#include "token_defines.h"
#include "codegen/codegen_private.h"
#include "codegen/codegen_prototype.h"
#include "libft.h"
#include "codegen/codegen_private.h"
#include "codegen/codegen_prototype.h"
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
#include <string.h>
int main(int ac, char **av)
{
	t_parser		*prs;
	char			*str = ft_memalloc(1000000);
	t_hash_map		*map = ft_hash_map_ctor(1000);
	t_vector		vtr;
	t_vector		*text;

	t_arg			*arg;
	int fd = open( "./valid/zork.s" , O_RDONLY);

	int errsv = errno;
	printf("somecall() %d, %d\n", errsv, fd);
	int chunk = 100;
	int cur = 0;

	while (read(fd,str + cur, chunk))
		cur += chunk;
	ft_vector_init(&vtr);

	t_analyser *analyser;
	analyser = analyser_singleton_instance(ANALYSER_INSTANTIATE);
	text = analyse_text(analyser, &vtr, map, &str);
	printf("valid\n");
//	exit(0);
	t_codegen	*code;
	header_t	header;
	int			fd1;
	int int_ptr[10];

	ft_bzero(&header.comment, COMMENT_LENGTH + 1);
	ft_bzero(&header.prog_name, PROG_NAME_LENGTH + 1);
	ft_memcpy(&header.comment, "I'M ALIIIIVE", strlen("I'M ALIIIIVE") );
	code = codegen_ctor(map, &vtr , &header);
	code->labels_free = map;
	code->code_size = 22;
	code->header->magic = COREWAR_EXEC_MAGIC;

	int i = 0;
	t_expr *new;
	while ((new = ft_vector_get(text, i++)))
		codegen_codegen(code, new);
	code->header->prog_size = champ_exec_constructor(code);
	fd1 = open("test.cmp", O_WRONLY);
	write(fd1, code->exec, code->header->prog_size);

	return  (0);
}
