/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   analyser_singleton_instance.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 19:34:19 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/14 19:44:57 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_analyser.h"
#include "prvt_analyser_xtor.h"

t_analyser				*analyser_singleton_instance(int instantiation_status)
{
	static t_analyser	*analyser_instance;

	if (instantiation_status == ANALYSER_INSTANTIATE)
	{
		if (!analyser_instance)
			prvt_analyser_ctor(&analyser_instance);
	}
	else if (instantiation_status == ANALYSER_DESTRUCT)
	{
		if (analyser_instance)
			prvt_analyser_dtor(&analyser_instance);
	}
	return (analyser_instance);
}
