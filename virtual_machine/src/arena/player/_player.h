/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _player.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:10:36 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/08 18:53:31 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _PALYER_H
# define _PLAYER_H

# include "libft.h"
# include "errors.h"
# include "player.h"
# include "vmp_player.h"
# include "code/_code.h"

typedef struct s_code	t_code;

typedef struct		s_player
{
	int				name;
	char			*text_name;
	char			*text_comment;
	t_code			*code;
}					t_player;


#endif