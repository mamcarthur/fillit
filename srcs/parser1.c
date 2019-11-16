/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 18:47:18 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/03/25 00:39:02 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void		ft_lstappend(t_list *pieces, t_list *last)
{
	t_list *tmp;

	tmp = pieces;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = last;
}

int			correctchar(char *tet)
{
	int i;

	i = 0;
	while (tet[i])
	{
		if (tet[i] != '.' && tet[i] != '#' && tet[i] != '\n')
			return (0);
		i++;
	}
	return (1);
}

int			correctlengths(char *tet)
{
	int i;
	int j;

	if (ft_strlen(tet) != 20 && ft_strlen(tet) != 21)
		return (0);
	i = 0;
	while (i < 20)
	{
		j = 0;
		while (tet[i] && tet[i] != '\n')
		{
			i++;
			j++;
		}
		if (j != 4)
			return (0);
		i++;
	}
	if (tet[i] && tet[i] != '\n')
		return (0);
	return (1);
}

int			fourtiles(char *tet)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (tet[i])
	{
		if (tet[i] == '#')
			j++;
		i++;
	}
	if (j == 4)
		return (1);
	return (0);
}

int			checkconnections(char *tet)
{
	int i;
	int len;
	int connects;

	len = ft_strlen(tet);
	connects = 0;
	i = 0;
	while (tet[i])
	{
		if (tet[i] == '#')
		{
			connects += ((i + 5 < len) && (tet[i + 5] == '#') ? 1 : 0);
			connects += ((i - 5 >= 0) && (tet[i - 5] == '#') ? 1 : 0);
			connects += ((i + 1 < len) && (tet[i + 1] == '#') ? 1 : 0);
			connects += ((i - 1 >= 0) && (tet[i - 1] == '#') ? 1 : 0);
		}
		i++;
	}
	if (connects < 6)
		return (0);
	return (1);
}
