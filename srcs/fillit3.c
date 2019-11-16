/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit3.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 18:08:36 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/03/25 18:08:41 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

void	freeboard(char **board, int ***pieces)
{
	int i;

	i = 0;
	free(*board);
	while ((*pieces)[i])
		free((*pieces)[i++]);
	free(*pieces);
}

void	freeintpieces(int ***pieces)
{
	int i;

	i = 0;
	while ((*pieces)[i] != NULL)
		free((*pieces)[i++]);
	free(*pieces);
}
