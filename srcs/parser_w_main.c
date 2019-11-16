/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_w_main.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 18:50:23 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/03/25 18:01:04 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void		fputstr(char *s)
{
	int i;
	int bs;
	int nlk;

	i = 0;
	nlk = 0;
	while (s[i] != 10)
		i++;
	bs = i;
	i = 0;
	while (nlk < bs && s[i])
	{
		if (s[i] == '\n')
			nlk++;
		write(1, &s[i++], 1);
	}
}

int			invalid_input(char *s)
{
	ft_putendl(s);
	return (1);
}

void		t_list_remove(void *content, size_t content_size)
{
	content_size++;
	free(content);
}

void		freetetr(char ***t)
{
	int i;

	i = 0;
	while ((*t)[i] != NULL)
	{
		free((*t)[i]);
		i++;
	}
	free(*t);
}

int			main(int ac, char **av)
{
	int		fd;
	t_list	*pieces;
	char	**tetriminos;
	char	*solvedboard;

	if (ac != 2)
		return (invalid_input("usage: ./fillit target_file"));
	fd = open(av[1], O_RDONLY);
	pieces = readlines(fd);
	if (!pieces)
		return (invalid_input("error"));
	tetriminos = NULL;
	if (linkcounter(pieces) > 26)
		return (invalid_input("error"));
	lst2strarr(pieces, &tetriminos);
	solvedboard = solve(tetriminos);
	fputstr(solvedboard);
	freetetr(&tetriminos);
	free(solvedboard);
	close(fd);
	return (1);
}
