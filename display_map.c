/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 15:48:29 by sangseo           #+#    #+#             */
/*   Updated: 2025/02/04 16:32:18 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	draw_map(t_vars *v, char map_c, int x, int y)
{
	mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->bg_img, x, y);
	if (map_c == '1')
		mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->wall_img, x, y);
	else if (map_c == 'C')
		mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->collect_img, x, y);
	else if (map_c == 'E')
		mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->exit_img, x, y);
	else if (map_c == 'P')
		mlx_put_image_to_window(v->mlx_ptr, v->win_ptr, v->player_img, x, y);
}

void	display_map(t_vars *v)
{
	int	i;
	int	j;

	mlx_clear_window(v->mlx_ptr, v->win_ptr);
	i = 0;
	while (v->map[i])
	{
		j = 0;
		while (v->map[i][j] && v->map[i][j] != '\n')
		{
			draw_map(v, v->map[i][j], j * v->img_pixel, i * v->img_pixel);
			j++;
		}
		i++;
	}
}
