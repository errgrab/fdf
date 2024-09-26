/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 19:14:53 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/09/26 12:29:52 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

char	*map_get_fd(int fd);
int		map_validate(t_model *model);
int		**map_to_points(t_model *model);
int		**map_to_edges(t_model *model);

char	*map_get_fd(int fd)
{
	char	*line;
	char	*res;

	line = ft_getline_fd(fd);
	res = NULL;
	while (line)
	{
		res = ft_strapnd(res, line);
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

int	**map_to_points(t_model *model)
{
	auto int **res = NULL;
	auto char *map = ft_strdup(model->map);
	auto char *tok = ft_strtok(map, " \n");
	auto int i = 0;
	auto int j = -1;
	while (tok)
	{
		i = i % model->map_width;
		if (i == 0)
			j++;
		res = points_append(res, (int *[]){
				points_new(i * 10, j * 10, ft_atoi(tok)), NULL});
		if (ft_strnstr(tok, ",0x", ft_strlen(tok)))
			model->colors = color_add(model->colors,
					ft_atoi_base(&ft_strnstr(tok, ",0x", ft_strlen(tok))[3],
						"0123456789abcdef"));
		else
			model->colors = color_add(model->colors, 0xffffff);
		tok = ft_strtok(NULL, " \n");
		i++;
	}
	free(map);
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
