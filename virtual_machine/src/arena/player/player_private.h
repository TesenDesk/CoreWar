/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_private.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:10:36 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/01 19:57:23 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PALYER_PRIVATE_H
# define PLAYER_PRIVATE_H

typedef struct s_code	t_code;

typedef struct		s_player
{
	int				id;
	char			*text_name;
	char			*text_comment;
	t_code			*code;
}					t_player;


#endif