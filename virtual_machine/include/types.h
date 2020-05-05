/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   types.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/14 19:37:39 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/14 22:12:07 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TYPES_H 
# define TYPES_H

enum						e_op_code_and_types_matching
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

typedef struct s_arguments	t_arguments;
typedef int					(*t_types)(t_arguments *arguments);

int				types_do_match_op_life(int self);
int				types_do_match_op_affect(int self);
int				types_do_match_op_load(int self);
int				types_do_match_op_store(int self);
int				types_do_match_op_load_i(int self);
int				types_do_match_op_store_i(int self);
int				types_do_match_op_logic(int self);
int				types_do_match_op_arithmetic(int self);

#endif
