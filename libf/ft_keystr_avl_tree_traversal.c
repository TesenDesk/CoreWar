/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_keystr_avl_tree_traversal.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/26 19:33:20 by cmissy            #+#    #+#             */
/*   Updated: 2020/03/01 17:09:25 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_keystr_avl_tree_traversal(t_keystr_avl_t *root,
			void f(t_keystr_avl_t *vertex))
{
	if (root != NULL)
	{
		ft_keystr_avl_tree_traversal(root->left, f);
		ft_keystr_avl_tree_traversal(root->right, f);
	}
	if (f && root)
		f(root);
}