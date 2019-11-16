/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 12:03:27 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/03/25 00:37:33 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		ft_rdupsqrt(int n)
{
	int y;

	y = 2;
	while (y * y <= n)
		y++;
	return (y - 1);
}

int		minbs(char **p)
{
	int z;
	int bs;
	int i;

	z = 0;
	while (p[z])
		z++;
	bs = ft_rdupsqrt(z * 4);
	if (bs == 2 || bs == 3)
	{
		i = 0;
		while (i < z)
		{
			if (ft_strnequ("000", p[i], 3) || ft_strnequ("333", p[i], 3))
				bs = (bs < 4) ? 4 : bs;
			else if (!ft_strnequ("020", p[i], 3))
				bs = (bs < 3) ? 3 : bs;
			else
				bs = (bs < 2) ? 2 : bs;
			i++;
		}
	}
	return (bs);
}

int		*shiftit(int *layer, int bs)
{
	int m;
	int n;

	m = 0;
	while (m < 4)
	{
		if ((m + 1 % bs) == 0)
		{
			n = 0;
			while (n < 4)
			{
				layer[n]++;
				n++;
			}
		}
		m++;
	}
	return (layer);
}

int		*start_pos(char *p, int bs)
{
	int *layer;
	int m;

	m = 0;
	layer = malloc(sizeof(int) * 4);
	layer[m] = 0;
	m++;
	while (m < 4)
	{
		if (p[m - 1] == '3')
			layer[m] = layer[m - 1] + bs + 1;
		else if (p[m - 1] == '2')
			layer[m] = layer[m - 1] + bs;
		else if (p[m - 1] == '1')
			layer[m] = layer[m - 1] + bs - 1;
		else if (p[m - 1] == '0')
			layer[m] = layer[m - 1] + 1;
		m++;
	}
	return (shiftit(layer, bs));
}
