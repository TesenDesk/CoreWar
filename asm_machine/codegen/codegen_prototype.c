#include "prvt_codegen.h"
//#include <fcntl.h>
#include <fcntl.h>

static void		rotate_four_bytes(unsigned int *p)
{
	int			first;
	int			second;
	int			third;
	int			fourth;

	first = (*p & 0x000000ff) << 24;
	second = ((*p & 0xff000000) >> 24);
	third = ((*p & 0x0000ff00) << 8);
	fourth = ((*p & 0x00ff0000) >> 8);
	*p = second | fourth | third | first;
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
}

t_codegen		*codegen_ctor(t_hash_map *labels_free,
									t_header *header)
{
	t_codegen	*code;

	code = ft_memalloc(sizeof(t_codegen));
	code->labels_free = labels_free;
	if (!(code->labels_ptrs = (t_vector*)ft_memalloc(sizeof(t_vector))))
		exit(-1);
	ft_vector_init(code->labels_ptrs);
	code->header = header;
	code->code = ft_memalloc(sizeof(char) * 1000000);
	return (code);
}

void			codegen_dtor(t_codegen *code)
{
	if (code)
	{
//		if (code->labels_free)
//			free(code->labels_free);
		if (code->labels_ptrs) {
//			ft_vector_free(code->labels_ptrs);
			printf("!!!!!!!!!!!!!!!!!!!!!!!!!%d\n", code->labels_ptrs->total);
			ft_vector_free_data(code->labels_ptrs, label_dtor);
			free(code->labels_ptrs);
			code->labels_ptrs = NULL;
		}
		free(code->exec);
		code->exec = NULL;
		free(code->code);
		code->code = NULL;
		free(code);
		code = NULL;
	}
}
void 		label_dtor(void **data)
{
	if (data)
	{
		if (*data)
		{
//			printf("%s\n", (*((t_label_data**)data))->name);
//			free((*((t_label_data**)data))->name);
//			(*((t_label_data**)data))->name = NULL;
			free(*data);
			*data = NULL;
		}
	}

}

static void		codegen_add_champ_name(char *dst, t_header *header)
{
	ft_memcpy(dst, header->prog_name,
			sizeof(char) * ft_strlen(header->prog_name));
}

static void		codegen_add_champ_comment(char *dst, t_header *header)
{
	ft_memcpy(dst, header->comment,
			sizeof(char) * ft_strlen(header->comment));
}

int				ft_checkbit(char n, int pos)
{
	return ((n & (1 << pos)) != 0);
}

void			ft_printbits(char n, int count)
{
	while (count--)
	{
		ft_printf("%c", ft_checkbit(n, count) + '0');
		if (!(count % 4 && count))
			ft_putchar(' ');
	}
	ft_putchar('\n');
}

static void		add_params_types(t_codegen *data, int first_arg, int second_arg,
									int third_arg)
{
	int			res;

	res = 0;
	res |= first_arg << 6;
	res |= second_arg << 4;
	res |= third_arg << 2;
	data->code[data->add++] = (char)res;
}

static void		recast_params_types(t_codegen *data, t_expr *q)
{
	int			args[3];
	int			i;
	int			arg_type;

	args[0] = 0;
	args[1] = 0;
	args[2] = 0;
	i = FIRST_ARG;
	while (i <= THIRD_ARG)
	{
		arg_type = expr_get_arg_type(q, i);
		if (arg_type == TOKEN_TIND_INT || arg_type == TOKEN_TIND_LAB)
			args[i - 1] = T_IND_CODE;
		else if (arg_type == TOKEN_TDIR_INT || arg_type == TOKEN_TDIR_LAB)
			args[i - 1] = T_DIR_CODE;
		else if (arg_type == TOKEN_TREG)
			args[i - 1] = T_REG_CODE;
		i++;
	}
	add_params_types(data, args[0], args[1], args[2]);
}

static void		write_address_to_free_label(t_codegen *data, t_expr *label)
{
	t_code_addr	*tmp;
	t_token		*token;

	token = expr_get_arg_value(label, LABEL_ARG);
	if (!(tmp = (t_code_addr*)ft_memalloc(sizeof(t_code_addr))))
		exit(-1);
	tmp->addr = data->add;
	ft_hash_map_set_content(data->labels_free, token_get_value(token), (tmp));
}

