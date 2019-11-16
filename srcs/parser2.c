/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 18:49:23 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/03/25 17:58:43 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int			checkvalid(char *tet)
{
	if (!correctchar(tet))
		return (0);
	if (!correctlengths(tet))
		return (0);
	if (!fourtiles(tet))
		return (0);
	if (!checkconnections(tet))
		return (0);
	return (1);
}

char		*convert_to_int(char *s)
{
	int		i;
	int		j;
	int		k;
	char	*code;

	i = 0;
	k = 0;
	code = malloc((sizeof(char) * 5));
	while (s[i] != '#')
		i++;
	j = i++;
	while (i < 19)
	{
		while (i < 19 && s[i] != '#')
			i++;
		if (i - j == 1)
			code[k++] = '0';
		else if (i - j == 3)
			code[k++] = '1';
		else
			code[k++] = (i - j == 4) ? '2' : '3';
		j = i++;
	}
	code[k] = '\0';
	return (code);
}

t_list		*readlines(int fd)
{
	int		r;
	char	tet[22];
	t_list	*pieces;
	char	*confree;

	pieces = NULL;
	while ((r = read(fd, &tet, 21)) != 0)
	{
		tet[r] = '\0';
		if (!checkvalid(tet))
		{
			if (pieces != NULL)
				ft_lstdel(&pieces, &t_list_remove);
			pieces = NULL;
			return (pieces);
		}
		confree = convert_to_int(tet);
		if (!pieces)
			pieces = ft_lstnew(confree, r);
		else
			ft_lstappend(pieces, ft_lstnew(confree, r));
		free(confree);
	}
	return (pieces);
}

int			linkcounter(t_list *p)
{
	int i;

	i = 1;
	while (p->next)
	{
		p = p->next;
		i++;
	}
	return (i);
}

void		lst2strarr(t_list *p, char ***pieces)
{
	int		i;
	t_list	*q;

	*pieces = malloc(sizeof(char *) * (linkcounter(p) + 1));
	i = 0;
	while (p)
	{
		(*pieces)[i] = p->content;
		q = p;
		p = p->next;
		free(q);
		i++;
	}
	(*pieces)[i] = NULL;
}
