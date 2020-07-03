/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_arg_is_num.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/02 18:59:32 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/02 18:59:36 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_vm_params.h"

int 				ft_arg_is_num(char *param)
{
	if (*param == '+' || *param == '-')
		++param;
	while (ft_isdigit(*param))
		++param;
	return (!(*param));
}
