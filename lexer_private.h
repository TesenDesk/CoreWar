/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_private.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:46:31 by ftothmur          #+#    #+#             */
/*   Updated: 2020/02/05 17:48:57 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_PRIVATE_H
#define LEXER_PRIVATE_H 

/*
 * STATE MACHINE STATEs
 */

#define comment_unit_st 0
#define line_feed_unit_st 1

/*
 * champ_unit_states
*/

#define name_cmd_st 3
#define ch_name st 4
#define comm_cmd_st 5
#define ch_comm_st 6

/*
 * code_unit_states
*/
#define opx_name_st 7

/*
 * augment_unit_substates
 */

#define t_reg_st        8
#define t_ind_st        9
#define t_dir_int_st    10
#define t_dir_lab_st    11
#defien arg_break_st    13

typedef struct 	    s_lexer
{
    int             state;
    t_token         (*fptr_lexer_form_token(t_lexer *lexer, char **text));
}				    t_lexer;


#endif