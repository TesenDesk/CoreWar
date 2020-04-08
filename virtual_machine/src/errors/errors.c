/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 21:07:20 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/09 00:05:12 by yurezz           ###   ########.fr       */
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
	"Can not read the file.",
	"Integer over- / underflow.",
	"Try to read not opend file.",
	"Try to open already opened file.",
	"Try to close not opened file.",
	"Forbidden ivocation of mock method.",
	"There is not a player passed to the programm.",
	"Invalid constats at interface file. (Probably at op.h).",
	"Player name exсeedes number of players. "
		"Or is invalid to some other reasons.",
	"Repetition of the parameter -n value.",
	"Try to replace pointer to memory not being freed.",
};

int				raise(char *file_name, int line_nb, int errmsg_index)
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