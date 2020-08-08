//
// Created by Jhiqui Jerde on 8/8/20.
//

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