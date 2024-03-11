/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:27:46 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/03/11 12:19:39 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_set_color(char *buff, int color, int endian);
void	draw_pixel(t_fdf *fdf, int px, int py, int color);
void	draw_clear(t_fdf *fdf, int color);
void	draw_line(t_fdf *fdf, int **line, int color);
void	draw_shape(t_fdf *fdf, int **points, int **edges);

/* Damn, I need to consider the endianess. */
void	draw_set_color(char *buff, int color, int endian)
{
	if (endian == 1)
	{
		buff[0] = (char)0xff;
		buff[1] = (color >> 16) & 0xff;
		buff[2] = (color >> 8) & 0xff;
		buff[3] = (color >> 0) & 0xff;
		return ;
	}
	buff[0] = (color >> 0) & 0xff;
	buff[1] = (color >> 8) & 0xff;
	buff[2] = (color >> 16) & 0xff;
	buff[3] = (char)0xff;
}

/* MLX is complex. I need to make this c_color (conversed color) before write
 * the color to the buffer. */
void	draw_pixel(t_fdf *fdf, int px, int py, int color)
{
	unsigned int	c_color;
	int				pos;

	if (px >= fdf->size[X] || px < 0
		|| py >= fdf->size[Y] || py < 0)
		return ;
	c_color = mlx_get_color_value(fdf->mlx, color);
	pos = (py * fdf->size[X] * 4) + (px * 4);
	draw_set_color(&fdf->buf[pos], c_color, fdf->img_endian);
}

void	draw_clear(t_fdf *fdf, int color)
{
	int	i;

	i = 0;
	while (i < fdf->size[X] * 4 * fdf->size[Y])
	{
		draw_set_color(&fdf->buf[i], color, fdf->img_endian);
		i += 4;
	}
}

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
 * line[0][X] gets the x position of the first line */
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
		draw_pixel(fdf, line[0][X], line[0][Y], color);
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

/* Iterating over the edges and drawing lines...
 * I would say: "Drawing lines, fealing fine", but faster */
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
