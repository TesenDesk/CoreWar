/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_analyser_xtor.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 19:32:04 by cmissy            #+#    #+#             */
/*   Updated: 2020/08/23 14:54:43 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRVT_ANALYSER_XTOR_H
# define PRVT_ANALYSER_XTOR_H

# include "prvt_analyser.h"

t_analyser		*prvt_analyser_ctor(t_analyser **analyser);
void			prvt_analyser_dtor(t_analyser **analyser);

#endif
