/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smbaabu <smbaabu@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/09 01:17:55 by smbaabu           #+#    #+#             */
/*   Updated: 2019/03/25 18:55:44 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/includes/libft.h"

void	ft_lstappend(t_list *pieces, t_list *last);
int		correctchar(char *tet);
int		correctlengths(char *tet);
int		fourtiles(char *tet);
int		checkconnections(char *tet);

int		checkvalid(char *tet);
void	t_list_remove(void *content, size_t content_size);
t_list	*readlines(int fd);
int		linkcounter(t_list *p);
void	lst2strarr(t_list *p, char ***pieces);

int		invalid_input(char *s);
void	t_list_remove(void *content, size_t content_size);

int		ft_rdupsqrt(int n);
int		minbs(char **p);
int		*shiftit(int *layer, int bs);
int		*start_pos(char *p, int bs);
int		**fit_to_board(char **p, int bs);
void	tet_scoot(int *p, int bs);
int		puzzlemaster(int **pieces, char *board, int bs, int f);
char	*solve(char **p);
void	freeboard(char **board, int ***pieces);
int		**reboarding(int *bs, char **board, int ***pieces, char **p);

void	freeboard(char **board, int ***pieces);
void	freeintpieces(int ***pieces);
void	freetetr(char ***t);

#endif
