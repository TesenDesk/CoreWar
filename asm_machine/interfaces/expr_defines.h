/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expr_defines.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 21:06:45 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/14 21:06:56 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPR_DEFINES_H
# define EXPR_DEFINES_H

typedef enum		e_expr_defines
{
	EXPR_UNDEF = -1,
	EXPR_INIT,
	COM_LIVE,
	COM_LD,
	COM_ST,
	COM_ADD,
	COM_SUB,
	COM_AND,
	COM_OR,
	COM_XOR,
	COM_ZJMP,
	COM_LDI,
	COM_STI,
	COM_FORK,
	COM_LLD,
	COM_LLDI,
	COM_LFORK,
	COM_AFF,
	EXPR_LFEED,
	EXPR_LABEL_W,
	EXPR_CH_NAME_LINE,
	EXPR_CH_COMMENT_LINE,
	EXPR_OP_AFCT,
	EXPR_OP_STOR,
	EXPR_OP_STRI,
	EXPR_OP_ARIT,
	EXPR_OP_LOAD,
	EXPR_OP_LODI,
	EXPR_OP_LOGC,
	EXPR_OP_LIFE,
	EXPR_EOF,
	COUNT_EXPR,
}					t_expr_defines;

typedef enum		e_arg_defines
{
	ARG_INIT = 0,
	ARG_TREG,
	ARG_DIR_LAB,
	ARG_DIR_INT,
	ARG_IND_LAB,
	ARG_IND_INT,
}					t_arg_defines;

#endif
