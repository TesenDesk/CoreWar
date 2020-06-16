/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _operation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:19:51 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/10 15:45:29 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _OPERATION_H
# define _OPERATION_H

# include "libft.h"
# include "errors.h"
# include "op.h"
# include "operation.h"
# include "carriage.h"
# include "vm.h"
# include "_carriage.h"

# define TWO_BITS_MASK      3

enum					e_arguments
{
    ARG_1,
    ARG_2,
    ARG_3,
    NB_ARGS,
};

enum					e_siz_in_bytes
{
    ONE_BYTE = 1,
    TWO_BYTES,
    THREE_BYTES,
    FOUR_BYTES,
};

enum					e_type_codes
{
    CODE_T_REG = 1, //01
    CODE_T_DIR, //10
    CODE_T_IND, //11
};

int                    _operation_precheck_args(t_carriage *self, int *args, char *type_codes, int num_of_args, int *op_len);
void                    _operation_live(t_carriage *self);
void                    _operation_ld(t_carriage *self);
void                    _operation_st(t_carriage *self);
void                    _operation_add(t_carriage *self);
void                    _operation_sub(t_carriage *self);
void                    _operation_and(t_carriage *self);
void                    _operation_or(t_carriage *self);
void                    _operation_xor(t_carriage *self);
void                    _operation_zjmp(t_carriage *self);
void                    _operation_ldi(t_carriage *self);
void                    _operation_sti(t_carriage *self);
//void                    _operation_fork(t_carriage *self);
void                    _operation_lld(t_carriage *self);
void                    _operation_lldi(t_carriage *self);




#endif

