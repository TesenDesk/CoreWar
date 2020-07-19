/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_carriage.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 20:37:41 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/04 20:37:53 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRVT_CARRIAGE_H
# define PRVT_CARRIAGE_H

# include "libft.h"
# include "errors.h"
# include "op.h"
# include "operation.h"
# include "arena.h"
# include "carriage.h"

typedef struct		s_carriage
{
	t_arena			*arena;
	int				num;
	int				p_name;
	int				carry;
	int				op_code;
	int				cycles_to_perform_op;
	int				last_live_cycle;
	int				is_correct_op_code;
	int				arena_position;
	int				registers[REG_NUMBER];
	int             was_store;
	int             was_live;
	unsigned int             stor_pos;
}					t_carriage;

void				prvt_carriage_set_op_code(t_carriage *self, t_arena *arena);
void				prvt_carriage_set_is_correct_op_code(t_carriage *self);
void				prvt_carriage_set_cycles_to_perform_op(t_carriage *self);

#endif
