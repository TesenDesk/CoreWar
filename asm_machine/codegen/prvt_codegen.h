/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_codegen.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 20:54:51 by cmissy            #+#    #+#             */
/*   Updated: 2020/08/23 14:58:41 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRVT_CODEGEN_H
# define PRVT_CODEGEN_H

# include "op.h"
# include "codegen.h"
# include "codegen_prototype.h"
# include "token.h"
# include "expr.h"
# include <fcntl.h>

# define T_REG_CODE		1
# define T_DIR_CODE		2
# define T_IND_CODE		3

# define IND_PARAM_SIZE	2
# define DIR_PARAM_SIZE	4

enum			e_t_opcodes
{
	NO_OPCODE = 0,
	OP_LIVE_CODE,
	OP_LD_CODE,
	OP_ST_CODE,
	OP_ADD_CODE,
	OP_SUB_CODE,
	OP_AND_CODE,
	OP_OR_CODE,
	OP_XOR_CODE,
	OP_ZJMP_CODE,
	OP_LDI_CODE,
	OP_STI_CODE,
	OP_FORK_CODE,
	OP_LLD_CODE,
	OP_LLDI_CODE,
	OP_LFORK_CODE,
	OP_AFF_CODE,
	OP_NUM_OF_CODES,
};

typedef struct	s_codegen
{
	int				add;
	char			*code;
	char			*exec;
	unsigned int	code_size;
	int				cur_instruction_addr;
	int				cur_instruction_code;
	int				cur_instruction_dirsize;
	t_hash_map		*labels_free;
	t_vector		*labels_ptrs;
	t_header		*header;
	t_vector		*junk_container;
}				t_codegen;

void			rotate_four_bytes(unsigned int *p);
void			rotate_two_bytes(unsigned short *p);
void			rotate_bytes(unsigned int *p, int size);

void			generate_code(t_hash_map *map, t_vector *text, char *filename);
void			write_code_to_file(char *exec, int code_size, char *filename);
int				ar_len(char *ar);
void			init_header(t_header *header, t_vector *text);
void			codegen_ending(t_codegen *data);
void			codegen_codegen(t_codegen *data, t_expr *q);
void			do_something_in_cycle(t_codegen *data, t_expr *q);
void			map_expr_to_code(t_expr *expr);
void			fill_codes(int array_of_codes[NUM_OF_TOKENS]);
void			add_param(t_codegen *data, t_arg *param, char dir_type);
void			fill_dirind_param(t_codegen *data, t_arg *param, char dir_type);
void			cut_num_arg(int *num_arg, int param_type, char dir_type);
void			fill_empty_cell(t_codegen *data, int size);
int				bytesize(int num);
void			add_address_to_arg_label(t_codegen *data, t_arg *arg,
		int shift);
void			write_address_to_free_label(t_codegen *data, t_expr *label);
void			recast_params_types(t_codegen *data, t_expr *q);
void			add_params_types(t_codegen *data, int first_arg, int second_arg,
		int third_arg);
void			ft_printbits(char n, int count);
int				ft_checkbit(char n, int pos);
void			codegen_add_champ_comment(char *dst, t_header *header);
void			codegen_add_champ_name(char *dst, t_header *header);

#endif
