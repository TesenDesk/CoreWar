/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_get_text_comment.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 15:02:20 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/09 15:02:21 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_player.h"

char	*player_get_text_comment(t_player *player)
{
	return (player->text_comment);
}
