/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_op_code.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/12 17:52:51 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/12 17:59:07 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_arena.h"

int				arena_op_code(t_arena *self, int arena_position)
{
	int			op_code;

	op_code = (int)(char)((char *)(self->data))[arena_position];
	return (op_code);
}
