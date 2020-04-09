/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _type_cut_short.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/09 23:55:48 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/09 23:56:09 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_type_cut.h"

void						_type_cut_short(long int *registers)
{
	*registers = (short)*registers;
	return;
}
