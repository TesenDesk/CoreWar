/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 21:07:20 by yurezz            #+#    #+#             */
/*   Updated: 2020/07/14 15:45:17 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "prvt_errors.h"

int				raise(char *file_name, int line_nb, int errmsg_index)
{
	(void)vm_singleton(VM_DESTRUCT, 0, NULL);
	ft_putstr_fd("Error! File: ", STDERR);
	ft_putstr_fd(file_name, STDERR);
	ft_putstr_fd(". Line: ", STDERR);
	ft_putnbr_fd(line_nb, STDERR);
	ft_putendl_fd(".", STDERR);
	ft_putendl_fd(g_error_messages[errmsg_index], STDERR);
	vm_singleton(VM_DESTRUCT, 0, NULL);
	exit(FAILURE);
}
