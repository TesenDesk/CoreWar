//
// Created by Jhiqui Jerde on 21/02/2020.
//

#include "codegen_prototype.h"

struct s_codegen
{
	int stage;
	int add;
	int *code;
	int *exec;
	int code_size;
	struct s_labelmap *labels_free;
	struct s_labelmap *labels_queue;
};

typedef struct s_codegen t_codegen;

void set_label(t_codegen *code, sequenced_text *seq)
{
	if (seq->unit == FREE_LABEL) //todo: функция добавления??? Как устроена label_map?
		add_address(code->labels_free, code->add);
	else
		add_address(code->labels_queue, code->add);
}

t_codegen *codegen_ctor(struct s_labelmap *labels_free, struct s_labelmap *labels_queue)
{
	t_codegen *code;

	code = ft_memalloc(sizeof(t_codegen));
	code->labels_free = labels_free;
	code->labels_queue = labels_queue;
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
static void codegen_add_champ_name(char *dst, t_sequenced_text *champ_name)
{
	ft_memcpy(dst, champ_name->content, sizeof(champ_name->content));
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
static void codegen_add_champ_comment(int *dst, const char *comment)
{
	ft_memcpy(dst, comment, sizeof(char) * ft_strlen(comment));
}

void champ_exec_constructor(t_codegen *data)
{
	size_t total_size;
	int i;

	i = 0;
	total_size = PROG_NAME_LENGTH + COMMENT_LENGTH + 16 + data->code_size;
	if (!(data->exec = ft_memalloc(total_size)))
		return (NULL);
	data->exec[i++] = COREWAR_EXEC_MAGIC;
	codegen_add_champ_name(&data->exec[i], champ_name_generic); //todo add struct
	i += (PROG_NAME_LENGTH / 4) + 1;
	data->exec[i++] = data->code_size;
	codegen_add_champ_comment(&data[i], champ_comment_generic->content); //todo ?????
	i += (COMMENT_LENGTH / 4) + 1;
	ft_memcpy(&data->exec[i], data->code, data->code_size);
}

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
}