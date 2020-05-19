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
	char			*str = malloc(1000000);
	t_hash_map		*map = ft_hash_map_ctor(1000);
	t_vector		vtr;
	t_vector		*text;

	t_arg			*arg;
	int i = 0;
	while (i < 1000)
		str[i++] = 0;
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
	exit(0);
	t_codegen	*code;
	header_t	header;
	int			fd1;
	int int_ptr[10];

	void 	**name = vtr.items;
//	char *name = (t_expr*)(vrt.items[0]);
	ft_bzero(&header.comment, COMMENT_LENGTH + 1);
	ft_bzero(&header.prog_name, PROG_NAME_LENGTH + 1);
	ft_memcpy(&header.comment, "I'M ALIIIIVE", strlen("I'M ALIIIIVE") );
	code = codegen_ctor(NULL, NULL, &header);
	code->labels_free = map;
	code->code_size = 22;
	//code->code = ft_memalloc(8);
	code->header->magic = COREWAR_EXEC_MAGIC;
//	q->type = LABEL_WORD;
//	q->args[0].value = "loop";
//	codegen_codegen(code, q);
//
//	q->type = COM_STI;
//	int_ptr[0] = 1;
//	q->args[0].type = T_REG;
//	q->args[0].value = &int_ptr[0];
//	q->args[1].type = T_DIR;
//	q->args[2].type = T_DIR;
//	int_ptr[1] = LABEL_WORD;
//	q->args[1].value = &int_ptr[1];
//	int_ptr[2] = 1;
//	q->args[2].value = &int_ptr[2];
//	codegen_codegen(code, q);

	code->header->prog_size = champ_exec_constructor(code);
	fd1 = open("test.cmp", O_WRONLY);
	//fprintf(fp, "%s", code->exec);
	write(fd1, code->exec, code->header->prog_size);

	return  (0);
}
