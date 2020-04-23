//
// Created by ikira on 13.03.2020.
//

#include "analyser_private.h"
#include "analyser_xtor_private.h"



t_analyser			*analyser_singleton_instance(int instantiation_status)
{
	static t_analyser	*analyser_instance;

	if (instantiation_status == ANALYSER_INSTANTIATE)
	{
		if (!analyser_instance)
			_analyser_ctor(&analyser_instance);
	}
	else if (instantiation_status == ANALYSER_DESTRUCT)
	{
		if (analyser_instance)
			_analyser_dtor(&analyser_instance);
	}
	return (analyser_instance);
}
