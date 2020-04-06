/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _vmp_player.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:18:37 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/06 17:18:45 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _VM_PARAMS_PLAYER_H
# define _VM_PARAMS_PLAYER_H

# include "libft.h"
# include "errors.h"

typedef struct			s_vmp_player
{
	int			player_name;
	int			fd;
	char		*file_name;
	int			is_opened;
}						t_vmp_player;


#endif