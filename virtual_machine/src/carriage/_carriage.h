/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _carriage.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:18:37 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/09 00:04:19 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CARIAGE_H
# define _CARIAGE_H

# include "op.h"
# include "operation.h"
# include "carriage.h"

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
