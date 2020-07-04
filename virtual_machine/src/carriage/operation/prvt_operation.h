/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_operation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:19:51 by yurezz            #+#    #+#             */
/*   Updated: 2020/07/04 21:26:23 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRVT_OPERATION_H
# define PRVT_OPERATION_H

# include "libft.h"
# include "errors.h"
# include "op.h"
# include "operation.h"
# include "carriage.h"
# include "vm.h"
# include "prvt_carriage.h"

# define TWO_BITS_MASK	3

enum	e_num_of_arguments
{
	ONE_ARG = 1,
	TWO_ARGS,
	THREE_ARGS,
};

enum	e_arguments
{
	ARG_1,
	ARG_2,
	ARG_3,
	NB_ARGS,
};

enum	e_siz_in_bytes
{
	ONE_BYTE = 1,
	TWO_BYTES,
	THREE_BYTES,
	FOUR_BYTES,
};

enum	e_type_codes
{
	CODE_T_REG = 1,
	CODE_T_DIR,
	CODE_T_IND,
};

int			prvt_operation_precheck_args(t_carriage *self, int *args,
			char *type_codes, int num_of_args, int *op_len);
void		prvt_operation_live(t_carriage *self);
void		prvt_operation_ld(t_carriage *self);
void		prvt_operation_st(t_carriage *self);
void		prvt_operation_add(t_carriage *self);
void		prvt_operation_sub(t_carriage *self);
void		prvt_operation_and(t_carriage *self);
void		prvt_operation_or(t_carriage *self);
void		prvt_operation_xor(t_carriage *self);
void		prvt_operation_zjmp(t_carriage *self);
void		prvt_operation_ldi(t_carriage *self);
void		prvt_operation_sti(t_carriage *self);
void		prvt_operation_fork(t_carriage *self);
void		prvt_operation_lld(t_carriage *self);
void		prvt_operation_lldi(t_carriage *self);
void		prvt_operation_lfork(t_carriage *self);
void		prvt_operation_aff(t_carriage *self);
int         prvt_op_num_of_args(int op_code);


#endif
