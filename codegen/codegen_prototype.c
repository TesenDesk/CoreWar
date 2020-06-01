#pragma clang diagnostic push
#pragma ide diagnostic ignored "hicpp-signed-bitwise" // todo: Hey? Delete this!

//
// Created by Jhiqui Jerde on 21/02/2020.
//

#include <token_private.h>
#include "codegen_prototype.h"
#include "codegen_private.h"
#include "token_defines.h"
#include "../virtual_machine/include/op.h"

static void		rotate_four_bytes(unsigned int *p)
{
	*p = *p << 24 | *p >> 24 | (*p & 0xff00) << 8 | (*p & 0xff0000) >> 8;
}

t_codegen		*codegen_ctor(t_hash_map *labels_free, t_vector *labels_ptrs,
									header_t *header)
{
	t_codegen	*code;

	code = ft_memalloc(sizeof(t_codegen));
	code->labels_free = labels_free;
	if (!labels_ptrs)
	{
		if (!(labels_ptrs = ft_memalloc(sizeof(t_vector))))
			return (NULL);
		ft_vector_init(labels_ptrs);
	}
	code->labels_ptrs = labels_ptrs;
	code->header = header;
	code->code = ft_memalloc(sizeof(char) * 32);
	return (code);
}

void			codegen_dtor(t_codegen *code)
{
	if (code)
	{
		if (code->labels_free)
			free(code->labels_free); //todo: заменить на норм очистку.
		if (code->labels_ptrs)
			free(code->labels_ptrs); //todo: заменить на норм очистку.
		if (code->header)
			free(code->header);
		free(code);
		code = NULL;
	}
}

static void		codegen_add_champ_name(char *dst, header_t *header)
{
	ft_memcpy(dst, header->prog_name,
			sizeof(char) * ft_strlen(header->prog_name));
}

static void		codegen_add_champ_comment(char *dst, header_t *header)
{
	ft_memcpy(dst, header->comment,
			sizeof(char) * ft_strlen(header->comment));
}

// NOTE: NEED CAST TYPES LIKE TYPES TABLE!!!!!!!!

static void		add_params_types(t_codegen *data, t_expr *q)
{
	int res;

	res = 0;
	res = (res + q->args[0].type) << 2;
	res = (res + q->args[1].type) << 2;
	res = (res + q->args[2].type) << 2;
	data->code[data->add++] = (char)res;
}
/*
 * переделать константы
 */
static void		recast_params_types(t_expr *q)
{
	/*
	 * все на токены
	 */
	if (q->args[0].type == TOKEN_TIND_INT || q->args[0].type == TOKEN_TIND_LAB)
		q->args[0].type = T_IND_CODE;
	else if (q->args[0].type == TOKEN_TDIR_INT || q->args[0].type == TOKEN_TDIR_LAB)
		q->args[0].type = T_DIR_CODE;
	else if (q->args[0].type == TOKEN_TREG)
		q->args[0].type = T_REG_CODE;
}

static void		dir_type_detector(t_expr *q)
{
	if (q->type < COM_ZJMP || q->type > COM_LFORK ||
		q->type == COM_LLD)
		q->size = 1;
	else
		q->size = 2;
}

static void		write_address_to_free_label(t_codegen *data, t_expr *label)
{
	t_code_addr	*tmp;
	t_token		*token;

	token = label->args[LABEL_ARG].value;
	if (!(tmp = (t_code_addr*)malloc(sizeof(t_code_addr))))
		exit(-1);
	tmp->addr = data->add;
	ft_hash_map_set_content(data->labels_free, token->val, (void*)&(tmp->addr));
}

static void		add_address_to_arg_label(t_codegen *data, t_arg *arg)
{
	t_label_data label;

	label.name = arg->value;
	label.add = data->add;
	ft_vector_add(data->labels_ptrs, &label);
}

