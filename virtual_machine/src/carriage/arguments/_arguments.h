/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _arguments.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:10:32 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/14 22:30:28 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ARGUMENTS_H
# define _ARGUMENTS_H

# include "libft.h"
# include "errors.h"
# include "arguments.h"
# include "arena.h"
# include "operation.h"
# include "types.h"

# define OP_CODE_SIZE	1




typedef struct			s_arguments
{
	int					arena_position;
	int					op_code;
	int					op_group;
	int					types;
	int					are_match_operation_and_argument_types;
	int					arg_1_size;
	int					arg_2_size;
	int					arg_3_size;
	int					code_size;
	long				arg_1;
	long				arg_2;
	long				arg_3;
}						t_arguments;

t_arguments		*_arguments_new(void);
void			_arguments_destroy(t_arguments **self);
void			_arguments_set_types(t_arguments *self, t_arena *arena);
void			_arguments_set_op_group(t_arguments *self);
int				_arguments_op_code_is_op_life(t_arguments *self);
void			_arguments_set_if_op_code_and_types_match(t_arguments *self);
void			_arguments_set_op_group(t_arguments *self)

#endif
