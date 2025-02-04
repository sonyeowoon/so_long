/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_exit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/04 19:05:59 by sangseo           #+#    #+#             */
/*   Updated: 2025/02/04 19:26:23 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	game_exit(t_vars *v)
{
	mlx_destroy_image(v->mlx_ptr, v->bg_img);
	mlx_destroy_image(v->mlx_ptr, v->wall_img);
	mlx_destroy_image(v->mlx_ptr, v->collect_img);
	mlx_destroy_image(v->mlx_ptr, v->exit_img);
	mlx_destroy_image(v->mlx_ptr, v->player_img);
	mlx_destroy_window(v->mlx_ptr, v->win_ptr);
	mlx_destroy_display(v->mlx_ptr);
	free(v->mlx_ptr);
	free_map(v->map);
	exit(1);
}
