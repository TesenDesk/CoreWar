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
# define NUM_OF_ARGS_ARRAY	{0, 1, 2, 2, 3, 3, 3, 3, 3, 1, 3, 3, 1, 2, 3, 1, 1}
# define DIR_SIZE_IN_OPS	{0, 4, 4, 4, 4, 4, 4, 4, 4, 2, 2, 2, 2, 4, 2, 2, 4}

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

//enum	e_siz_in_bytes
//{
//	ONE_BYTE = 1,
//	TWO_BYTES,
//	THREE_BYTES,
//	FOUR_BYTES,
//};

int operation_precheck_args(t_carriage *self, int *args,
			char *type_codes, int num_of_args, int *op_len);
void operation_live(t_carriage *self);
void operation_ld(t_carriage *self);
void operation_st(t_carriage *self);
void operation_add(t_carriage *self);
void operation_sub(t_carriage *self);
void operation_and(t_carriage *self);
void operation_or(t_carriage *self);
void operation_xor(t_carriage *self);
void operation_zjmp(t_carriage *self);
void operation_ldi(t_carriage *self);
void operation_sti(t_carriage *self);
void operation_fork(t_carriage *self);
void operation_lld(t_carriage *self);
void operation_lldi(t_carriage *self);
void operation_lfork(t_carriage *self);
void operation_aff(t_carriage *self);
int         prvt_op_num_of_args(int op_code);


#endif
