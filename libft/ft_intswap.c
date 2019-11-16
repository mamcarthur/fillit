/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_intswap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmcarthu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/18 14:44:29 by mmcarthu          #+#    #+#             */
/*   Updated: 2019/02/18 14:45:07 by mmcarthu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_intswap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}
