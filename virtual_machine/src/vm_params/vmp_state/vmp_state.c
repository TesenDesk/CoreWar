/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vmp_state.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurezz <yurezz@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/04/02 21:07:27 by yurezz            #+#    #+#             */
/*   Updated: 2020/04/08 22:17:41 by yurezz           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <vm_params/_vm_params.h>
#include "_vmp_state.h"

# define P_SHORT_NAME	"-n"
# define P_LONG_NAME	"--name"
# define P_SHORT_DUMP	"-d"
# define P_LONG_DUMP	"--dump"
# define FLAG_CYCLE		"-s"
# define FLAG_VERB		"-v"
# define FLAG_BINARY	"-b"
# define FLAG_STEALTH	"--stealth"
# define FLAG_NCURSES	"--curses"


static int 					is_flag(char *param)
{		return (ft_strncmp(P_SHORT_NAME, param, 2) 	||
			ft_strncmp(P_LONG_NAME, param, 6)  		||
			ft_strncmp(FLAG_CYCLE, param, 2)   		||
			ft_strncmp(P_SHORT_DUMP, param, 2) 		||
			ft_strncmp(P_LONG_DUMP, param, 6)  		||
			ft_strncmp(FLAG_VERB, param, 2)    		||
			ft_strncmp(FLAG_STEALTH, param, 9) 		||
			ft_strncmp(FLAG_NCURSES, param, 8)
		);
}

static int 					is_numflag(char *param)
{
	return(ft_strncmp(P_SHORT_NAME, param, 2) 		||
				ft_strncmp(P_LONG_NAME, param, 6)  	||
				ft_strncmp(FLAG_CYCLE, param, 2)   	||
				ft_strncmp(FLAG_VERB, param, 2)
	);

}

static int 					chose_numflag(char *param) {
	if (ft_strncmp(P_SHORT_NAME, param, 2) ||
		ft_strncmp(P_LONG_NAME, param, 6))
		return (VMP_SET_PNAME);
	else if (ft_strncmp(FLAG_CYCLE, param, 2))
		return (VMP_SET_CYCLES);
	else if(ft_strncmp(FLAG_VERB, param, 2))
		return (VMP_SET_VERB);
}

//static int 					chose_flag(char *param)
//{
//
//	if (ft_strncmp(P_SHORT_DUMP, param, 2) ||
//	ft_strncmp(P_LONG_DUMP, param, 6))
//		return (VMP_SET_DUMP);
//	else if(ft_strncmp(FLAG_STEALTH, param, 9))
//		return (VMP_SET_STEALTH);
//	else if(ft_strncmp(FLAG_NCURSES, param, 8))
//		return (VMP_SET_NCURSES);
//
//}



//static int 				find_next_to_init(char *param)
//{
//	if(is_flag(param))
//	{
//		if (is_numflag(param))
//			return (chose_numflag(param));
//		return (chose_flag(param));
//	}
//		return (VMP_WAIT_FOR_NUM);
//	else
//		return (VMP_INITIAL);
//}

static int 				state_is_nonumflag(int state)
{
	return (state == VMP_SET_PNAME || state == VMP_SET_CYCLES
	|| state == VMP_SET_VERB);
}



//int 					vmp_state(int argtype)
//{
//	static int 			state;
//
//	if (state == VMP_INITIAL && !param) {
//		printf(USAGE_STR);
//		exit(0);
//	}
//	else if (state == VMP_INITIAL && param)
//		return (find_next_to_init(param));
//	else if(state == VMP_WAIT_FOR_NUM && !(param))
//		raise(__FILE__, __LINE__, ENOARGVAL);
//	else if(state == VMP_WAIT_FOR_NUM && !(str_is_num(param)))
//		raise(__FILE__, __LINE__, ENOARGVAL);
//	else if (state == VMP_WAIT_FOR_NUM && str_is_num(param))
//		return (VMP_INITIAL);
//}



