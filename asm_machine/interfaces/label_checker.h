/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_checker.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:18:04 by ftothmur          #+#    #+#             */
/*   Updated: 2020/08/23 14:54:15 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LABEL_CHECKER_H
# define LABEL_CHECKER_H

# include "ft_printf.h"
# include "token.h"
# include "expr.h"

int				label_checker_put_to_map_label_word(
					t_hash_map **map_of_label_words, t_token *token);
int				label_checker_put_to_map_label_ptr(
					t_vector *added_label_ptrs, t_token *token);
int				label_checker_inclusion_of_maps(t_vector *label_ptr_keys,
					t_hash_map *map_of_label_words);

#endif
