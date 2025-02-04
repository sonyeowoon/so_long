/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/01 11:55:26 by sangseo           #+#    #+#             */
/*   Updated: 2025/02/04 19:32:44 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	cnt_c(char **m)
{
	int	i;
	int	j;
	int	cnt;

	cnt = 0;
	i = 1;
	while (m[i])
	{
		j = 1;
		while (m[i][j] && m[i][j] != '\n')
		{
			if (m[i][j] == 'C')
				cnt++;
			j++;
		}
		i++;
	}
	return (cnt);
}

static void	setup_vars(t_vars *v, char *path)
{
	int	img_size;

	v->map = init_map(path);
	get_player(v->map, &(v->x), &(v->y));
	v->c_cnt = cnt_c(v->map);
	v->cnt = 0;
	v->width = ft_strlen(*(v->map)) - 1;
	v->height = cnt_line(path);
	v->img_pixel = 64;
	v->mlx_ptr = mlx_init();
	v->bg_img = mlx_xpm_file_to_image(v->mlx_ptr, "textures/0.xpm", \
			&img_size, &img_size);
	v->wall_img = mlx_xpm_file_to_image(v->mlx_ptr, "textures/1.xpm", \
			&img_size, &img_size);
	v->collect_img = mlx_xpm_file_to_image(v->mlx_ptr, "textures/C.xpm", \
			&img_size, &img_size);
	v->exit_img = mlx_xpm_file_to_image(v->mlx_ptr, "textures/E.xpm", \
			&img_size, &img_size);
	v->player_img = mlx_xpm_file_to_image(v->mlx_ptr, "textures/P.xpm", \
			&img_size, &img_size);
}

int	main(int ac, char **av)
{
	t_vars	v;

	if (ac != 2 || av[1] == 0)
		print_error("Error: Bad arguments\n");
	check_map(av[1]);
	setup_vars(&v, av[1]);
	v.win_ptr = mlx_new_window(v.mlx_ptr, v.width * v.img_pixel, \
			v.height * v.img_pixel, "sangseo so_long");
	display_map(&v);
	mlx_hook(v.win_ptr, KeyPress, KeyPressMask, &move_player, &v);
	mlx_hook(v.win_ptr, DestroyNotify, KeyPressMask, &game_exit, &v);
	mlx_loop(v.mlx_ptr);
}
