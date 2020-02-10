/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:35:16 by ftothmur          #+#    #+#             */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
#define LEXER_H

#include "token.h"
#include "token_defines.h"



//enum							e_words
//{
//	UNDEFINED_TOKEN = -1,
//	EOF_WORD,
//	LINE_FEED,
//	CH_NAME,
//	CH_COMMENT,
//	LABEL_WORD,
//	OP_NAME,
//	T_REG,
//	T_IND,
//	T_DIR
//};

/*
** The attribute structure with no disclosed attribute.
*/
//struct                          s_lexer;
typedef struct s_lexer          t_lexer;

/*
** Constructor and destructor functions.
*/

void             lexer_constructor(t_lexer **lexer);
void             lexer_destructor(t_lexer **lexer);

/*
** Public behavioral functions.
*/

t_token*            lexer_form_token(t_lexer *lexer, char const **text);


#endif