static void		add_address_to_arg_label(t_codegen *data, t_arg *arg, int shift)
{
	t_label_data *label;

	if (!(label = (t_label_data*)malloc(sizeof(t_label_data))))
		exit(-1);
	label->name = token_get_value(arg_get_value(arg));
	label->add = data->add + shift;
	label->instruction_begining = data->cur_instruction_addr;
	label->param_type = arg_get_type(arg);
	label->size = data->cur_instruction_dirsize;
	ft_vector_add(data->labels_ptrs, label);
}

int				bytesize(int num)
{
	int			ans;

	ans = 1;
	while (num >>= 1)
		ans += 1;
	return (!(ans % 8) ? (ans / 8) : (ans / 8) + 1);
}

static void		fill_empty_cell(t_codegen *data, int size)
{
	while (size)
	{
		ft_memcpy(&(data->code[data->add++]), "\0", 1);
		--size;
	}
}

void			cut_num_arg(int *num_arg, int param_type, char dir_type)
{
	if (param_type == TOKEN_TREG)
	{
		if (*num_arg > 255 || *num_arg < -256)
			exit(-1);
		return ;
	}
}

static void			fill_dirind_param(t_codegen *data, t_arg *param,
					char dir_type)
{
	unsigned int	num_arg;
	int				cell_size;
	short			s;

	num_arg = (unsigned int)ft_atol(token_get_value(arg_get_value(param)));
	if (arg_get_type(param) == TOKEN_TREG)
		cell_size = 1;
	else
		cell_size = arg_get_type(param) == TOKEN_TDIR_INT && dir_type == 1 ?
			4 : 2;
	rotate_bytes(&num_arg, cell_size);
	if (cell_size == 2)
	{
		s = (short)num_arg;
		ft_memcpy(&(data->code[data->add]), &s, cell_size);
	}
	else
		ft_memcpy(&(data->code[data->add]), &num_arg, cell_size);
	data->add += cell_size;
}

static void		add_param(t_codegen *data, t_arg *param, char dir_type)
{
	int			arg;
	int			shift;
	int			arg_type;

	arg = 0;
	arg_type = arg_get_type(param);
	if (arg_type == TOKEN_TIND_LAB || arg_type == TOKEN_TDIR_LAB)
	{
		if ((arg_type == TOKEN_TDIR_LAB && dir_type == 2)
		|| arg_type == TOKEN_TIND_LAB)
			shift = 2;
		else
			shift = 4;
		add_address_to_arg_label(data, param, 0);
		data->add += shift;
	}
	else
		fill_dirind_param(data, param, dir_type);
}

static void		fill_codes(int array_of_codes[NUM_OF_TOKENS])
{
	array_of_codes[TOKEN_AFF] = OP_AFF_CODE;
	array_of_codes[TOKEN_ST] = OP_ST_CODE;
	array_of_codes[TOKEN_STI] = OP_STI_CODE;
	array_of_codes[TOKEN_ADD] = OP_ADD_CODE;
	array_of_codes[TOKEN_SUB] = OP_SUB_CODE;
	array_of_codes[TOKEN_LD] = OP_LD_CODE;
	array_of_codes[TOKEN_LLD] = OP_LLD_CODE;
	array_of_codes[TOKEN_LDI] = OP_LDI_CODE;
	array_of_codes[TOKEN_LLDI] = OP_LLDI_CODE;
	array_of_codes[TOKEN_AND] = OP_AND_CODE;
	array_of_codes[TOKEN_OR] = OP_OR_CODE;
	array_of_codes[TOKEN_XOR] = OP_XOR_CODE;
	array_of_codes[TOKEN_LIVE] = OP_LIVE_CODE;
	array_of_codes[TOKEN_ZJMP] = OP_ZJMP_CODE;
	array_of_codes[TOKEN_FORK] = OP_FORK_CODE;
	array_of_codes[TOKEN_LFORK] = OP_LFORK_CODE;
}

static void		map_expr_to_code(t_expr *expr)
{
	static int	array_of_exprcodes[NUM_OF_TOKENS];
	int			new_type;

	if (array_of_exprcodes[TOKEN_LFORK])
		;
	else
		fill_codes(array_of_exprcodes);
	new_type = array_of_exprcodes[expr_get_arg_type(expr, OP_NAME)];
	expr_set_type(expr, new_type);
}

