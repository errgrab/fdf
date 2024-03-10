/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:25:51 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/03/09 23:56:00 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	event_quit(t_fdf *fdf);
int	event_keypress(int key, t_fdf *fdf);
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
	auto int *keys = (int []){XK_w, XK_a, XK_s, XK_d, XK_i, XK_j, XK_k, XK_l,
		XK_q, XK_e, XK_u, XK_o};
	auto int **args = (int *[]){
		(int []){-5, 0, 0, 0, 0, 0}, (int []){0, -5, 0, 0, 0, 0},
		(int []){5, 0, 0, 0, 0, 0}, (int []){0, 5, 0, 0, 0, 0},
		(int []){0, 0, 0, -5, 0, 0}, (int []){0, 0, -5, 0, 0, 0},
		(int []){0, 0, 0, 5, 0, 0}, (int []){0, 0, 5, 0, 0, 0},
		(int []){0, 0, 0, 0, -5, 0}, (int []){0, 0, 0, 0, 5, 0},
		(int []){0, 0, 0, 0, 0, -5}, (int []){0, 0, 0, 0, 0, 5}};
	auto int i = -1;
	while (++i < 12)
		if (keys[i] == key)
			break ;
	if (i == 12)
		return (0);
	fdf->model->rotation[X] += args[i][0];
	fdf->model->rotation[Y] += args[i][1];
	fdf->model->position[X] += args[i][2];
	fdf->model->position[Y] += args[i][3];
	fdf->model->scale[Z] += args[i][4];
	fdf->model->scale[X] += args[i][5];
	fdf->model->scale[Y] += args[i][5];
	fdf->img_updated = 0;
	return (0);
}

int	event_keyrelease(int key, t_fdf *fdf)
{
	if (key == XK_Escape)
		event_quit(fdf);
	return (0);
}
