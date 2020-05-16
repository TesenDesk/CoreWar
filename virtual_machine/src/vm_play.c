/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vm_play.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/03 23:20:21 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/03 23:20:22 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "_vm.h"
#include "carriage/_carriage.h"
#include "arena/_arena.h"
#include "player.h"
#include "errors.h"

//static t_list *carriages_new( int players_num)
//{
//	int 	cur_player;
//	t_list	*new_car;
//	t_list	*core;
//
//	cur_player = 1;
////	if (!(ft_lstnew(carriage_new())))
//
//	while(cur_player <= players_num)
//	{
////		if (!(ft_lstnew()))
//		++cur_player;
//
//
//	}
//
//}

//void            vm_introducing_contestants(t_vm *self)
//{
//    t_player    **players;
//    t_player    *player;
//    int         index;
//    int         num_players;
//
////    players = arena_players(self->arena);
////    num_players = arena_nb_players(self->arena);
//    write(1, "Introducing contestants...\n", 27 );
////    printf("%i\n", num_players);
////    index = 0;
//
//    arena_players_introducing(self->arena);
//    while (index < num_players)
//    {
//        player = players[index];
//        player_introducing(player);
//        ++index;
//    }
//}

void 		    vm_play(t_vm *self)
{
	t_list	*carriages;

//    write(1, "there\n", 6);
    arena_players_introducing(self->arena);
//    while (TRUE)
//    {
//        carriages = self->carriage_head;
//        while (carriages)
//        {
//            carriages_take_next_step((t_carriage*)carriages);
//            vm_take_next_step(self);
//            carriages = carriages->next;
//        }
//    }
}