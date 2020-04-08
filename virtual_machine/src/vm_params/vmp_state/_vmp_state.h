/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _vmp_state.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:18:37 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/08 22:17:22 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _VMP_STATE_H
# define _VMP_STATE_H

# include "libft.h"
# include "errors.h"
# include "vmp_state.h"

# define P_SHORT_NAME	"-n"
# define P_LONG_NAME	"--name"
# define P_SHORT_DUMP	"-d"
# define P_LONG_DUMP	"--dump"

int			_vmp_state_due_to_state(int state);
int			_vmp_state_due_to_param(char *param);

#endif
