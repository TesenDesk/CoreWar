#include "_player.h"

void		player_print_winner(t_player *self)
{
//    char    *player_nb;
//    write(1, "Contestant ", 11);
//    player_nb = ft_itoa(self->);
//    write(1, player_nb, ft_strlen(player_nb));
//    free(player_nb);
//
//    write(1, ", \"", 3 );
//    write(1, self->text_name, ft_strlen(self->text_name));
//    write(1, "\", has won !\n", 13);

    printf("Contestant %i, \"%s\", has won !\n", self->name, self->text_name);

    return;
}