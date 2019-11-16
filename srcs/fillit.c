/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/17 01:18:00 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/03/25 17:59:35 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fillit.h"

int		**fit_to_board(char **p, int bs)
{
	int piececount;
	int i;
	int **x;

	piececount = 0;
	while (p[piececount])
		piececount++;
	x = malloc(sizeof(int *) * (piececount + 1));
	i = 0;
	while (i < piececount)
	{
		x[i] = start_pos(p[i], bs);
		i++;
	}
	x[i] = NULL;
	return (x);
}

void	tet_scoot(int *p, int bs)
{
	int i;

	i = 0;
	while (i < 4)
	{
		p[i]++;
		i++;
	}
	while ((p[0] + 1) % (bs + 1) == 0 || (p[1] + 1) % (bs + 1) == 0 ||
			(p[2] + 1) % (bs + 1) == 0 || (p[3] + 1) % (bs + 1) == 0)
	{
		i = 0;
		while (i < 4)
		{
			p[i]++;
			i++;
		}
	}
}

int		puzzlemaster(int **pieces, char *board, int bs, int f)
{
	int i;

	if (pieces[f] == NULL)
		return (1);
	while (pieces[f][3] < (bs + 1) * bs)
	{
		if (board[(pieces[f][0])] == '.' && board[(pieces[f][1])] == '.' &&
				board[(pieces[f][2])] == '.' && board[(pieces[f][3])] == '.')
		{
			i = 0;
			while (i < 4)
				board[(pieces[f][i++])] = 'A' + f;
			if (puzzlemaster(pieces, board, bs, f + 1))
				return (1);
		}
		i = -1;
		while (board[++i])
			if (board[i] == 'A' + f)
				board[i] = '.';
		tet_scoot(pieces[f], bs);
	}
	i = 3;
	while (i > -1)
		pieces[f][i--] -= pieces[f][0];
	return (0);
}

int		**reboarding(int *bs, char **board, int ***pieces, char **p)
{
	(*bs)++;
	freeboard(board, pieces);
	return (fit_to_board(p, *bs));
}

char	*solve(char **p)
{
	int		boardsize;
	char	*board;
	int		**pieces;
	int		i;

	boardsize = minbs(p);
	pieces = fit_to_board(p, boardsize);
	while (1)
	{
		board = malloc(sizeof(char) * (boardsize + 1) * boardsize);
		ft_memset(board, '.', (boardsize + 1) * boardsize);
		i = -1;
		while (++i < boardsize * (boardsize + 1))
			if ((i + 1) % (boardsize + 1) == 0)
				board[i] = '\n';
		if (puzzlemaster(pieces, board, boardsize, 0))
		{
			freeintpieces(&pieces);
			return (board);
		}
		else
			pieces = reboarding(&boardsize, &board, &pieces, p);
	}
	return (NULL);
}
