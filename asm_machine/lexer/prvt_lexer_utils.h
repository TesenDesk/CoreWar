/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_lexer_utils.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:09:16 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/23 14:40:23 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRVT_LEXER_UTILS_H
# define PRVT_LEXER_UTILS_H

# include "lexer.h"

int				lexer_utils_is_line_feed(char c);
int				lexer_utils_is_of_label_chars(char c);
int				lexer_utils_is_label_char(char c);
int				lexer_utils_is_whitespace(char c);
int				lexer_utils_is_quotation_mark(char c);
int				lexer_utils_is_eof(char c);

void			lexer_utils_trim_whitespace(const char **text);
long long       lexer_utils_trim_not_eof_not_line_feed_not_quotatuion_mark(
					const char **text);

#endif
