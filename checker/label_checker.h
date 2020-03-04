/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_checker.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:18:04 by ftothmur          #+#    #+#             */
/*   Updated: 2020/03/04 21:05:26 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LABEL_CHECKER_H
# define LABEL_CHECKER_H

#include "../libf/libft.h"
#include "../parser/expr_private.h"
#include "../lexer/token_defines.h"

t_hash_map		*create_hashmap(size_t vertices_num);
int				label_checker_put_to_map_label_word(
				t_hash_map **map_of_label_words,  t_expr *expr);
int				label_checker_put_to_map_label_ptr(
				t_vector *added_label_ptrs, t_expr *expr);
int				label_checker_inclusion_of_maps(t_vector *label_ptr_keys,
				t_hash_map *map_of_label_words);

#endif