/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 16:00:07 by sangseo           #+#    #+#             */
/*   Updated: 2025/02/03 21:52:47 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dxdy_setup(int *dx, int *dy)
{
	dx[0] = 1;
	dx[1] = -1;
	dx[2] = 0;
	dx[3] = 0;
	dy[0] = 0;
	dy[1] = 0;
	dy[2] = 1;
	dy[3] = -1;
}

void    dfs(char **map, int *flg, int x, int y)
{
	int	dx[4];
	int	dy[4];
	int	i;

	if (map[x][y] == 'E')
		*flg = 1;
	if (map[x][y] == '1' || map[x][y] == 'E' || map[x][y] == 'V')
		return ;
	dxdy_setup(dx, dy);
	map[x][y] = 'V';
	i = 0;
	while (i < 4)
	{
		dfs(map, flg, x + dx[i], y + dy[i]);
		i++;
	}
}

void	get_player(char **m, int *x, int *y)
{
	int	i;
	int	j;

	i = 1;
	while (m[i])
	{
		j = 1;
		while (m[i][j] && m[i][j] != '\n')
		{
			if (m[i][j] == 'P')
			{
				*x = i;
				*y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

void	validate_map(char **m)
{
	int	x;
	int	y;
	int	flg[1];
	int	i;
	int	j;

	get_player(m, &x, &y);
	*flg = 0;
	dfs(m, flg, x, y);
	i = 1;
	while (m[i])
	{
		j = 1;
		while (m[i][j] && m[i][j] != '\n')
		{
			if (m[i][j] == 'C')
				mfree_perror("Error: Invalid collectible location\n", m);
			j++;
		}
		i++;
	}
	if (*flg != 1)
		mfree_perror("Error: Incorrect exit location\n", m);
}
