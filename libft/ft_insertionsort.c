/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_insertionsort.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 19:59:56 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/03/18 13:07:55 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"

int	*ft_insertionsort(int *arr, size_t arraysize)
{
	unsigned int	i;
	unsigned int	j;
	int				hold;

	i = 1;
	while (i < arraysize)
	{
		hold = arr[i];
		j = i - 1;
		while ((hold < arr[j]) && (j >= 0))
		{
			arr[j + 1] = arr[j];
			j--;
		}
		arr[j + 1] = hold;
		i++;
	}
	return (arr);
}
