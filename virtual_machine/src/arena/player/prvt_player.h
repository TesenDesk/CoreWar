/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_player.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/04 18:04:29 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/04 18:07:11 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRVT_PLAYER_H
# define PRVT_PLAYER_H

# include "libft.h"
# include "errors.h"
# include "player.h"
# include "vmp_player.h"
# include "vm.h"

typedef struct		s_player
{
	int				name;
	char			*text_name;
	char			*text_comment;
	void			*code;
	unsigned int	code_size;
}					t_player;

#endif
