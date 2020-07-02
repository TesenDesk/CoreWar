//#pragma clang diagnostic push
//#pragma ide diagnostic ignored "hicpp-signed-bitwise" // todo: Hey? Delete this!

//
// Created by Jhiqui Jerde on 21/02/2020.
//

#include "../lexer/token_private.h"
#include "codegen_prototype.h"
#include "codegen_private.h"
#include "token_defines.h"
#include "op.h"
#include "expr.h"
#include "expr_defines.h"

static void		rotate_four_bytes(unsigned int *p)
{
	int 		tmp = *p;
	int	first = (*p & 0x000000ff) << 24;
	int second = ((*p & 0xff000000) >> 24);
	int third = 	((*p & 0x0000ff00) << 8);
	int fourth = ((*p & 0x00ff0000) >> 8);
//	printf("%x %x %x %x\n", first, third, fourth, second);
	/*
	 * в обратную сторону???
	 */
//	printf("*p:%d\n", *p);
	*p = second | fourth | third | first;
//	printf("*p:%d\n", *p);
//				 *p = ((*p & 0x000000ff)) << 24 | ((*p & 0xff000000) >> 24) | ((*p & 0x0000ff00) << 8) | ((*p & 0x00ff0000) >> 8);
//	*p = (*p << 24) | (*p >> 24);
}

static void		rotate_two_bytes(unsigned short *p)
{
	*p = *p << 8 | (*p & 0xff00) >> 8;
}

