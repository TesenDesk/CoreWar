/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arena_new.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nikita_toropov <nikita_toropov@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:29:47 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/24 20:31:19 by nikita_toro      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_player.h"
#include "_arena.h"
#include "vm_params.h"
#include "./vm_params/_vm_params.h"
#include "vmp_player.h"
#include "player.h"
#include "./arena/player/_player.h"
#include "unistd.h"
static void			_arena_new_precondition_check(void)
{
	if (MEM_SIZE <= 0 || CHAMP_MAX_SIZE <= 0 || REG_NUMBER <= 0)
		raise(__FILE__, __LINE__, EINVALCONSTANTS);
	return;
}

static void			arena_fill_in_the_data(t_arena *self)
{
	char			*arena_field;
	int 			curr;
	int 			step;

	step = MEM_SIZE / self->nb_players;
	curr = 0;
	if (!(arena_field = ft_memalloc(MEM_SIZE * sizeof(char))))
		raise(__FILE__, __LINE__, EINVALCONSTANTS);
	while (curr < self->nb_players)
	{
		ft_memcpy((arena_field + (curr) * step), self->players[curr]->code,
				self->players[curr]->code_size);
		curr += 1;
	}
	self->data = arena_field;

	return ;
}


t_arena				*arena_new(t_vm_params *params)
{
	t_arena			*self;

	_arena_new_precondition_check();
	if ((self = (t_arena *)ft_memalloc(sizeof(*self))) == NULL)
		raise(__FILE__, __LINE__, ENOMEMORY);
	self->nb_players = vm_params_nb_players(params);
	self->players = _arena_players_new(self->nb_players);
	self->dump_cycles = params->dump_cycles;
//	printf("aren_dump:%d\n", self->dump_cycles);


	vm_params_fill_and_sort_array_of_players(params, self);





    //	vm_params_destroy_players_lists(params); // problems, check it
	arena_fill_in_the_data(self);
//    write(1, "there\n", 6);
	arena_print_dump(self);

    arena_players_introducing(self);
	return (self);
}
