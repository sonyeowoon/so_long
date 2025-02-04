/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 17:35:48 by sangseo           #+#    #+#             */
/*   Updated: 2025/02/04 19:51:22 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_dxdy(t_vars *v, int i)
{
	int	dx[4];
	int	dy[4];
	int	nx;
	int	ny;

	dxdy_setup(dx, dy);
	nx = v->x + dx[i];
	ny = v->y + dy[i];
	if (v->map[nx][ny] == '1' || (v->map[nx][ny] == 'E' && v->c_cnt > 0))
		return ;
	else if (v->map[nx][ny] == 'E')
	{
		v->cnt++;
		ft_printf("move count = %d\n", v->cnt);
		game_exit(v);
	}
	else if (v->map[nx][ny] == 'C')
		v->c_cnt--;
	v->map[v->x][v->y] = '0';
	v->map[nx][ny] = 'P';
	v->x = nx;
	v->y = ny;
	v->cnt++;
	ft_printf("move count = %d\n", v->cnt);
}

int	move_player(int keycode, t_vars *v)
{
	int	i;

	if (keycode == 's')
		i = 0;
	else if (keycode == 'w')
		i = 1;
	else if (keycode == 'd')
		i = 2;
	else if (keycode == 'a')
		i = 3;
	else
		return (0);
	move_dxdy(v, i);
	display_map(v);
	return (1);
}