static void		rotate_bytes(unsigned int *p, int size)
{
	if (size == 2)
		rotate_two_bytes((unsigned short*)p);
	else if (size == 4)
		rotate_four_bytes(p);
	else
		;
}
//
//
//
t_codegen		*codegen_ctor(t_hash_map *labels_free,
									header_t *header)
{
	t_codegen	*code;

	code = ft_memalloc(sizeof(t_codegen));
	code->labels_free = labels_free;
	if (!(code->labels_ptrs = (t_vector*)ft_memalloc(sizeof(t_vector))))
		exit(-1);
	ft_vector_init(code->labels_ptrs);
	code->header = header;
	/*
	 * найти размер?
	 */
	code->code = ft_memalloc(sizeof(char) * 1000000);
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
//
static void		codegen_add_champ_name(char *dst, header_t *header)
{
	ft_memcpy(dst, header->prog_name,
			sizeof(char) * ft_strlen(header->prog_name));
}
//
static void		codegen_add_champ_comment(char *dst, header_t *header)
{
	ft_memcpy(dst, header->comment,
			sizeof(char) * ft_strlen(header->comment));
}
//
//// NOTE: NEED CAST TYPES LIKE TYPES TABLE!!!!!!!!
//
//
int			ft_checkbit(char n, int pos)
{
	return ((n & (1 << pos)) != 0);
}

void		ft_printbits(char n, int count)
{
	while (count--)
	{
		printf("%c", ft_checkbit(n, count) + '0');
		if (!(count % 4 && count))
			ft_putchar(' ');
	}
	ft_putchar('\n');
}
//
//
static void		add_params_types(t_codegen *data,  int first_arg, int second_arg, int third_arg)
{
	int res;

	res = 0;
	res |= first_arg << 6;
	res |= second_arg << 4;
	res |= third_arg << 2;
	data->code[data->add++] = (char)res;
//	ft_printbits(res, 8);
}
///*
// * переделать константы
// */
static void		recast_params_types(t_codegen *data, t_expr  *q)
{
	/*
	 * все на токены
	 */
	int		first_arg;
	int 	second_arg;
	int 	third_arg;

	first_arg = 0;
	second_arg = 0;
	third_arg = 0;
	if (q->args[FIRST_ARG].type == TOKEN_TIND_INT || q->args[FIRST_ARG].type == TOKEN_TIND_LAB)
		first_arg = T_IND_CODE;
	else if (q->args[FIRST_ARG].type == TOKEN_TDIR_INT || q->args[FIRST_ARG].type == TOKEN_TDIR_LAB)
		first_arg = T_DIR_CODE;
	else if (q->args[FIRST_ARG].type == TOKEN_TREG)
		first_arg = T_REG_CODE;
	if (q->args[SECOND_ARG].type == TOKEN_TIND_INT || q->args[SECOND_ARG].type == TOKEN_TIND_LAB)
		second_arg = T_IND_CODE;
	else if (q->args[SECOND_ARG].type == TOKEN_TDIR_INT || q->args[SECOND_ARG].type == TOKEN_TDIR_LAB)
		second_arg = T_DIR_CODE;
	else if (q->args[SECOND_ARG].type == TOKEN_TREG)
		second_arg = T_REG_CODE;
	if (q->args[THIRD_ARG].type == TOKEN_TIND_INT || q->args[THIRD_ARG].type == TOKEN_TIND_LAB)
		third_arg = T_IND_CODE;
	else if (q->args[THIRD_ARG].type == TOKEN_TDIR_INT || q->args[THIRD_ARG].type == TOKEN_TDIR_LAB)
		third_arg = T_DIR_CODE;
	else if (q->args[THIRD_ARG].type == TOKEN_TREG)
		third_arg = T_REG_CODE;
	add_params_types(data, first_arg, second_arg, third_arg);

}

static void		dir_type_detector(t_expr *q)
{
	if (q->args[OP_NAME].type == TOKEN_ZJMP || q->args[OP_NAME].type == TOKEN_LDI || q->args[OP_NAME].type == TOKEN_STI ||
	q->args[OP_NAME].type == TOKEN_FORK || q->args[OP_NAME].type == TOKEN_LLDI || q->args[OP_NAME].type == TOKEN_LFORK)
		q->size = 2;
	else
		q->size = 1;
}

static void		write_address_to_free_label(t_codegen *data, t_expr *label)
{
	t_code_addr	*tmp;
	t_token		*token;

	token = label->args[LABEL_ARG].value;
	if (!(tmp = (t_code_addr*)malloc(sizeof(t_code_addr))))
		exit(-1);
	tmp->addr = data->add;
	printf("codegen, addr:%d, val:%s\n", tmp->addr, token->val);
	ft_hash_map_set_content(data->labels_free, token->val, (tmp));
}

static void		add_address_to_arg_label(t_codegen *data, t_arg *arg, int shift)
{
	t_label_data *label;

	if (!(label = (t_label_data*)malloc(sizeof(t_label_data))))
		exit(-1);
	label->name = ((t_token*)arg->value)->val;
	label->add = data->add + shift;
	label->instruction_begining = data->cur_instruction_addr;
	label->param_type = arg->type;
	label->size = data->cur_instruction_dirsize;

	ft_vector_add(data->labels_ptrs, label);
}

int 	bytesize(int num)
{
	int	ans;

	ans = 1;
	while(num >>= 1)
		ans += 1;
	return (!(ans % 8) ? (ans / 8) : (ans / 8)+ 1);
}

static void		fill_empty_cell(t_codegen *data, int size)
{
	while (size)
	{
		ft_memcpy(&(data->code[data->add++]),"\0", 1);
		--size;
	}
}

/*
 * ВЕЗДЕ ЛИ ОБРЕЗАЕТСЯ?
 */

void			cut_num_arg(int *num_arg, int param_type, char dir_type)
{
	if (param_type == TOKEN_TREG)
	{
		if (*num_arg > 255 || *num_arg < -256)
			exit(-1);
		return ;
	}
//	else if ((param_type == TOKEN_TDIR_INT && dir_type == 2) || param_type == TOKEN_TIND_INT)
//		*num_arg %=  ft_power(2, 16);
	else
		;
//		*num_arg %= ft_power(2, 32);
}



static void		fill_dirind_param(t_codegen *data, t_arg *param, char dir_type)
{
	int			num_arg;
	int 		cell_size;


	num_arg = ft_atol(((t_token *)param->value)->val);
//	if (param->type == TOKEN_TIND_INT)
//		num_arg %= IDX_MOD;
	if (param->type == TOKEN_TREG)
		cell_size = 1;
	else
		cell_size = param->type == TOKEN_TDIR_INT && dir_type == 1 ? 4 : 2;
	printf("cell_type:%d, num_arg:%d\n", cell_size, num_arg);
	rotate_bytes(&num_arg, cell_size);
	if (cell_size == 2) {
		short s = (short)num_arg;
		ft_memcpy(&(data->code[data->add]), &s, cell_size);
	}
	else
		ft_memcpy(&(data->code[data->add]), &num_arg, cell_size);
	data->add += cell_size;
}


static void		add_param(t_codegen *data, t_arg *param, char dir_type)
{
	int			arg;
	int 		shift;

	arg = 0;
	if (param->type == TOKEN_TIND_LAB || param->type == TOKEN_TDIR_LAB)
	{
		if ((param->type == TOKEN_TDIR_LAB && dir_type == 2) || param->type == TOKEN_TIND_LAB)
			shift = 2;
		else
			shift = 4;
		add_address_to_arg_label(data, param, 0);
		data->add += shift;
	}
	else
		fill_dirind_param(data, param, dir_type);
}
/*
 * переделать
 */

static void fill_codes(int array_of_codes[NUM_OF_TOKENS])
{
	array_of_codes[TOKEN_AFF] = OP_AFF_CODE;
	array_of_codes[TOKEN_ST]  = OP_ST_CODE;
	array_of_codes[TOKEN_STI] = OP_STI_CODE;
	array_of_codes[TOKEN_ADD] = OP_ADD_CODE;
	array_of_codes[TOKEN_SUB] = OP_SUB_CODE;
	array_of_codes[TOKEN_LD]  = OP_LD_CODE;
	array_of_codes[TOKEN_LLD] = OP_LLD_CODE;
	array_of_codes[TOKEN_LDI] = OP_LDI_CODE;
	array_of_codes[TOKEN_LLDI] = OP_LLDI_CODE;
	array_of_codes[TOKEN_AND] = OP_AND_CODE;
	array_of_codes[TOKEN_OR]  = OP_OR_CODE;
	array_of_codes[TOKEN_XOR] = OP_XOR_CODE;
	array_of_codes[TOKEN_LIVE] = OP_LIVE_CODE;
	array_of_codes[TOKEN_ZJMP] = OP_ZJMP_CODE;
	array_of_codes[TOKEN_FORK] = OP_FORK_CODE;
	array_of_codes[TOKEN_LFORK] = OP_LFORK_CODE;
}


static void map_expr_to_code(t_expr *expr)
{
	static int array_of_exprcodes[NUM_OF_TOKENS];

	if (array_of_exprcodes[TOKEN_LFORK])
		;
	else
		fill_codes(array_of_exprcodes);
	expr->type = array_of_exprcodes[expr->args[OP_NAME].type];
}


void		codegen_codegen(t_codegen *data, t_expr *q)
{
	static int expr_size[OP_NUM_OF_CODES];
	int i;

	i = 1;
	if (q->type == EXPR_LABEL_W)
		write_address_to_free_label(data, q);
	else if(q->type != EXPR_EOF)
	{
		dir_type_detector(q);
		map_expr_to_code(q);
		data->cur_instruction_addr = data->add;
		data->cur_instruction_code = q->type;
		data->cur_instruction_dirsize = q->size;
		data->code[data->add++] = q->type;
		data->code_size += 1;
		if (q->type != OP_LIVE_CODE && q->type != OP_ZJMP_CODE
			&& q->type != OP_FORK_CODE && q->type != OP_LFORK_CODE)
		{
			recast_params_types(data, q);
			data->code_size += 1;
		}
		while (i - 1 < q->arg_size && q->args[i].type)
		{
			add_param(data, &(q->args[i++]), q->size);
			if (q->args[i-1].type == TOKEN_TREG)
				data->code_size += 1;
			else if (q->args[i-1].type == TOKEN_TIND_LAB || q->args[i-1].type == TOKEN_TIND_INT
			|| ((q->args[i-1].type == TOKEN_TDIR_LAB || q->args[i-1].type == TOKEN_TDIR_INT) && q->size == 2))
				data->code_size += 2;
			else
				data->code_size += 4;
		}
//		data->code_size += expr_size[q->type];
	}
}


static void			codegen_ending(t_codegen *data)
{
	int				i;
	t_label_data	*ld;
	int				add;
	int				tmp;
	int 			cell_size;

	i = -1;
	while ((ld = ft_vector_get(data->labels_ptrs, ++i)))
	{
		add = (int)(((t_code_addr*)ft_hash_map_get(data->labels_free, ld->name))->addr);
		printf("add_addr:%d, val:%s, instr:%d\n", add, ld->name, ld->instruction_begining);
		tmp = (add - ld->instruction_begining);
		if (ld->param_type == TOKEN_TIND_LAB)
			tmp %= IDX_MOD;
		/*
		 * HERE PROBLEM
		 */
//		cell_size = ld->param_type == TOKEN_TDIR_LAB && ld->size == 1 ? 4 : 2;

		cell_size = (ld->param_type == TOKEN_TDIR_LAB && ld->size == 1) ? 4 : 2;
		rotate_bytes(&tmp, cell_size);
		if (cell_size == 2) {
			short temp = (short)tmp;
			ft_memcpy(&(data->code[ld->add]), (short *) &tmp, cell_size);
		}
		else
			ft_memcpy(&(data->code[ld->add]) , &tmp, cell_size);
	}
}


int				champ_exec_constructor(t_codegen *data)
{
	size_t			total_size;
	int				i;
	unsigned int	tmp_size;

	i = 0;
	codegen_ending(data);
	total_size = (PROG_NAME_LENGTH + COMMENT_LENGTH) + 16 + data->code_size;
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

void            init_header(header_t *header, t_vector*text)
{
    char        *name;
    char        *comment;

    name =((t_token*)((((t_expr*)text->items[0])->args[0]).value))->val;
    comment =((t_token*)((((t_expr*)text->items[1])->args[0]).value))->val;
    ft_bzero(header->comment, COMMENT_LENGTH + 1);
    ft_bzero(header->prog_name, PROG_NAME_LENGTH + 1);
    ft_memcpy(header->prog_name, name, ft_strlen(name));
    ft_memcpy(header->comment, comment, ft_strlen(comment));
    header->magic = COREWAR_EXEC_MAGIC;
//    printf("%d\n");
}

int         ar_len(char *ar)
{
	int res;

	res = 0;
	while (ar != NULL)
	{
		ar += 1;
		res += 1;
	}
	return (res);
}


void        write_code_to_file(char* exec,int code_size,char * filename)
{
	int     fd;
	char    *root;
	char    *new_name;



    if (!(root = ft_memalloc(ft_strlen(filename) - 1)))
    	exit(-1);
    if (ft_strncmp(filename + ft_strlen(filename) - 2, ".s", 2) != 0){
	    printf("bad filename or format\n");
	    exit(-1);
    }
    root = ft_strncpy(root, filename, ft_strlen(filename)  - 2);
    new_name = ft_strjoin(root, ".cor");
    free(root);
    printf("!!!!!!!!!!!!!!!%s\n", new_name);
    if (!(fd = open(new_name, O_WRONLY | O_CREAT))){
    	printf("can' open/create a file\n");
    	exit(-1);
    }
    write(fd, exec, code_size);

}


void            generate_code(t_hash_map *map, t_vector *text, char *filename)
{
    t_codegen   *codegen;
    header_t    header;
    int         fd;
    int         index;

    index = 2;

    init_header(&header, text);
    codegen = codegen_ctor(map, &header);
    while(index < text->total)
        codegen_codegen(codegen, text->items[index++]);
    write_code_to_file(codegen->exec, champ_exec_constructor(codegen), filename);
    /*
     * цикл, эндинг
     */

}

