/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sangseo <sangseo@student.42gyeongsan.kr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/02 20:40:34 by sangseo           #+#    #+#             */
/*   Updated: 2025/02/03 21:47:04 by sangseo          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <X11/keysym.h>
# include <X11/X.h>

void	print_error(char *str);
void	check_map(char *file_name);
int	cnt_line(char *file_name);
char	**init_map(char *file_name);
char    *get_next_line(int fd);
size_t  ft_strlen(const char *s);
char    *ft_strdup(const char *s);
char    *ft_strjoin(char const *s1, char const *s2);
char    *ft_allocfree(char *s1, char *s2, int n);
void	free_map(char **c_map);
void	mfree_perror(char *str, char **c_map);
void	check_rectangle(char **m);
void	check_walls(char **m);
void    dfs(char **map, int *flg, int x, int y);
void	validate_map(char **m);

#endif