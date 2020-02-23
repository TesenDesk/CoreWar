//
// Created by Jhiqui Jerde on 21/02/2020.
//

#include "codegen_prototype.h"

struct s_codegen
{
	int stage;
	int add;
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

t_codegen *codegen_constructor()
{
	t_codegen *code;

	code = ft_memalloc(sizeof(t_codegen));
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