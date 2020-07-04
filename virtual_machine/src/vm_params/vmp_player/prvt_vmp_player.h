/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_vmp_player.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 17:19:40 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/04 17:19:40 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRVT_VMP_PLAYER_H
# define PRVT_VMP_PLAYER_H

# include "libft.h"
# include "errors.h"
# include "vmp_player.h"
# include "file.h"

typedef struct	s_vmp_player
{
	int			player_name;
	t_i_file	*file;
}				t_vmp_player;

#endif
