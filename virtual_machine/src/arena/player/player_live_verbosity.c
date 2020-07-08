#include "prvt_player.h"

void			player_live_verbosity(t_player *self)
{
	if (vm_verbosity_lvl() & 1)
		printf("Player %i (%s) is said to be alive\n", self->name, self->text_name);
}