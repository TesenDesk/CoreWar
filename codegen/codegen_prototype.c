//
// Created by Jhiqui Jerde on 21/02/2020.
//

#include "codegen_prototype.h"

struct s_codegen
{
	int stage;
	int add;
	int *code;
	unsigned int *exec;
	int code_size;
	struct s_labelmap *labels_free;
	struct s_labelmap *labels_queue;
	header_t *header;
};

typedef struct s_codegen t_codegen;
/*
void set_label(t_codegen *code, sequenced_text *seq)
{
	if (seq->unit == FREE_LABEL) //todo: функция добавления??? Как устроена label_map?
		add_address(code->labels_free, code->add);
	else
		add_address(code->labels_queue, code->add);
}
*/
t_codegen *codegen_ctor(struct s_labelmap *labels_free, struct s_labelmap *labels_queue, header_t *header)
{
	t_codegen *code;

	code = ft_memalloc(sizeof(t_codegen));
	code->labels_free = labels_free;
	code->labels_queue = labels_queue;
	code->header = header;
	return (code);
}

void codegen_dtor(t_codegen *code)
{
	if (code)
	{
		if (code->labels_free)
			free(code->labels_free); //todo: заменить на норм очистку.
		if (code->labels_queue)
			free(code->labels_queue); //todo: заменить на норм очистку.
		if (code->header)
			free(code->header);
		free(code);
		code = NULL;
	}
}
/*
void codegen_generate_magic(int *dst)
{
	ft_memcpy(dst, COREWAR_EXEC_MAGIC, COREWAR_MAGIC_SIZE);
}
*/
static void codegen_add_champ_name(unsigned int *dst, header_t *header)
{
	ft_memcpy(dst, header->prog_name, sizeof(char) * ft_strlen(header->prog_name));
}
/*
char *codegen_generate_champ_code_size(int code_size)
{
	char *result;

	result = ft_itoa(code_size);
	if (!result)
		return (NULL);
	return (result);
}
*/
static void codegen_add_champ_comment(unsigned int *dst, header_t *header)
{
	ft_memcpy(dst, header->comment, sizeof(char) * ft_strlen(header->comment));
}

int champ_exec_constructor(t_codegen *data)
{
	size_t total_size;
	int i;

	i = 0;
	total_size = PROG_NAME_LENGTH + COMMENT_LENGTH + 16 + data->code_size;
	if (!(data->exec = ft_memalloc(total_size)))
		return (FAILURE);
	data->exec[i++] = data->header->magic;
	codegen_add_champ_name(&data->exec[i], data->header);
	i += (PROG_NAME_LENGTH / 4) + 1;
	data->exec[i++] = data->code_size;
	codegen_add_champ_comment(&data->exec[i], data->header);
	i += (COMMENT_LENGTH / 4) + 1;
	ft_memcpy(&data->exec[i], data->code, data->code_size);
	return (SUCCESS);
}
/*
void codegen(t_codegen *code)
{
	sequenced_text *seq;

	seq = get_sequence();
	if (seq->type == LABEL_WORD)
		set_label(code, seq);
	else
	{
		//todo: add to code using code table.
		code->add++;
	}
}*/


/*
** ========== DEBUG ZONE =================================== TODO: Delete this
*/



int main(void)
{
	t_codegen *code;
	header_t header;
	char cod[8];
	FILE *fp;

	ft_bzero(&header.comment, COMMENT_LENGTH + 1);
	ft_bzero(&header.prog_name, PROG_NAME_LENGTH + 1);
	ft_memcpy(&header.prog_name, "Batman", 4*6);
	ft_memcpy(&header.comment, "This city needs me", 4*6);
	code = codegen_ctor(NULL, NULL, &header);
	code->code_size = 8;
	code->code = ft_memalloc(8);
	code->header->magic = COREWAR_EXEC_MAGIC;
	cod[0] = 1;
	cod[1] = 1;
	cod[2] = 1;
	cod[3] = 0;
	cod[4] = 1;
	cod[5] = 2;
	cod[6] = 0;
	cod[7] = 0;
	ft_memcpy(code->code, &cod, 8);
	champ_exec_constructor(code);
	fp = fopen("test.cmp", "r");
	fprintf(fp, "%s", (char *)code->exec);

	return  (0);
}