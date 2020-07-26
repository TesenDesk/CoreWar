/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arg_getters.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/19 17:35:45 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/19 17:35:45 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_expr.h"

void		*arg_get_value(t_arg *self)
{
	return (self->value);
}

int			arg_get_type(t_arg *self)
{
	return (self->type);
}
