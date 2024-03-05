/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:27:46 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/03/04 11:22:56 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_fdf *fdf, int **line, int color);
void	draw_shape(t_fdf *fdf, int **points, int **edges);

/* [Thnks Wikipedia!](https://en.wikipedia.org/wiki/Bresenham's_line_algorithm)
 *
 * This is one of the most important functions of this project. With the power
 * of drawing lines, I can draw triangles. You can make any shape with only
 * triangles.
 *
 * explanation of the implementation:
 * int **line is the same as int line[2][2]
 * line[0] is the first point of the line
 * line[1] is the seccond
 * line[0][X] gets the x position of the first line
 */
void	draw_line(t_fdf *fdf, int **line, int color)
{
	int	*dif;
	int	*dir;
	int	err;

	dif = (int [2]){
		abs(line[1][X] - line[0][X]),
		-abs(line[1][Y] - line[0][Y])};
	dir = (int [2]){
		_tern(line[0][X] < line[1][X], 1, -1),
		_tern(line[0][Y] < line[1][Y], 1, -1)};
	err = dif[X] + dif[Y];
	while (line[0][X] != line[1][X] || line[0][Y] != line[1][Y])
	{
		mlx_pixel_put(fdf->mlx, fdf->win, line[0][X], line[0][Y], color);
		if (2 * err >= dif[Y] && line[0][X] != line[1][X])
		{
			err += dif[Y];
			line[0][X] += dir[X];
		}
		if (2 * err <= dif[X] && line[0][Y] != line[1][Y])
		{
			err += dif[X];
			line[0][Y] += dir[Y];
		}
	}
}

void	draw_shape(t_fdf *fdf, int **points, int **edges)
{
	int	i;
	int	**line;

	i = -1;
	while (edges[++i])
	{
		line = (int *[]){
			(int [2]){points[edges[i][0]][X], points[edges[i][0]][Y]},
			(int [2]){points[edges[i][1]][X], points[edges[i][1]][Y]}};
		draw_line(fdf, line, 0xffffff);
	}
}
