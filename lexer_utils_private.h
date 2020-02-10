/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lexer_utils_private.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 18:09:16 by ftothmur          #+#    #+#             */
/*   Updated: 2020/02/10 19:01:17 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEXER_UTILS_PRIVATE_H
# define LEXER_UTILS_PRIVATE_H

int				lexer_utils_is_line_feed(char c);
int				lexer_utils_is_of_label_chars(char c);
int				lexer_utils_is_label_char(char c);

#endif
