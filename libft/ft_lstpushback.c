/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpushback.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 18:57:06 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/15 18:57:19 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_lstpushback(t_list **head, t_list *new)
{
	t_list		*tmp;

	if (head && new)
	{
		if (*head == NULL)
		{
			*head = new;
		}
		else
		{
			tmp = *head;
			while (tmp->next != NULL)
				tmp = tmp->next;
			tmp->next = new;
		}
	}
	return ;
}
