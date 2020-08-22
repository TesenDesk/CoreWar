/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prvt_analyser_xtor.h                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 19:32:04 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/14 19:33:46 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRVT_ANALYSER_XTOR_H
# define PRVT_ANALYSER_XTOR_H

# include "prvt_analyser.h"


t_analyser		*prvt_analyser_ctor(t_analyser **analyser);

void			prvt_analyser_dtor(t_analyser **analyser);

#endif
