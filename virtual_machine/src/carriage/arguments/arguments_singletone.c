/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arguments_singletone.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/08 23:12:16 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/12 13:33:11 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_arguments.h"

t_arguments					*arguments_singleton(int instantiation_status)
{
	static t_arguments		*self;

	if (instantiation_status == ARGUMENTS_INSTANTIATE)
	{
		if (self == NULL)
			self = _arguments_new();
	}
	else if (instantiation_status == ARGUMENTS_DESTRUCT)
	{
		if (self != NULL)
			_arguments_destroy(&self);
	}
	return (self);
}