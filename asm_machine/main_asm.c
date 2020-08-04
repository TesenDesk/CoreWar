/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_asm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cmissy <cmissy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 18:38:52 by cmissy            #+#    #+#             */
/*   Updated: 2020/07/15 18:40:37 by cmissy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "token.h"
#include "analyser.h"
#include "codegen.h"
#include "parser/prvt_expr.h"

char				*read_code(int fd)
{
	char			*buf;
	int				chunk;
	int				cur;
	int				limit;

	cur = 0;
	chunk = 1;
	limit = 1;
	if (fd < 0)
		exit(-1);
	if (!(buf = ft_memalloc(chunk * sizeof(char))))
		exit(-1);
	while (read(fd, buf + cur, chunk))
	{
		cur += chunk;
		if (cur == limit)
		{
			if (!(buf = ft_realloc(buf, limit, limit * 2)))
				exit(-1);
			limit *= 2;
		}
	}
	return (buf);
}



void				ft_del_text(t_vector *v, void (*del)(void**))
{
	int 			i;

	i = 0;
	while (i < v->capacity)
	{
//		del(&(v->items[i]));
		expr_dtor(&((v->items[i])));
		++i;
	}
	ft_memdel((void **)&v->items);
	return ;
}


int					main(int ac, char **av)
{
	t_hash_map		*map;
	t_vector		*text;
	t_analyser		*analyser;
	t_vector		vtr;
	char            *buf;
	int				count;

	count = 1;
	buf = NULL;
	while (count < ac)
	{
		map = ft_hash_map_ctor(HASH_CONST);
		ft_vector_init(&vtr);
		analyser = analyser_singleton_instance(ANALYSER_INSTANTIATE);
		buf = (read_code(open(av[count],
		                      O_RDONLY)));
		text = analyse_text(analyser, &vtr, map, buf);
		generate_code(map, text, av[count]);
		analyser_singleton_instance(ANALYSER_DESTRUCT);
		ft_hash_map_dtor_full(&map, token_destructor);
		ft_vector_free_data(&vtr, label_dtor);
		ft_del_text(text, expr_dtor);
		free(text);
		free(buf);

		++count;
	}
	return (SUCCESS);
}
