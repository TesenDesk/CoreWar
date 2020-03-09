/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   token_private.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/05 17:44:55 by ftothmur          #+#    #+#             */
<<<<<<< HEAD
/*   Updated: 2020/03/05 20:34:00 by cmissy           ###   ########.fr       */
=======
/*   Updated: 2020/03/05 21:22:19 by ftothmur         ###   ########.fr       */
>>>>>>> 09a844fd5c990e262fc840d5c787b248f88ce6d1
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKEN_PRIVATE_H
#define TOKEN_PRIVATE_H
#include <stdio.h>
//#define UNDEF_TOKEN -1


typedef struct		s_token
{
<<<<<<< HEAD
    int             type;
    void			*val; // ?????????
    void		    *token_ptr[2];
    int             (*get_type)(t_token  *token);
    void*           (*get_begin)(t_token *token);
    void*			(*get_val)(t_token *token);
}				    t_token;
=======
	int				type;
	void			*val;
	void			*token_ptr[2];
	int				(*get_type)(t_token  *token);
	void			*(*get_begin)(t_token *token);
	void			*(*get_val)(t_token *token);
}					t_token;
>>>>>>> 09a844fd5c990e262fc840d5c787b248f88ce6d1


#endif