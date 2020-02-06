/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_private.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:44:55 by ftothmur          #+#    #+#             */
/*   Updated: 2020/02/06 17:27:27 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_PRIVATE_H
#define TOKEN_PRIVATE_H


typedef struct 	    s_token
{
    int             token_type;
    void		    *tkn_begin;
    size_t		    tkn_len;
    void            (*form_token)(t_token *token, char **text);
}				    t_token;



void                (*fptr_init_term_switch)(t_token *token, char **text, void (*fptr)(t_token *token,char**)[4]);
void                tkn_get_term_init_state(t_token *token, char**text);

/*
 * 1lvl token substates
 */

void                (*fptr_1sub_term_switch)(t_token *token, char **text,(void) (*fptr)(t_token *token, char**)[2] );
void                tkn_get_term_comment_unit(t_token *token, char **text);
void                tkn_get_term_line_feed_unit(t_token *token, char **text);
void                tkn_get_term_champion_unit(t_token *token, char **text);
void                tkn_get_term_code_unit(t_token *token, char **text);

/*
 * code_state_terms
 */

void                (*fptr_code_state_term_switch)(t_token *token, char **text, (void) (*fptr)(char**)[2]);
void                tkn_get_term_op_name_unit(t_token *token, char **text);
void                tkn_get_term_label_word_unit(t_token *token, char **text);

/*
 * op_name_terms
 */

void                tkn_get_term_opx_name(t_token *token, char **text);
void                tkn_get_label_word_unit(t_token *token, char **text);


int					is_white_space(char c);
int					is_line_feed(char c);
int					is_of_label_chars(char c);

#endif