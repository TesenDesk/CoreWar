/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _arguments.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:10:32 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/13 00:48:58 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ARGUMENTS_H
# define _ARGUMENTS_H

# include "libft.h"
# include "errors.h"
# include "arguments.h"
# include "arena.h"
# include "operation.h"

// # define NO_ARGUMENT_TYPES	0x0

typedef struct			s_arguments
{
	int					arena_position;
	int					op_code;
	int					is_correct_op_code;
	int					types;
	int					are_match_operation_and_argument_types;
	int					arg_1_size;
	int					arg_2_size;
	int					arg_3_size;
	int					code_size;
	long				arg_1;
	long				arg_2;
	long				arg_3;
}						t_arguments;

enum			e_op_code_and_types_matching
{
	IND_NIL_NIL = 0xC0,
	NIL_IND_NIL = 0x30,
	NIL_NIL_REG = 0x04,
	NIL_DIR_NIL = 0x20,
	NIL_REG_NIL = 0x10,
	NO_ARGTYPES = 0x00,
	DIR_NIL_NIL = 0x80,
	REG_NIL_NIL = 0x40,
	DIR_REG_NIL = 0x90,
	IND_REG_NIL = 0xD0,
	REG_IND_NIL = 0x70,
	REG_REG_NIL = 0x50,
	DIR_DIR_REG = 0xA4,
	DIR_IND_REG = 0xB4,
	DIR_REG_REG = 0x94,
	IND_DIR_REG = 0xE4,
	IND_IND_REG = 0xF4,
	IND_REG_REG = 0xD4,
	REG_DIR_DIR = 0x68,
	REG_DIR_REG = 0x64,
	REG_IND_DIR = 0x78,
	REG_IND_REG = 0x74,
	REG_REG_DIR = 0x58,
	REG_REG_REG = 0x54,
};

t_arguments		*_arguments_new(void);
void			_arguments_destroy(t_arguments **self);
void			_arguments_set_types(t_arguments *self, t_arena *arena);
int				_arguments_op_code_is_op_life(t_arguments *self);
void			_arguments_set_if_operation_and_types_match(t_arguments *self);
int				_arguments_is_match_op_logic(t_arguments *self);
int				_arguments_is_match_op_load_i(t_arguments *self);
int				_arguments_is_match_op_sti(t_arguments *self);
int				_arguments_is_match_op_st(t_arguments *self);
int				_arguments_is_match_op_load(t_arguments *self);
int				_arguments_is_match_op_arithmetic(t_arguments *self);
int				_arguments_is_match_op_affect(t_arguments *self);
int				_arguments_is_match_op_life(t_arguments *self);
int				_arguments_not_nil_not_nil_reg(t_arguments *self);

#endif
