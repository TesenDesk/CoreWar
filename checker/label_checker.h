/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   label_checker.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 16:18:04 by ftothmur          #+#    #+#             */
/*   Updated: 2020/02/28 16:32:18 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LABEL_CHECKER_H
# define LABEL_CHECKER_H

#include "libft.h"

int				label_checker_put_to_map_label_word(
				t_hash_map **map_of_label_words, char const **text,
				size_t label_len);
int				label_checker_put_to_map_label_ptr(
				t_hash_map **map_of_label_ptrs, char const **text,
				size_t label_len);
int				label_checker_inclusion_of_maps(t_hash_map *map_of_label_ptrs,
				t_hash_map *map_of_label_words);

#endif