//
// Created by Jhiqui Jerde on 8/8/20.
//

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