static void		do_something_in_cycle(t_codegen *data, t_expr *q)
{
	int			i;
	t_arg		*curr_arg;
	int			arg_type;

	i = 1;
	while (i - 1 < expr_get_arg_size(q) && expr_get_arg_type(q, i))
	{
		arg_type = expr_get_arg_type(q, i);
		curr_arg = expr_get_arg(q, i++);
		add_param(data, curr_arg, (char)expr_get_size(q));
		if (arg_type == TOKEN_TREG)
			data->code_size += 1;
		else if (arg_type == TOKEN_TIND_LAB
		|| arg_type == TOKEN_TIND_INT
		|| ((arg_type == TOKEN_TDIR_LAB
		|| arg_type == TOKEN_TDIR_INT) && expr_get_size(q) == 2))
			data->code_size += 2;
		else
			data->code_size += 4;
	}
}

void			codegen_codegen(t_codegen *data, t_expr *q)
{
	if (expr_get_type(q) == EXPR_LABEL_W)
		write_address_to_free_label(data, q);
	else if (expr_get_type(q) != EXPR_EOF)
	{
		expr_set_size(q);
		map_expr_to_code(q);
		data->cur_instruction_addr = data->add;
		data->cur_instruction_code = expr_get_type(q);
		data->cur_instruction_dirsize = expr_get_size(q);
		data->code[data->add++] = expr_get_type(q);
		data->code_size += 1;
		if (expr_get_type(q) != OP_LIVE_CODE && expr_get_type(q) != OP_ZJMP_CODE
			&& expr_get_type(q) != OP_FORK_CODE && expr_get_type(q) !=
			OP_LFORK_CODE)
		{
			recast_params_types(data, q);
			data->code_size += 1;
		}
		do_something_in_cycle(data, q);
	}
}

static void			codegen_ending(t_codegen *data)
{
	int				i;
	t_label_data	*ld;
	int				add;
	int				tmp;
	int				cell_size;

	i = -1;
	while ((ld = ft_vector_get(data->labels_ptrs, ++i)))
	{
		add = (int)(((t_code_addr*)ft_hash_map_get(data->labels_free,
		ld->name))->addr);
		tmp = (add - ld->instruction_begining);
		if (ld->param_type == TOKEN_TIND_LAB)
			tmp %= IDX_MOD;
		cell_size = (ld->param_type == TOKEN_TDIR_LAB && ld->size == 1) ? 4 : 2;
		rotate_bytes((unsigned int*)&tmp, cell_size);
		if (cell_size == 2)
			ft_memcpy(&(data->code[ld->add]), (short *)&tmp, cell_size);
		else
			ft_memcpy(&(data->code[ld->add]), &tmp, cell_size);
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

void			init_header(t_header *header, t_vector *text)
{
	char		*name;
	char		*comment;

	name = token_get_value(expr_get_arg_value(text->items[0], 0));
	comment = token_get_value(expr_get_arg_value(text->items[1], 0));
	ft_bzero(header->comment, COMMENT_LENGTH + 1);
	ft_bzero(header->prog_name, PROG_NAME_LENGTH + 1);
	ft_memcpy(header->prog_name, name, ft_strlen(name));
	ft_memcpy(header->comment, comment, ft_strlen(comment));
	header->magic = COREWAR_EXEC_MAGIC;
}

int			ar_len(char *ar)
{
	int		res;

	res = 0;
	while (ar != NULL)
	{
		ar += 1;
		res += 1;
	}
	return (res);
}

void		write_code_to_file(char *exec, int code_size, char *filename)
{
	int		fd;
	char	*root;
	char	*new_name;

	if (!(root = ft_memalloc(ft_strlen(filename) - 1)))
		exit(-1);
	if (ft_strncmp(filename + ft_strlen(filename) - 2, ".s", 2) != 0)
	{
		ft_printf("bad filename or format\n");
		exit(-1);
	}
	root = ft_strncpy(root, filename, ft_strlen(filename) - 2);
	new_name = ft_strjoin(root, ".cor");
	free(root);
	if (!(fd = open(new_name, O_WRONLY | O_CREAT, S_IWUSR | S_IRUSR)))
	{
		ft_printf("can' open/create a file\n");
		exit(-1);
	}
	write(fd, exec, code_size);
	free(new_name);
}

void			generate_code(t_hash_map *map, t_vector *text, char *filename)
{
	t_codegen	*codegen;
	t_header	header;
	int			fd;
	int			index;
	int			size;

	index = 2;
	size = 0;
	init_header(&header, text);
	codegen = codegen_ctor(map, &header);
	while (index < text->total)
		codegen_codegen(codegen, text->items[index++]);
	size = champ_exec_constructor(codegen);
	write_code_to_file(codegen->exec, size, filename);
	codegen_dtor(codegen);
}
