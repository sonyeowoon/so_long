/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 22:05:01 by sangseo           #+#    #+#             */
/*   Updated: 2025/02/04 09:31:18 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	check_filename(char *file_name)
{
	size_t	len;

	len = ft_strlen(file_name);
	if (len < 5)
		return (0);
	if (file_name[len - 4] != '.' || file_name[len - 3] != 'b' || \
			file_name[len - 2] != 'e' || file_name[len - 1] != 'r')
		return (0);
	return (1);
}

static void	init_component_cnt(int *c, int *e, int *p)
{
	*c = 0;
	*e = 0;
	*p = 0;
}

static void	component_cnt(char **m)
{
	int	i;
	int	j;
	int	c;
	int	e;
	int	p;

	init_component_cnt(&c, &e, &p);
	i = 0;
	while (m[i])
	{
		j = 0;
		while (m[i][j])
		{
			if (m[i][j] == 'C')
				c++;
			if (m[i][j] == 'E')
				e++;
			if (m[i][j] == 'P')
				p++;
			j++;
		}
		i++;
	}
	if (c < 1 || e != 1 || p != 1)
		mfree_perror("Error: Bad component cnt\n", m);
}

static void	check_component(char **c_map)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	while (c_map[i])
	{
		j = 0;
		while (c_map[i][j])
		{
			c = c_map[i][j];
			if (c != '0' && c != '1' && c != 'C' && \
				c != 'E' && c != 'P' && c != '\n')
				mfree_perror("Error: Invalid component\n", c_map);
			j++;
		}
		i++;
	}
	component_cnt(c_map);
}

void	check_map(char *file_name)
{
	char	**c_map;

	if (!check_filename(file_name))
		print_error("Error: Invalid file name\n");
	c_map = init_map(file_name);
	if (!c_map)
		print_error("Error: Map creation failed\n");
	check_component(c_map);
	check_rectangle(c_map);
	check_walls(c_map);
	validate_map(c_map);
	free_map(c_map);
}
