/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:10:01 by yurezz            #+#    #+#             */
/*   Updated: 2020/07/13 17:52:45 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OPERATION_H
# define OPERATION_H

# include "libft.h"
# include "errors.h"
# include "op.h"
# include "vm.h"
# include "../src/carriage/prvt_carriage.h"

# define NUM_OF_OPERATIONS	DEAD_LINE - 1
# define TYPE_CODE_SIZE		(MAX_ARGS_NUMBER*2)/8+((MAX_ARGS_NUMBER*2)%8)?1:0
# define OP_CODE_SIZE		1
# define BITS_PER_BYTE		8
# define TWO_BITS			2
# define TWO_BITS_MASK		3
# define T_REG_SIZE			1
# define T_IND_SIZE			IND_SIZE
# define NUM_OF_ARG_TYPES	3

enum				e_op_codes
{
	OP_LIVE = 1,
	OP_LD,
	OP_ST,
	OP_ADD,
	OP_SUB,
	OP_AND,
	OP_OR,
	OP_XOR,
	OP_ZJMP,
	OP_LDI,
	OP_STI,
	OP_FORK,
	OP_LLD,
	OP_LLDI,
	OP_LFORK,
	OP_AFF,
	DEAD_LINE
};

enum	e_arguments
{
	ARG_1,
	ARG_2,
	ARG_3,
};

typedef struct s_carriage	t_carriage;

typedef struct			s_op
{
	char				*name;
	int					code;
	int					args_num;
	char				args_types_code;
	char				args_types[MAX_ARGS_NUMBER];
	int					t_dir_size;
	int					cycles_to_perform;
	int					args[MAX_ARGS_NUMBER];
	char				type_codes[MAX_ARGS_NUMBER];
	int					op_len;
	void 				(*operation)(t_carriage *self);
}						t_op;

int						operation_precheck_args(t_carriage *self, t_op *op);
void					operation_live(t_carriage *self);
void					operation_ld(t_carriage *self);
void					operation_st(t_carriage *self);
void					operation_add(t_carriage *self);
void					operation_sub(t_carriage *self);
void					operation_and(t_carriage *self);
void					operation_or(t_carriage *self);
void					operation_xor(t_carriage *self);
void					operation_zjmp(t_carriage *self);
void					operation_ldi(t_carriage *self);
void					operation_sti(t_carriage *self);
void					operation_fork(t_carriage *self);
void					operation_lld(t_carriage *self);
void					operation_lldi(t_carriage *self);
void					operation_lfork(t_carriage *self);
void					operation_aff(t_carriage *self);
void					operation_dispatched(t_carriage *self);

static t_op				g_op[16] = {
		{
				.name = "live",
				.code = OP_LIVE,
				.args_num = 1,
				.args_types_code = FALSE,
				.args_types = {T_DIR, 0, 0},
				.t_dir_size = DIR_SIZE,
				.cycles_to_perform = 10,
				.operation = operation_live,
		},
		{
				.name = "ld",
				.code = OP_LD,
				.args_num = 2,
				.args_types_code = TRUE,
				.args_types = {T_DIR | T_IND, T_REG, 0},
				.t_dir_size = DIR_SIZE,
				.cycles_to_perform = 5,
				.operation = operation_ld,
		},
		{
				.name = "st",
				.code = OP_ST,
				.args_num = 2,
				.args_types_code = TRUE,
				.args_types = {T_REG, T_REG | T_IND, 0},
				.t_dir_size = DIR_SIZE,
				.cycles_to_perform = 5,
				.operation = operation_st,
		},
		{
				.name = "add",
				.code = OP_ADD,
				.args_num = 3,
				.args_types_code = TRUE,
				.args_types = {T_REG, T_REG, T_REG},
				.t_dir_size = DIR_SIZE,
				.cycles_to_perform = 10,
				.operation = operation_add,
		},
		{
				.name = "sub",
				.code = OP_SUB,
				.args_num = 3,
				.args_types_code = TRUE,
				.args_types = {T_REG, T_REG, T_REG},
				.t_dir_size = DIR_SIZE,
				.cycles_to_perform = 10,
				.operation = operation_sub,
		},
		{
				.name = "and",
				.code = OP_AND,
				.args_num = 3,
				.args_types_code = TRUE,
				.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
				.t_dir_size = DIR_SIZE,
				.cycles_to_perform = 6,
				.operation = operation_and,
		},
		{
				.name = "or",
				.code = OP_OR,
				.args_num = 3,
				.args_types_code = TRUE,
				.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
				.t_dir_size = DIR_SIZE,
				.cycles_to_perform = 6,
				.operation = operation_or,
		},
		{
				.name = "xor",
				.code = OP_XOR,
				.args_num = 3,
				.args_types_code = TRUE,
				.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR | T_IND, T_REG},
				.t_dir_size = DIR_SIZE,
				.cycles_to_perform = 6,
				.operation = operation_xor,
		},
		{
				.name = "zjmp",
				.code = OP_ZJMP,
				.args_num = 1,
				.args_types_code = FALSE,
				.args_types = {T_DIR, 0, 0},
				.t_dir_size = DIR_SIZE / 2,
				.cycles_to_perform = 20,
				.operation = operation_zjmp,
		},
		{
				.name = "ldi",
				.code = OP_LDI,
				.args_num = 3,
				.args_types_code = TRUE,
				.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
				.t_dir_size = DIR_SIZE / 2,
				.cycles_to_perform = 25,
				.operation = operation_ldi,
		},
		{
				.name = "sti",
				.code = OP_STI,
				.args_num = 3,
				.args_types_code = TRUE,
				.args_types = {T_REG, T_REG | T_DIR | T_IND, T_REG | T_DIR},
				.t_dir_size = DIR_SIZE / 2,
				.cycles_to_perform = 25,
				.operation = operation_sti,
		},
		{
				.name = "fork",
				.code = OP_FORK,
				.args_num = 1,
				.args_types_code = FALSE,
				.args_types = {T_DIR, 0, 0},
				.t_dir_size = DIR_SIZE / 2,
				.cycles_to_perform = 800,
				.operation = operation_fork,
		},
		{
				.name = "lld",
				.code = OP_LLD,
				.args_num = 2,
				.args_types_code = TRUE,
				.args_types = {T_DIR | T_IND, T_REG, 0},
				.t_dir_size = DIR_SIZE,
				.cycles_to_perform = 10,
				.operation = operation_lld,
		},
		{
				.name = "lldi",
				.code = OP_LLDI,
				.args_num = 3,
				.args_types_code = TRUE,
				.args_types = {T_REG | T_DIR | T_IND, T_REG | T_DIR, T_REG},
				.t_dir_size = DIR_SIZE / 2,
				.cycles_to_perform = 50,
				.operation = operation_lldi,
		},
		{
				.name = "lfork",
				.code = OP_LFORK,
				.args_num = 1,
				.args_types_code = FALSE,
				.args_types = {T_DIR, 0, 0},
				.t_dir_size = DIR_SIZE / 2,
				.cycles_to_perform = 1000,
				.operation = operation_lfork,
		},
		{
				.name = "aff",
				.code = OP_AFF,
				.args_num = 1,
				.args_types_code = TRUE,
				.args_types = {T_REG, 0, 0},
				.t_dir_size = DIR_SIZE,
				.cycles_to_perform = 2,
				.operation = operation_aff,
		}
};

#endif
