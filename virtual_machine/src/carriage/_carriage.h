/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _carriage.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:18:37 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/13 01:41:25 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _CARIAGE_H
# define _CARIAGE_H

# include "libft.h"
# include "errors.h"
# include "op.h"
# include "operation.h"
# include "carriage.h"
# include "arena.h"

typedef struct				s_carriage
{
	t_arena			*arena;
	int				player_name;
	int				carry;
	int				op_code;
	int				is_correct_op_code;
	int				wait_so_many_cycles_to_perform_op;
	t_operation		ops[NUMBER_OF_OPERATIONS];
	int				announcment_cycle_that_live;
	int				arena_position;
	int				bytes_to_next_op;
	long int		registers[REG_NUMBER];
}							t_carriage;



#endif
