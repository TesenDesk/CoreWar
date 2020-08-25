/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_asm.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ftothmur <ftothmur@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 18:38:52 by cmissy            #+#    #+#             */
/*   Updated: 2020/08/16 14:49:34 by ftothmur         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "main_asm.h"
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

/*
**	while (i < v->total)
**	{
**		del(&(v->items[i]));
**		expr_dtor(&((v->items[i])));
**		++i;
**	}
*/

void				ft_del_text(t_vector *v, void (*del)(void**))
{
	int				i;

	i = 0;
	while (i < v->total)
	{
		expr_dtor(&((v->items[i])));
		++i;
	}
	ft_memdel((void **)&v->items);
	v->items = NULL;
	return ;
}

/*
**	while (count < ac)
**	{
**		map = ft_hash_map_ctor(HASH_CONST);
**		ft_vector_init(&vtr);
**		analyser = analyser_singleton_instance(ANALYSER_INSTANTIATE);
**		buf = (read_code(open(av[count],
**		                      O_RDONLY)));
**		text = analyse_text(analyser, &vtr, map, buf);
**		generate_code(map, text, av[count]);
**		analyser_singleton_instance(ANALYSER_DESTRUCT);
**		ft_hash_map_dtor(&map);
**		ft_hash_map_dtor_full(&map, token_destructor);
**		ft_vector_free_data(&vtr, label_dtor);
**		ft_del_text(text, expr_dtor);
**		free(text);
**		free(buf);
**		++count;
**	}
*/

static void			free_resourses(t_hash_map **map, t_vector *vtr,
		t_vector **text, char **buf)
{
	ft_hash_map_dtor(map);
	ft_vector_free_data(vtr, label_dtor);
	ft_del_text(*text, expr_dtor);
	ft_memdel((void **)text);
	ft_memdel((void **)buf);
	return ;
}

int					main(int ac, char **av)
{
    t_main_asm		main_asm;

	main_asm.count = 1;
	main_asm.buf = NULL;
	while (main_asm.count < ac)
	{
		main_asm.map = ft_hash_map_ctor(HASH_CONST);
		ft_vector_init(&main_asm.vtr);
        write(1,"111\n", 5);

		main_asm.analyser = analyser_singleton_instance(ANALYSER_INSTANTIATE);
        write(1,"222\n", 5);
		main_asm.buf = (read_code(open(av[main_asm.count], O_RDONLY)));
		main_asm.text = analyse_text(main_asm.analyser, &main_asm.vtr,
				main_asm.map, main_asm.buf);
        write(1,"333\n", 5);
		generate_code(main_asm.map, main_asm.text, av[main_asm.count]);
        write(1,"444\n", 5);
		analyser_singleton_instance(ANALYSER_DESTRUCT);
		free_resourses(&main_asm.map, &main_asm.vtr, &main_asm.text,
				&main_asm.buf);
		++main_asm.count;
	}
	return (SUCCESS);
}
