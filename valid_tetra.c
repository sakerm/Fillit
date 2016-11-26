/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_tetra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeress <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:08:53 by lomeress          #+#    #+#             */
/*   Updated: 2016/11/26 18:16:00 by lomeress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int		ft_tetra(char **tetra)
{
	int x;
	int y;
	int res;

	x = 0;
	y = 0;
	res = 0;
	while (tetra[y][x])
	{
		if (tetra[y][x] == '#' && tetra[y][x + 1] != '#' &&
				tetra[y][x - 1] != '#' && tetra[y + 1][x] != '#' &&
				tetra[y - 1][x] != '#')
			return (0);
		if (x == 3)
		{
			x = 0;
			y++;
		}
		else
			x++;
	}
	return (1);
}

int				valid_tetra(char **tetra)
{
	int a;
	int i;

	a = 0;
	i = 0;
	a = check_case(tetra);
	if (a == 1)
		a += ft_tetra(tetra);
	return (a == 2 ? 1 : 0);
}
