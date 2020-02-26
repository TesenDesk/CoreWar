//
// Created by Jhiqui Jerde on 21/02/2020.
//

#include "codegen_prototype.h"

struct s_codegen
{
	int stage;
	int add;
	char
	struct s_labelmap *labels_free;
	struct s_labelmap *labels_queue;
};

typedef struct s_codegen t_codegen;

void set_label( t_codegen *code, sequenced_text *seq)
{
	if (seq->unit == FREE_LABEL) //todo: функция добавления??? Как устроена label_map?
		add_address(code->labels_free, code->add);
	else
		add_address(code->labels_queue, code->add);
}

t_codegen *codegen_constructor(struct s_labelmap *labels_free, struct s_labelmap *labels_queue)
{
	t_codegen *code;

	code = ft_memalloc(sizeof(t_codegen));
	code->labels_free = labels_free;
	code->labels_queue = labels_queue;
	return (code);
}

void codegen_destructor(t_codegen *code)
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

char *codegen_generate_magic(void)
{
	char *magic;
	size_t size;

	size = sizeof(COREWAR_EXEC_MAGIC);
	if (!(magic = ft_memalloc(size)))
	{
		return (NULL);
	}
	ft_memcpy(magic, COREWAR_EXEC_MAGIC, size);
	return (magic);
}

char *codegen_generate_champ_name_null(t_sequenced_text *champ_name)
{
	char *name;

	if (!(name = ft_memalloc(PROG_NAME_LENGTH + 4)))
		return (NULL);
	ft_memcpy(name, champ_name->content, sizeof(champ_name->content));
	return (name);
}

char *codegen_generate_champ_code_size(int code_size)
{
	char *result;

	result = ft_itoa(code_size);
	if (!result)
		return (NULL);
	return (result);
}

char *codegen_generate_champ_comment_null(const char *comment)
{
	char *result;

	if (!(result = ft_memalloc(COMMENT_LENGTH + 4)))
	{
		return (NULL);
	}
	ft_memcpy(result, comment, sizeof(comment));
	return (result);
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