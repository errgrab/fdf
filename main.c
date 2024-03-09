/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:20:20 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/03/08 21:04:10 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_fdf	fdf;

	fdf_init(&fdf, ac, av);
	return (0);
}

/*
int	main(int ac, char **av)
{
	int		fd;
	char	*map;
	int		**points;
	int		**edges;
	int		i;

	if (ac < 2)
		return (1);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (1);
	map = map_get_fd(fd);
	points = map_to_points(map);
	edges = map_to_edges(map);
	i = -1;
	while (points[++i])
		ft_printf("points[%d] = {%d, %d, %d};\n", i,
				points[i][X], points[i][Y], points[i][Z]);
	i = -1;
	while (edges[++i])
		ft_printf("edges[%d] = {%d, %d, %d};\n", i,
				edges[i][X], edges[i][Y], edges[i][Z]);
	return (0);
}
*/
