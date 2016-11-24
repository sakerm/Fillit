/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid_tetra.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lomeress <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 11:08:53 by lomeress          #+#    #+#             */
/*   Updated: 2016/11/24 09:55:07 by lomeress         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

static int		check_case(char cs[4][5])
{
	int y;
	int x;
	int error;
	int ht;

	y = 0;
	x = 0;
	error = 0;
	ht = 0;
	while (cs[y][x])
	{
		if (cs[y][x] == '#')
			ht++;
		if (x == 3)
		{
			y++;
			x = 0;
		}
		else if (x < 3)
			x++;
		else if ((cs[y][x] != '#' && cs[y][x] != '.') || (x > 3) || (y > 3))
			error++;
	}
	return (error == 0 && ht == 4 ? 1 : 0);
}

static int		ft_tetra(char tetra[4][5])
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

int				valid_tetra(char tetra[4][5])
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

int				main()
{
	char tmp[4][5] = {
		{'.', '.', '.', '.', '\n'},
		{'.', '#', '#', '.', '\n'},
		{'.', '.', '#', '.', '\n'},
		{'.', '.', '#', '.', '\0'},
	};
	int i = valid_tetra(tmp);
	printf("%d", i);
	return (0);
}
