/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _analyser_xtor.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 18:50:49 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/14 18:52:25 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_analyser_xtor.h"

t_analyser			*prvt_analyser_ctor(t_analyser **analyser)
{
	if (!(*analyser = (t_analyser *)malloc(sizeof(t_analyser))))
	{
		printf("error\n");
		exit(-1);
	}
	(*analyser)->state = ANALYSER_INIT_ST;
	(*analyser)->prvt_change_state = prvt_analyser_change_state;
	(*analyser)->prvt_get_expr = prvt_analyser_get_expr;
	return (*analyser);
}

void				prvt_analyser_dtor(t_analyser **analyser)
{
	(*analyser)->parser = parser_singleton_instance(PARSER_DESTRUCT);
	ft_memdel((void **)analyser);
}
