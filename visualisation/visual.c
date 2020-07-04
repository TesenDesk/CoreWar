//
// Created by Mudcrab Stygg on 7/4/20.
//


#include "visual.h"


t_wins            *win_constructor(t_wins win)
{
	t_wins        *new;
	if (!(new = (t_wins*)malloc(sizeof(t_wins))))
		exit(-1);
	if (!(new->main = newwin(0,0,0,0)))
		exit(-1);
}
