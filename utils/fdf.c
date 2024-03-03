/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:29:39 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/03/03 00:55:18 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		fdf_draw(t_fdf *fdf);
void	fdf_init(t_fdf *fdf);

int	fdf_draw(t_fdf *fdf)
{
	t_vec3	**points;
	int		**edges;

	points = (t_vec3 *[]){
		&(t_vec3){0, 0, 0}, &(t_vec3){100, 0, 0}, &(t_vec3){100, 100, 0},
		&(t_vec3){0, 100, 0}, &(t_vec3){0, 0, 100}, &(t_vec3){100, 0, 100},
		&(t_vec3){100, 100, 100}, &(t_vec3){0, 100, 100}, NULL};
	edges = (int *[]){
		(int [2]){0, 1}, (int [2]){1, 2}, (int [2]){2, 3}, (int [2]){3, 0},
		(int [2]){4, 5}, (int [2]){5, 6}, (int [2]){6, 7}, (int [2]){7, 4},
		(int [2]){0, 4}, (int [2]){1, 5}, (int [2]){2, 6}, (int [2]){3, 7},
		NULL};
	mlx_clear_window(fdf->mlx, fdf->win);
	draw_shape(fdf, points, edges);
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
