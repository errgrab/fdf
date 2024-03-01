/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:27:46 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/03/01 19:31:11 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_rect_bord(t_fdf *fdf, t_vec4 rect, int color);
void	draw_shape(t_fdf *fdf, t_vec2 **shape, int color);
void	draw_line(t_fdf *fdf, t_vec2 start, t_vec2 end, int color);

void	draw_rect_bord(t_fdf *fdf, t_vec4 rect, int color)
{
	int		x;
	int		y;
	int		ex;
	int		ey;
	t_vec2	**points;

	x = rect.x;
	y = rect.y;
	ex = x + rect.z;
	ey = y + rect.w;
	points = (t_vec2 *[]){
		&(t_vec2){x, y}, &(t_vec2){ex, y}, &(t_vec2){ex, ey}, &(t_vec2){x, ey},
		&(t_vec2){x, y}, NULL};
	draw_shape(fdf, points, color);
}

void	draw_shape(t_fdf *fdf, t_vec2 **shape, int color)
{
	int	i;

	i = 0;
	while (shape[++i])
		draw_line(fdf, shape[i - 1][0], shape[i][0], color);
}

/* [Thnks Wikipedia!](https://en.wikipedia.org/wiki/Bresenham's_line_algorithm)
 */
void	draw_line(t_fdf *fdf, t_vec2 start, t_vec2 end, int color)
{
	t_vec2	dif;
	t_vec2	dir;
	int		err;

	dif = (t_vec2){
		abs(end.x - start.x),
		-abs(end.y - start.y)};
	dir = (t_vec2){
		_tern(start.x < end.x, 1, -1),
		_tern(start.y < end.y, 1, -1)};
	err = dif.x + dif.y;
	while (start.x != end.x || start.y != end.y)
	{
		mlx_pixel_put(fdf->mlx, fdf->win, start.x, start.y, color);
		if (2 * err >= dif.y && start.x != end.x)
		{
			err += dif.y;
			start.x += dir.x;
		}
		if (2 * err <= dif.x && start.y != end.y)
		{
			err += dif.x;
			start.y += dir.y;
		}
	}
}
