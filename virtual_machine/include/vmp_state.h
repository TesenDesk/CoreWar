/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vmp_state.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 13:12:02 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/06 01:29:49 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VMP_STATE_H
# define VMP_STATE_H

enum					e_vmp_states
{
	VMP_STOP = -1,
	VMP_INITIAL,
	VMP_SET_PNAME,
	VMP_SET_CYCLES,
	VMP_SET_VERB,
	NBR_OF_VIRTUAL_METHODS,
};

int					vmp_state(int argtype);

#endif
