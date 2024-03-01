/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:29:39 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/03/01 20:45:25 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		fdf_draw(t_fdf *fdf);
void	fdf_init(t_fdf *fdf);

/*
0
33
66
100
*/

void	trl_shape(t_vec2 **shape, t_vec2 pos)
{
	int	i;

	i = -1;
	while (shape[++i])
		simple_trl(&shape[i]->x, &shape[i]->y, pos);
}

void	rot_shape(t_vec2 **shape, int angle)
{
	int	i;

	i = -1;
	while (shape[++i])
		simple_rot(&shape[i]->x, &shape[i]->y, angle);
}

int	fdf_draw(t_fdf *fdf)
{
	static int	rotn;
	t_vec2	**points;

	points = (t_vec2 *[]){
		&(t_vec2){100, 0}, &(t_vec2){100, 66},
		&(t_vec2){66, 66}, &(t_vec2){66, 100},
		&(t_vec2){0, 100}, &(t_vec2){0, 33},
		&(t_vec2){33, 33}, &(t_vec2){33, 0},
		&(t_vec2){100, 0}, NULL};
	mlx_clear_window(fdf->mlx, fdf->win);
	trl_shape(points, (t_vec2){-50, -50});
	rot_shape(points, rotn);
	rotn = (rotn + 1) % 360;
	trl_shape(points, (t_vec2){50, 50});
	trl_shape(points, (t_vec2){100, 100});
	draw_shape(fdf, points, 0xffffff);
	usleep(10000);
	return (0);
}

void	fdf_init(t_fdf *fdf)
{
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		exit(1);
	fdf->win_size = (t_vec2){300, 300};
	fdf->win = mlx_new_window(
			fdf->mlx, fdf->win_size.x, fdf->win_size.y, "fdf");
	if (!fdf->win)
	{
		free(fdf->mlx);
		exit(1);
	}
	mlx_hook(fdf->win, KeyRelease, KeyReleaseMask, event_keyrelease, fdf);
	mlx_hook(fdf->win, DestroyNotify, StructureNotifyMask, event_quit, fdf);
	mlx_loop_hook(fdf->mlx, fdf_draw, fdf);
	mlx_loop(fdf->mlx);
}
