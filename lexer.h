/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:35:16 by ftothmur          #+#    #+#             */
/*   Updated: 2020/02/03 18:47:48 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_H
#define LEXER_H

#define COMMENT_CHAR			'#'
#define ALT_COMMENT_CHAR		';'

#define REGISTER_CHAR           'r'
#define LABEL_CHAR				':'
#define DIRECT_CHAR				'%'

#define SEPARATOR_CHAR			','

#define LABEL_CHARS				"abcdefghijklmnopqrstuvwxyz_0123456789"
#define NAME_CMD_STRING			".name"
#define COMMENT_CMD_STRING		".comment"
#define WHITE_SPACE				" \t"

struct s_lexer;
typedef struct s_lexer          t_lexer;


void			lexer_ctor(t_lexer *lexer);
void			lexer_dtor(t_lexer *lexer);

#endif