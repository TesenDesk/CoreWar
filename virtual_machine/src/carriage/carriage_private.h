/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   carriage_private.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:18:37 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/02 18:26:33 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CARIAGE_PRIVATE_H
# define CARIAGE_PRIVATE_H

#include "op.h"
#include "operation.h"

typedef						(*t_operation)();

typedef struct				s_carriage
{
	int				id;
	int				carry;
	int				op_code;
	int				wait_so_many_cycles_to_perform_op;
	t_operation		ops[NUMBER_OF_OPERATIONS];
	int				announcment_cycle_that_live;
	int				arena_position;
	int				bytes_to_next_op;
	char			registers[REG_NUMBER][REG_SIZE];
}							t_carriage;


#endif