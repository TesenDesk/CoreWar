#include "_arena.h"
#include "_player.h"

void    arena_players_introducing(t_arena *self)
{
    int         index;

    write(1, "Introducing contestants...\n", 27 );

//    player_introducing(self->players);
    index = 0;
    while (index < self->nb_players)
    {
        player_introducing(self->players[index]);
        ++index;
    }
    return;
}