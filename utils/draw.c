/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:27:46 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/03/03 00:53:27 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_fdf *fdf, int line[4], int color);
void	draw_shape(t_fdf *fdf, t_vec3 **points, int **edges);

/* [Thnks Wikipedia!](https://en.wikipedia.org/wiki/Bresenham's_line_algorithm)
 *
 * This is one of the most important functions of this project. With the power
 * of drawing lines, I can draw triangles. You can make any shape with only
 * triangles.
 */
void	draw_line(t_fdf *fdf, int line[4], int color)
{
	t_vec2	dif;
	t_vec2	dir;
	int		err;

	dif = (t_vec2){
		abs(line[2] - line[0]),
		-abs(line[3] - line[1])};
	dir = (t_vec2){
		_tern(line[0] < line[2], 1, -1),
		_tern(line[1] < line[3], 1, -1)};
	err = dif.x + dif.y;
	while (line[0] != line[2] || line[1] != line[3])
	{
		mlx_pixel_put(fdf->mlx, fdf->win, line[0], line[1], color);
		if (2 * err >= dif.y && line[0] != line[2])
		{
			err += dif.y;
			line[0] += dir.x;
		}
		if (2 * err <= dif.x && line[1] != line[3])
		{
			err += dif.x;
			line[1] += dir.y;
		}
	}
}

void	draw_shape(t_fdf *fdf, t_vec3 **points, int **edges)
{
	int	i;
	int	line[4];

	i = -1;
	while (edges[++i])
	{
		line[0] = points[edges[i][0]]->x;
		line[1] = points[edges[i][0]]->y;
		line[2] = points[edges[i][1]]->x;
		line[3] = points[edges[i][1]]->y;
		draw_line(fdf, line, 0xffffff);
	}
}
