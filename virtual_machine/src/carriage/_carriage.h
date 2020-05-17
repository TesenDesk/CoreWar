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
//	char 			*text_player_name; // нужно или нет - хз
	int				player_name; // 1. уникальный код кареткии
	int				carry; // 2. Флаг, который может изменять некоторые операции. Изначально его значение равно false.
	int				op_code; // 3. До начала битвы значение этой переменной не установлено.
	int				is_correct_operation; //
	int				wait_so_many_cycles_to_perform_op; // циклов до операции (какая операция по умолчанию??)
	t_operation 	ops[NUMBER_OF_OPERATIONS];
	int				last_live_cycle; // посдедний цикл в котором каретка  live
	int				is_correct_op_code;
	int				arena_position;
	int				bytes_to_next_op;
	long int		registers[REG_NUMBER];
}							t_carriage;



#endif