static void		add_param(t_codegen *data, t_arg *param, char dir_type)
{
	if (param->type == TOKEN_TIND_LAB || param->type == TOKEN_TDIR_LAB)
	{
		add_address_to_arg_label(data, param);
		++(data->add);
	}
	else
	{
		if (param->type == TOKEN_TIND_INT)
		{
			rotate_four_bytes(param->value);
			ft_memcpy(&data->code[data->add], param->value, IND_SIZE);
			data->add += IND_SIZE;
		}
		else if (param->type == TOKEN_TDIR_INT)
		{
			rotate_four_bytes(param->value);
			ft_memcpy(&data->code[data->add], param->value,
					DIR_SIZE / dir_type);
			data->add += DIR_SIZE / dir_type;
		}
		else if (param->type == TOKEN_TREG)
		{
			data->code[data->add] = (char)param->value;
			++(data->add);
		}
	}
}
/*
 * переделать
 */
void		codegen_codegen(t_codegen *data, t_expr *q)
{
	int i;

	i = -1;
	if (q->type == EXPR_LABEL_W)
		write_address_to_free_label(data, q);
	else
	{
		add_params_types(data, q);
		dir_type_detector(q);
		data->code[data->add++] = q->type;
		while (++i < 3 && q->args[i].type)
			add_param(data, &q->args[i], q->size);
	}
}

static void			codegen_ending(t_codegen *data)
{
	int				i;
	t_label_data	*ld;
	int				*add;
	int				tmp;

	i = -1;
//	printf("labs");
	while ((ld = ft_vector_get(data->labels_ptrs, ++i)))
	{
		add = (int*)ft_hash_map_get(data->labels_free, ld->name);
		tmp = (int)(add - ld->add);
		if (tmp < 0)
		{
			tmp = (int)(tmp ^ 0xFFFFFFFF);
			++tmp;
		}
		data->code[ld->add] = (char)tmp;
	}
}

int				champ_exec_constructor(t_codegen *data)
{
	size_t			total_size;
	int				i;
	unsigned int	tmp_size;

	i = 0;
	codegen_ending(data);
	total_size = PROG_NAME_LENGTH + COMMENT_LENGTH + 16 + data->code_size;
	if (!(data->exec = ft_memalloc(total_size)))
		return (0);
	rotate_four_bytes(&data->header->magic);
	ft_memcpy(&data->exec[i], &data->header->magic, 4);
	i += 4;
	codegen_add_champ_name(&data->exec[i], data->header);
	i += (PROG_NAME_LENGTH) + 4;
	printf("code_s:%d\n", data->code_size);
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
** ========== DEBUG ZONE =========== TODO: Delete all data beyond this point
*/

// WARN: IF YOU WANT DELETE THIS, PLEASE ASK A DEVELOPER.
// OR YOU CAN COMMENT CODEGEN_DEBUGGER DEFINITION ON .h FILE

#ifdef CODEGEN_DEBUGGER

//int				main(void)
//{
//	t_codegen	*code;
//	header_t	header;
//	int			fd;
//	t_expr		*q;
//	t_hash_map	*map;
//	t_pair      *new_item;
//	int int_ptr[10];
//
//	ft_bzero(&header.comment, COMMENT_LENGTH + 1);
//	ft_bzero(&header.prog_name, PROG_NAME_LENGTH + 1);
//	q = ft_memalloc(sizeof(t_expr));
//	ft_memcpy(&header.prog_name, "Batman", 4*6);
//	ft_memcpy(&header.comment, "This city needs me", 4*6);
//	code = codegen_ctor(NULL, NULL, &header);
//	map = ft_hash_map_ctor(5);
//	new_item = ft_memalloc(sizeof(t_pair));
//	new_item->key = "loop";
//	ft_hash_map_put_to_map(&map, new_item);
//	new_item = ft_memalloc(sizeof(t_pair));
//	new_item->key = "live";
//	ft_hash_map_put_to_map(&map, new_item);
//	code->labels_free = map;
//	code->code_size = 22;
//	//code->code = ft_memalloc(8);
//	code->header->magic = COREWAR_EXEC_MAGIC;
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
//
//	code->header->prog_size = champ_exec_constructor(code);
//	fd = open("test.cmp", O_WRONLY);
//	//fprintf(fp, "%s", code->exec);
//	write(fd, code->exec, code->header->prog_size);
//
//	return  (0);
//}

#endif // CODEGEN_DEBUGGER

#pragma clang diagnostic pop
