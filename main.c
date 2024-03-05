/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:20:20 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/03/05 22:49:43 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

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

int	*points_new(int x, int y, int z)
{
	int	*res;

	res = (int*)ft_calloc(sizeof(int), 3);
	if (!res)
		return (NULL);
	res[X] = x;
	res[Y] = y;
	res[Z] = z;
	return (res);
}

int	points_len(int **points)
{
	int	len;

	len = 0;
	if (!points)
		return (len);
	while (points[len])
		len++;
	return (len);
}

void	*points_free(int **points)
{
	int	i;

	i = -1;
	while (points[++i])
		free(points[i]);
	free(points);
	return (NULL);
}

int	**points_append(int **dest, int **src)
{
	int	**res;
	int	i;
	int	j;

	if (!dest)
		dest = ft_calloc(sizeof(int*), 1);
	res = (int**)ft_calloc(sizeof(int*),
			points_len(dest) + points_len(src) + 1);
	if (!res)
		return (NULL);
	i = -1;
	j = 0;
	while (dest[++i])
		res[i] = dest[i];
	while (src[j])
		res[i++] = src[j++];
	res[i] = NULL;
	free(dest);
	return (res);
}

int	**line_to_points(char *line, int pos)
{
	int		**res;
	char	**row;
	int		**appnd;
	int		*point;
	int		i;

	res = NULL;
	row = ft_split(line, " ");
	i = -1;
	while (row[++i])
	{
		point = points_new(i, ft_atoi(row[i]), pos);
		appnd = (int *[]){point, NULL};
		res = points_append(res, appnd);
	}
	ft_freesplit(row);
	return (res);
}

int	**map_to_points(char *map)
{
	int		**res;
	int		**line_points;
	char	**line;
	int		i;

	res = NULL;
	line = ft_split(map, "\n");
	if (!line)
		return (NULL);
	i = -1;
	while (line[++i])
	{
		line_points = line_to_points(line[i], i);
		res = points_append(res, line_points);
		free(line_points);
	}
	ft_freesplit(line);
	return (res);
}

int	main(int ac, char **av)
{
	int		fd;
	char	*map;
	int		**points;
	int		i;
//	t_fdf	fdf;

	if (ac < 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
	{
		ft_printf("Error on opening file\n");
		return (1);
	}
	map = map_get_fd(fd);
	points = map_to_points(map);
	i = -1;
	while (points[++i])
		ft_printf("point %d: x: %d, y: %d, z: %d\n",
				i, points[i][X], points[i][Y], points[i][Z]);
	points_free(points);
//	fdf_init(&fdf);
	free(map);
	close(fd);
	return (0);
}
