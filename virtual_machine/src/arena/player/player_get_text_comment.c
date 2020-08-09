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
	char	*player_comment;

	if (!(player_comment = malloc(ft_strlen((player->text_comment)
		+ 1) * sizeof(char))))
		ft_raise(__FILE__, __LINE__, ENOMEMORY);
	ft_strcpy(player_comment, player->text_comment);
	return (player_comment);
}
