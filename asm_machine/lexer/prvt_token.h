/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_token.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 21:53:04 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/14 21:53:04 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRVT_TOKEN_H
# define PRVT_TOKEN_H

# include "token.h"

typedef struct		s_token
{
	int				type;
	void			*val;
	void			*token_ptr[2];
	int				(*get_type)(struct s_token *token);
	void			*(*get_begin)(struct s_token *token);
	void			*(*get_val)(struct s_token *token);
}					t_token;

#endif
