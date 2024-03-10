/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:14:53 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/03/09 14:05:09 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*map_get_fd(int fd);
int		map_validate(t_model *model);
int		**map_to_points(char *map);
int		**map_to_edges(t_model *model);

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

int	map_validate(t_model *model)
{
	char	*map;
	char	*row;

	map = ft_strdup(model->map);
	model->map_height = ft_wordcount(map, "\n");
	row = ft_strtok(map, "\n");
	model->map_width = ft_wordcount(row, " ");
	while (row)
	{
		if (model->map_width != ft_wordcount(row, " "))
			return (0);
		row = ft_strtok(NULL, "\n");
	}
	free(map);
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
					points_new(j * 10, i * 10, ft_atoi(column[j])), NULL});
		ft_freesplit(column);
	}
	ft_freesplit(row);
	return (res);
}

int	**map_to_edges(t_model *model)
{
	int		**res;
	int		i;

	res = NULL;
	i = -1;
	while (++i < model->map_height * model->map_width)
	{
		if ((i + 1) % model->map_width != 0)
			res = points_append(res, (int *[]){points_new(i, i + 1, 0), NULL});
		if ((i + model->map_width) < model->map_height * model->map_width)
			res = points_append(res,
					(int *[]){points_new(i, i + model->map_width, 0), NULL});
	}
	return (res);
}
