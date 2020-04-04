/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 21:07:20 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/04 16:42:48 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "_errors.h"

static char		*error_messages[ERRMSGCOUNT] =
{
	"Usage: ./corewar [-d nbr_cycles] [[-n number] player1.cor ...]\n"
	"\n"
	"Here is the text about the programm."
	"\n"
	"Options:\n"
	"\t"	"-n, --number\t"	"& means ...\n"
	"\t"	"-d, --dump\t"		"& means ...\n",
	"Could not allocate memory.",
	"Invalid argument.",
	"Invalid command line argument. "
		"Option flag is set but its value is absent.",
	"Bad filename.",
	"Can not close the file.",
	"Can not read the file."
};

int				errors(char *file_name, int line_nb, int errmsg_index)
{
	(void)vm_singleton(VM_DESTRUCT, 0, NULL);
	ft_putstr_fd("Error! File: ", STDERR);
	ft_putstr_fd(file_name, STDERR);
	ft_putstr_fd(". Line: ", STDERR);
	ft_putnbr_fd(line_nb, STDERR);
	ft_putendl_fd(".", STDERR);
	ft_putendl_fd(error_messages[errmsg_index], STDERR);
	exit (FAILURE);
}