/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 03:02:31 by sangseo           #+#    #+#             */
/*   Updated: 2025/02/04 20:38:54 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	cnt_line(char *file_name)
{
	int		fd;
	int		i;
	char	*line;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		print_error("Error: File open failure\n");
	line = get_next_line(fd);
	if (!line)
		return (0);
	i = 0;
	while (line && *line && *line != '\n')
	{
		i++;
		free(line);
		line = get_next_line(fd);
	}
	free(line);
	close(fd);
	return (i);
}

void	free_map(char **c_map)
{
	int	i;

	i = 0;
	while (c_map[i])
		free(c_map[i++]);
	free(c_map);
}

static void	init_map_setup(int *cnt, int *fd, char *file_name)
{
	*cnt = cnt_line(file_name);
	if (*cnt < 3)
		print_error("Error: Invalid row\n");
	*fd = open(file_name, O_RDONLY);
	if (*fd == -1)
		print_error("Error: File open failure\n");
}

char	**init_map(char *file_name)
{
	char	*line;
	char	**c_map;
	int		cnt;
	int		fd;
	int		i;

	init_map_setup(&cnt, &fd, file_name);
	c_map = (char **)malloc(sizeof(char *) * (cnt + 1));
	if (!c_map)
		return (0);
	line = get_next_line(fd);
	if (!line)
	{
		free(c_map);
		return (0);
	}
	i = 0;
	while (line && *line)
	{
		c_map[i++] = line;
		line = get_next_line(fd);
	}
	c_map[i] = 0;
	close(fd);
	return (c_map);
}
