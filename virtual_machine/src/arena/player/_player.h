/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _player.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita_toropov <nikita_toropov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:10:36 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/26 21:14:57 by nikita_toro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PLAYER_H
# define _PLAYER_H

# include "libft.h"
# include "errors.h"
# include "player.h"
# include "vmp_player.h"
# include "file.h"  // ask about including this header

typedef struct s_code	t_code;

typedef struct		s_player
{
	int				name;
	char			*text_name;
	char			*text_comment;
	t_code			*code;
}					t_player;


#endif