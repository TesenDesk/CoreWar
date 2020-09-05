/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_get_text_name.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/09 15:02:28 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/09 15:02:31 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_player.h"

char	*player_get_text_name(t_player *player)
{
	char	*player_name;

	if (!(player_name =
			malloc((ft_strlen(player->text_name) + 1) * sizeof(char))))
		ft_raise(__FILE__, __LINE__, ENOMEMORY);
	ft_strcpy(player_name, player->text_name);
	return (player_name);
}
