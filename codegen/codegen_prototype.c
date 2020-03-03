#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-signed-bitwise" // todo: Hey? Delete this!
//
// Created by Jhiqui Jerde on 21/02/2020.
//

#include "codegen_prototype.h"
#include "codegen_private.h"

#include <fcntl.h>

struct s_codegen
{
	int add;
	int *code;
	char *exec;
	unsigned int code_size;
	struct s_labelmap *labels_free;
	struct s_labelmap *labels_queue;
	header_t *header;
};

typedef struct s_param
{
	char type;
	unsigned int content;
}				t_arg;

struct s_expr
{
	char type;
	char dir_type;
	int params_count;
	t_arg *param1;
	t_arg *param2;
	t_arg *param3;
};

typedef struct s_expr t_expr;

// seq->param1->content == 1;

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

static void rotate_four_bytes(unsigned int *p)
{
	*p = *p << 24 | *p >> 24 | (*p & 0xff00) << 8 | (*p & 0xff0000) >> 8;
}

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
		//code = NULL;
	}
}

static void codegen_add_champ_name(char *dst, header_t *header)
{
	ft_memcpy(dst, header->prog_name, sizeof(char) * ft_strlen(header->prog_name));
}

static void codegen_add_champ_comment(char *dst, header_t *header)
{
	ft_memcpy(dst, header->comment, sizeof(char) * ft_strlen(header->comment));
}
// NOTE: NEED CAST TYPES LIKE TYPES TABLE!!!!!!!!
static void add_params_types(t_codegen *data, t_expr *q)
{
	int res;

	res = 0;
	res = (res + q->param1->type) << 2;
	res = (res + q->param2->type) << 2;
	res = (res + q->param3->type) << 2;
	data->code[data->add++] = (char)res;
}

static void recast_params_types(t_expr *q)
{
	if (q->param1->type == T_IND)
		q->param1->type = T_IND_CODE;
	if (q->param2->type == T_IND)
		q->param2->type = T_IND_CODE;
	if (q->param3->type == T_IND)
		q->param3->type = T_IND_CODE;
}

static void dir_type_detector(t_expr *q)
{
	if (q->type < COM_ZJMP || q->type > COM_LFORK ||
		q->type == COM_LLD)
		q->dir_type = 1;
	else
		q->dir_type = 2;
}

static void add_param(t_codegen *data, t_arg *param, char dir_type)
{
	if (param->type == LABEL_WORD)
		(void)param; // aka 'do nothing' todo: add labels manipulation.
	else //todo: Нужно ли указыать размеры из хедера, или лучше указать здесь?
	{
		if (param->type == T_IND_CODE)
		{
			rotate_four_bytes(&param->content);
			ft_memcpy(&data->code[data->add], &param->content, IND_SIZE);
			data->add += IND_SIZE;
		}
		else if (param->type == T_DIR)
		{
			rotate_four_bytes(&param->content);
			ft_memcpy(&data->code[data->add], &param->content, T_DIR / dir_type);
			data->add += T_DIR / dir_type;
		}
		else if (param->type == T_REG)
		{
			data->code[data->add] = (char)param->content;
			++(data->add);
		}
	}
}

static void codegen_codegen(t_codegen *data, t_expr *q)
{
	if (q->type == LABEL_WORD)
		(void)q; // aka 'do nothing' todo: add labels manipulation.
	else
	{
		add_params_types(data, q);
		recast_params_types(q);
		dir_type_detector(q);
		data->code[data->add++] = q->type;
		if (q->params_count)
			add_param(data, q->param1, q->dir_type);
		if (q->params_count > 1)
			add_param(data, q->param2, q->dir_type);
		if (q->params_count > 2)
			add_param(data, q->param3, q->dir_type);
	}
}

int champ_exec_constructor(t_codegen *data)
{
	size_t total_size;
	int i;
	unsigned int tmp_size;

	i = 0;
	total_size = PROG_NAME_LENGTH + COMMENT_LENGTH + 16 + data->code_size;
	if (!(data->exec = ft_memalloc(total_size)))
		return (0);
	rotate_four_bytes(&data->header->magic);
	ft_memcpy(&data->exec[i], &data->header->magic, 4);
	i += 4;
	codegen_add_champ_name(&data->exec[i], data->header);
	i += (PROG_NAME_LENGTH) + 4;
	tmp_size = data->code_size;
	rotate_four_bytes(&tmp_size);
	ft_memcpy(&data->exec[i], &tmp_size, 4);
	i += 4;
	codegen_add_champ_comment(&data->exec[i], data->header);
	i += (COMMENT_LENGTH) + 4;
	ft_memcpy(&data->exec[i], data->code, data->code_size);
	return (total_size);
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
** ========== DEBUG ZONE =========== TODO: Delete all data beyond this point
*/

#ifdef CODEGEN_DEBUGGER

int main(void)
{
	t_codegen *code;
	header_t header;
	char cod[8];
	int fd;

	ft_bzero(&header.comment, COMMENT_LENGTH + 1);
	ft_bzero(&header.prog_name, PROG_NAME_LENGTH + 1);
	ft_memcpy(&header.prog_name, "Batman", 4*6);
	ft_memcpy(&header.comment, "This city needs me", 4*6);
	code = codegen_ctor(NULL, NULL, &header);
	code->code_size = 22;
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
	code->header->prog_size = champ_exec_constructor(code);
	fd = open("test.cmp", O_WRONLY);
	//fprintf(fp, "%s", code->exec);
	write(fd, code->exec, code->header->prog_size);

	return  (0);
}

#endif

#pragma clang diagnostic pop