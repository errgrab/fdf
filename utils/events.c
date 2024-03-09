/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:25:51 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/03/08 23:07:44 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	event_quit(t_fdf *fdf);
int	event_keyrelease(int key, t_fdf *fdf);

int	event_quit(t_fdf *fdf)
{
	if (fdf->win)
		mlx_destroy_window(fdf->mlx, fdf->win);
	if (fdf->img)
		mlx_destroy_image(fdf->mlx, fdf->img);
	mlx_destroy_display(fdf->mlx);
	model_free(fdf->model);
	free(fdf->mlx);
	exit(0);
	return (0);
}

int	event_keypress(int key, t_fdf *fdf)
{
	if (key == XK_w)
		fdf->model->rotation[X] -= 10;
	if (key == XK_s)
		fdf->model->rotation[X] += 10;
	if (key == XK_a)
		fdf->model->rotation[Y] -= 10;
	if (key == XK_d)
		fdf->model->rotation[Y] += 10;
	if (key == XK_j)
		fdf->model->position[X] -= 10;
	if (key == XK_l)
		fdf->model->position[X] += 10;
	if (key == XK_i)
		fdf->model->position[Y] -= 10;
	if (key == XK_k)
		fdf->model->position[Y] += 10;

	if (key == XK_u)
		fdf->model->scale[Z] += 1;
	if (key == XK_o)
		fdf->model->scale[Z] -= 1;
	if (key == XK_q)
	{
		fdf->model->scale[X] -= 1;
		fdf->model->scale[Y] -= 1;
	}
	if (key == XK_e)
	{
		fdf->model->scale[X] += 1;
		fdf->model->scale[Y] += 1;
	}
	if (key == XK_w || key == XK_a || key == XK_s || key == XK_d
		|| key == XK_i || key == XK_j || key == XK_k || key == XK_l
		|| key == XK_u || key == XK_o || key == XK_q || key == XK_e)
		fdf->img_updated = 0;
	return (0);
}

int	event_keyrelease(int key, t_fdf *fdf)
{
	if (key == XK_Escape)
		event_quit(fdf);
	return (0);
}
