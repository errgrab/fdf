/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:29:39 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/03/03 01:21:56 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		fdf_draw(t_fdf *fdf);
void	fdf_init(t_fdf *fdf);

int	fdf_draw(t_fdf *fdf)
{
	int	**points;
	int	**edges;

	points = (int *[]){
		(int [3]){0, 0, 0}, (int [3]){100, 0, 0}, (int [3]){100, 100, 0},
		(int [3]){0, 100, 0}, (int [3]){0, 0, 100}, (int [3]){100, 0, 100},
		(int [3]){100, 100, 100}, (int [3]){0, 100, 100}, NULL};
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
	fdf->win_size[X] = 300;
	fdf->win_size[Y] = 300;
	fdf->win = mlx_new_window(
			fdf->mlx, fdf->win_size[X], fdf->win_size[Y], "fdf");
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
