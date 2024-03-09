/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:14:53 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/03/08 20:54:27 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*map_get_fd(int fd);
int		map_validate(char *map, int *map_width, int *map_height);
int		**map_to_points(char *map);
int		**map_to_edges(char *map);

char	*map_get_fd(int fd)
{
	char	*line;
	char	*res;

	line = ft_getline_fd(fd);
	res = NULL;
	while (line)
	{
		ft_strappend(&res, line);
		free(line);
		line = ft_getline_fd(fd);
	}
	return (res);
}

int	map_validate(char *map, int *map_width, int *map_height)
{
	char	**rows;
	int		i;

	*map_height = ft_wordcount(map, "\n");
	if (*map_height < 2)
		return (0);
	rows = ft_split(map, "\n");
	if (!rows)
		return (0);
	*map_width = ft_wordcount(rows[0], " ");
	if (*map_width < 2)
		return (ft_freesplit(rows), 0);
	i = 0;
	while (rows[++i])
		if (ft_wordcount(rows[i], " ") != *map_width)
			return (ft_freesplit(rows), 0);
	ft_freesplit(rows);
	return (1);
}

int	**map_to_points(char *map)
{
	int		**res;
	char	**row;
	char	**column;
	int		i;
	int		j;

	res = NULL;
	row = ft_split(map, "\n");
	i = -1;
	while (row[++i])
	{
		column = ft_split(row[i], " ");
		j = -1;
		while (column[++j])
			res = points_append(res, (int *[]){
					points_new(j, i, ft_atoi(column[j])), NULL});
		ft_freesplit(column);
	}
	ft_freesplit(row);
	return (res);
}

int	**map_to_edges(char *map)
{
	int		**res;
	int		map_width;
	int		map_height;
	int		i;

	if (!map_validate(map, &map_width, &map_height))
		return (NULL);
	res = NULL;
	i = -1;
	while (++i < map_height * map_width)
	{
		if ((i + 1) % map_width != 0)
			res = points_append(res, (int *[]){points_new(i, i + 1, 0), NULL});
		if ((i + map_width) < map_height * map_width)
			res = points_append(res,
					(int *[]){points_new(i, i + map_width, 0), NULL});
	}
	return (res);
}
