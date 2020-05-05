/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _arguments.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:10:32 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/12 17:29:22 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _ARGUMENTS_H
# define _ARGUMENTS_H

# include "libft.h"
# include "errors.h"
# include "arguments.h"
# include "arena.h"
# include "operation.h"

# define NO_ARGUMENT_TYPES	0x0

typedef struct			s_arguments
{
	int					op_code;
	int					types;
	int					are_match_operation_and_argument_types;
	int					arg_len;
	long				arg_1;
	long				arg_2;
	long				arg_3;
}						t_arguments;

t_arguments			*_arguments_new(void);
void					_arguments_destroy(t_arguments **self);


#endif
