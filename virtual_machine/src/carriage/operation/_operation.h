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

typedef					(*t_operation)(t_carriage *carriage);
void                    _operation_live(t_carriage *self);
void                    _operation_ld(t_carriage *self);

#endif

