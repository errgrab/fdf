/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 20:32:17 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/03/11 12:21:49 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_update(t_fdf *fdf);

void	img_update(t_fdf *fdf)
{
	int	**points;

	if (fdf->img_updated)
		return ;
	draw_clear(fdf, 0x1d2021);
	points = points_copy(fdf->model->points);
	apply_scale(points, fdf->model->scale);
	apply_rotate(points, fdf->model->rotation);
	apply_translate(points, (int []){0, 0, fdf->model->position[Z]});
	if (fdf->perspective)
		apply_weak_projection(points, fdf->distance);
	apply_translate(points, fdf->model->position);
	draw_shape(fdf, points, fdf->model->edges);
	points_free(points);
	fdf->img_updated = 1;
	fdf->img_drawed = 0;
}
