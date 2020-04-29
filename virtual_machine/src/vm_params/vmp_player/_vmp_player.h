/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _vmp_player.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita_toropov <nikita_toropov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:18:37 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/26 21:13:02 by nikita_toro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _VM_PARAMS_PLAYER_H
# define _VM_PARAMS_PLAYER_H

# include "libft.h"
# include "errors.h"
# include "vmp_player.h"
# include "file.h"

typedef struct			s_vmp_player
{
	int			player_name;
	t_file		*file;
}						t_vmp_player;

#endif
