/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/03 13:53:59 by sangseo           #+#    #+#             */
/*   Updated: 2025/02/03 21:51:20 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_rectangle(char **m)
{
	int	width;
	int	i;

	width = ft_strlen(*m);
	i = 1;
	while (m[i])
	{
		if (width != ft_strlen(m[i]))
			mfree_perror("Error: Not rectangle map\n", m);
		i++;
	}
    if (width < 4)
        mfree_perror("Error: Not enough column\n", m);
}

void	check_walls(char **m)
{
	int	i;
	int	width;
	int	j;

	i = 0;
	while ((*m)[i] && (*m)[i] != '\n')
	{
		if ((*m)[i++] != '1')
			mfree_perror("Error: Invalid walls\n", m);
	}
	width = ft_strlen(*m) - 2;
	i = 1;
	while (m[i])
	{
		if (m[i][0] != '1' || m[i][width] != '1')
			mfree_perror("Error: Invalid walls\n", m);
		i++;
	}
	i--;
	j = 0;
	while (m[i][j] && m[i][j] != '\n')
	{
		if (m[i][j++] != '1')
			mfree_perror("Error: Invalid walls\n", m);
	}
}
