/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:25:51 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/03/10 15:56:46 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int			event_quit(t_fdf *fdf);
static void	event_movement(int key, t_fdf *fdf);
static void	event_scale(int key, t_fdf *fdf);
int			event_keypress(int key, t_fdf *fdf);
int			event_keyrelease(int key, t_fdf *fdf);

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

static void	event_movement(int key, t_fdf *fdf)
{
	auto int *keys = (int []){XK_s, XK_w, XK_a, XK_d, XK_i, XK_k, XK_j, XK_l,
		XK_f, XK_r, XK_h, XK_y};
	auto int **args = (int *[]){
		(int []){-1, 0, 0, 0, 0, 0}, (int []){1, 0, 0, 0, 0, 0},
		(int []){0, -1, 0, 0, 0, 0}, (int []){0, 1, 0, 0, 0, 0},
		(int []){0, 0, 0, 0, -1, 0}, (int []){0, 0, 0, 0, 1, 0},
		(int []){0, 0, 0, -1, 0, 0}, (int []){0, 0, 0, 1, 0, 0},
		(int []){0, 0, -1, 0, 0, 0}, (int []){0, 0, 1, 0, 0, 0},
		(int []){0, 0, 0, 0, 0, -1}, (int []){0, 0, 0, 0, 0, 1}};
	auto int i = -1;
	while (++i < 12)
		if (keys[i] == key)
			break ;
	if (i == 12)
		return ;
	fdf->model->rotation[X] += args[i][0] * fdf->event_weight;
	fdf->model->rotation[Y] += args[i][1] * fdf->event_weight;
	fdf->model->rotation[Z] += args[i][2] * fdf->event_weight;
	fdf->model->position[X] += args[i][3] * fdf->event_weight;
	fdf->model->position[Y] += args[i][4] * fdf->event_weight;
	fdf->model->position[Z] += args[i][5] * fdf->event_weight;
	fdf->img_updated = 0;
}

static void	event_scale(int key, t_fdf *fdf)
{
	auto int *keys = (int []){XK_q, XK_e, XK_u, XK_o, XK_g, XK_t,
		XK_comma, XK_period};
	auto int **args = (int *[]){
		(int []){-1, 0, 0, 0}, (int []){1, 0, 0, 0},
		(int []){0, -1, 0, 0}, (int []){0, 1, 0, 0},
		(int []){0, 0, -1, 0}, (int []){0, 0, 1, 0},
		(int []){0, 0, 0, -1}, (int []){0, 0, 0, 1},
	};
	auto int i = -1;
	while (++i < 8)
		if (keys[i] == key)
			break ;
	if (i == 8)
		return ;
	fdf->model->scale[Z] += args[i][0] * fdf->event_weight;
	fdf->model->scale[X] += args[i][1] * fdf->event_weight;
	fdf->model->scale[Y] += args[i][1] * fdf->event_weight;
	if (fdf->distance + args[i][2] * fdf->event_weight > 0)
		fdf->distance += args[i][2] * fdf->event_weight;
	if (fdf->event_weight + args[i][3] > 0)
		fdf->event_weight += args[i][3];
	fdf->img_updated = 0;
}

int	event_keypress(int key, t_fdf *fdf)
{
	event_movement(key, fdf);
	event_scale(key, fdf);
	return (0);
}

int	event_keyrelease(int key, t_fdf *fdf)
{
	if (key == XK_Escape)
		event_quit(fdf);
	if (key == XK_m)
	{
		fdf->perspective = !fdf->perspective;
		fdf->img_updated = 0;
	}
	return (0);
}
