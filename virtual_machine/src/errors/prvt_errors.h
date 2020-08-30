/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_errors.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/01 17:10:49 by yurezz            #+#    #+#             */
/*   Updated: 2020/08/30 17:05:37 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRVT_ERRORS_H
# define PRVT_ERRORS_H

# include "libft.h"
# include "errors.h"
# include "vm.h"

static char		*g_error_messages[ERRMSGCOUNT] =
{
	"Usage: ./corewar [-d N -v N] [[-n number] <champion1.cor> <...>]\n"
	"\n"
	"Options:\n"
	"\t-n N, -number N\t: Dumps memory after N cycles then exits\n"
	"\t-d N, -dump N\t: Set the next champion to the N position\n"
	"\t-v N\t\t: Verbosity levels, can be added together to enable several\n"
	"\t\t\t- 0 : Show only essentials\n"
	"\t\t\t- 1 : Show lives\n"
	"\t\t\t- 2 : Show cycles\n"
	"\t\t\t- 4 : Show operations (Params are NOT litteral ...)\n"
	"\t\t\t- 8 : Show deaths\n"
	"\t-curses : Ncurses output mode",
	"Could not allocate memory.",
	"Invalid argument.",
	"Invalid command line argument. "
	"Option flag is set but its value is absent.",
	"Can not close the file.",
	"Can not read the file.",
	"Try to open already opened file.",
	"Try to close not opened file.",
	"There is not a player passed to the programm.",
	"Invalid constats at interface file. (Probably at op.h).",
	"Player name exсeedes number of players. "
	"Or is invalid to some other reasons.",
	"Repetition of the parameter -n value.",
	"Try to replace pointer to memory not being freed.",
	"Loss of information due to some reasons. "
	"(REG_SIZE is less then number of players.)",
	"Wrong code_size.",
	"Incorrectly placed NULLs in data.",
	"No magic header.",
	"To many players.",
	"Bad filename.",
};

#endif
