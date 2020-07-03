#ifndef PRVT_VM_PARAMS_PLAYER_H
# define PRVT_VM_PARAMS_PLAYER_H

# include "libft.h"
# include "errors.h"
# include "vmp_player.h"
# include "file.h"

typedef struct			s_vmp_player
{
	int					player_name;
	tt_file				*file;
}						t_vmp_player;

#endif
