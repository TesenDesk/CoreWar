/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils_private.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:09:16 by ftothmur          #+#    #+#             */
/*   Updated: 2020/03/06 19:57:38 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_UTILS_PRIVATE_H
# define LEXER_UTILS_PRIVATE_H

int				lexer_utils_is_line_feed(char c);
int				lexer_utils_is_of_label_chars(char c);
int				lexer_utils_is_label_char(char c);
int				lexer_utils_is_whitespace(char c);
int				lexer_utils_is_quotation_mark(char c);
int				lexer_utils_is_eof(char c);

void			lexer_utils_trim_whitespace(const char **text);
void			lexer_utils_trim_not_eof_not_line_feed_not_quotatuion_mark(
					const char **text);

#endif
