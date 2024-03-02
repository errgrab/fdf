/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:29:39 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/03/02 19:56:55 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		fdf_draw(t_fdf *fdf);
void	fdf_init(t_fdf *fdf);

void	apply_rot_x(t_vec3 **points, int angle)
{
	int	i;

	i = -1;
	while (points[++i])
		point_rotate(&points[i]->y, &points[i]->z, angle);
}

void	apply_rot_y(t_vec3 **points, int angle)
{
	int	i;

	i = -1;
	while (points[++i])
		point_rotate(&points[i]->x, &points[i]->z, angle);
}

void	apply_rot_z(t_vec3 **points, int angle)
{
	int	i;

	i = -1;
	while (points[++i])
		point_rotate(&points[i]->x, &points[i]->y, angle);
}

void	apply_translate(t_vec3 **points, t_vec3 trl)
{
	int	i;

	i = -1;
	while (points[++i])
	{
		points[i]->x += trl.x;
		points[i]->y += trl.y;
		points[i]->z += trl.z;
	}
}

void	apply_factor(t_vec3 **points, float factor)
{
	int	i;

	i = -1;
	while (points[++i])
	{
		if (points[i]->z == 0)
			continue ;
		points[i]->x = (int)(points[i]->x * (points[i]->z * factor));
		points[i]->y = (int)(points[i]->y * (points[i]->z * factor));
	}
}

void	draw_shape(t_fdf *fdf, t_vec3 **points, int **edges)
{
	int		i;
	t_vec2	 start;
	t_vec2	 end;

	i = -1;
	while (edges[++i])
	{
		start.x = points[edges[i][0]]->x;
		start.y = points[edges[i][0]]->y;
		end.x = points[edges[i][1]]->x;
		end.y = points[edges[i][1]]->y;
		draw_line(fdf, start, end, 0xffffff);
	}
}

int	fdf_draw(t_fdf *fdf)
{
	t_vec3	**points;
	int		**edges;

	points = (t_vec3 *[]){
		&(t_vec3){0, 0, 0}, &(t_vec3){100, 0, 0}, &(t_vec3){100, 100, 0},
		&(t_vec3){0, 100, 0}, &(t_vec3){0, 0, 100}, &(t_vec3){100, 0, 100},
		&(t_vec3){100, 100, 100}, &(t_vec3){0, 100, 100}, NULL};
	edges = (int *[]){
		(int[2]){0, 1}, (int[2]){1, 2}, (int[2]){2, 3}, (int[2]){3, 0},
		(int[2]){4, 5}, (int[2]){5, 6}, (int[2]){6, 7}, (int[2]){7, 4},
		(int[2]){0, 4}, (int[2]){1, 5}, (int[2]){2, 6}, (int[2]){3, 7}, NULL};
	mlx_clear_window(fdf->mlx, fdf->win);
	static int roty;
	static int rotx;
	static int rotz;
	apply_translate(points, (t_vec3){-50, -50, -50});
	apply_rot_y(points, roty);
	roty = (roty + 3) % 360;
	apply_rot_x(points, rotx);
	rotx = (rotx + 2) % 360;
	apply_rot_z(points, rotz);
	rotz = (rotz + 1) % 360;
	apply_translate(points, (t_vec3){0, 0, 150});
	apply_factor(points, .01);
	apply_translate(points, (t_vec3){150, 150, 0});
	usleep(30000);
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
