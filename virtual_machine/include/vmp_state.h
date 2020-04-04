/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vmp_state.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/04 13:12:02 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/04 13:27:35 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VMP_STATE_H
# define VMP_STATE_H

enum					e_vmp_states
{
	VMP_INITIAL,
	SET_NBR_CYCLES,
	SET_PLAYER_NAME,
	SET_FILE_NAME,
	INCREMENT_PARAMS,
	VMP_STOP,
};

#endif