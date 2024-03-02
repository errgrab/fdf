/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:27:46 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/03/02 14:45:09 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	draw_line(t_fdf *fdf, t_vec2 start, t_vec2 end, int color);

/* [Thnks Wikipedia!](https://en.wikipedia.org/wiki/Bresenham's_line_algorithm)
 *
 * This is one of the most important functions of this project. With the power
 * of drawing lines, I can draw triangles. You can make any shape with only
 * triangles.
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
