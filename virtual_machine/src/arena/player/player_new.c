/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_new.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita_toropov <nikita_toropov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:30:11 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/15 04:15:31 by nikita_toro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_player.h"
#include "_vmp_player.h"
# define COREWAR_EXEC_MAGIC			15369203 // 0xea83f3;
# define COREWAR_EXEC_MAGIC_LENGTH	4
# define PROG_NAME_LENGTH			128
# define NULL_LENGTH				4
# define CHAMP_MAX_SIZE				682
# define CHAMP_SIZE_LENGTH			4
# define COMMENT_LENGTH				2048


int				magic_header_check(t_vmp_player *vmp_player)
{
	int		magic_header_in_file;

	magic_header_in_file = *(int*)(vmp_player->file->file);
	if (magic_header_in_file == COREWAR_EXEC_MAGIC)
		return (SUCCESS);
	else
		return (FAILURE);
}

int				code_size_check(t_vmp_player *vmp_player)
{
	char		*text;
	int			champion_code_size;
	int			champion_file_size;

	text = vmp_player->file->file;
	text += COREWAR_EXEC_MAGIC_LENGTH
		+ PROG_NAME_LENGTH
		+ NULL_LENGTH;
	champion_code_size = *(int*)text;
	champion_file_size = COREWAR_EXEC_MAGIC_LENGTH
		+ PROG_NAME_LENGTH
		+ NULL_LENGTH
		+ CHAMP_SIZE_LENGTH
		+ COMMENT_LENGTH
		+ NULL_LENGTH
		+ champion_code_size;
	if (champion_code_size > CHAMP_MAX_SIZE &&
	champion_file_size != vmp_player->file->file_size)
		return (SUCCESS);
	else
		return (FAILURE);
}

static void		player_new_precondition_check(t_vmp_player *vmp_player)
{
	// наличие magic header'а'
	magic_header_check(vmp_player);
	// соответствие указанного размера кода реальному и так далее
	// максимальному размеру исполняемого кода
	code_size_check(vmp_player);
	return ;
}

char			*_player_text_name_from_vmp_player(t_vmp_player *vmp_player)
{
	char		*name_in_text;
	size_t		len;

	name_in_text = vmp_player->file->file;
	name_in_text += COREWAR_EXEC_MAGIC_LENGTH;
	len = ft_strlen(name_in_text);
	vmp_player->player_name = ft_strnew(len);
	ft_strcpy(vmp_player->player_name, name_in_text);
}

t_player		*player_new(t_vmp_player *vmp_player)
{
	t_player	*self;

	player_new_precondition_check(vmp_player);
	if ((self = (t_player *)ft_memalloc(sizeof(*self))) == NULL)
		raise(__FILE__, __LINE__, ENOMEMORY);
	self->name = _player_name_from_vmp_player(vmp_player);
	self->text_name = _player_text_name_from_vmp_player(vmp_player);
	self->text_comment = _player_text_comment_from_vmp_player(vmp_player);
	self->text_name = code_new(vmp_player);
	return (self);
}

