/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 20:32:17 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/03/09 13:07:52 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	img_update(t_fdf *fdf);

void	img_update(t_fdf *fdf)
{
	int	**points;

	if (fdf->img_updated)
		return ;
	draw_clear(fdf);
	points = points_copy(fdf->model->points);
	apply_scale(points, fdf->model->scale);
	apply_rotate(points, fdf->model->rotation);
	apply_translate(points, fdf->model->position);
	draw_shape(fdf, points, fdf->model->edges);
	points_free(points);
	fdf->img_updated = 1;
	fdf->img_drawed = 0;
}
