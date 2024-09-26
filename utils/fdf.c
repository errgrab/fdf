/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:29:39 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/09/26 12:28:45 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		fdf_draw(t_fdf *fdf);
void	fdf_init(t_fdf *fdf, int ac, char **av);

int	fdf_draw(t_fdf *fdf)
{
	if (!fdf->img_updated)
	{
		img_update(fdf);
		mlx_put_image_to_window(fdf->mlx, fdf->win, fdf->img, 0, 0);
		return (0);
	}
	return (0);
}

void	fdf_init(t_fdf *fdf, int ac, char **av)
{
	fdf->model = model_init(ac, av);
	if (!fdf->model)
		return ;
	fdf->mlx = mlx_init();
	if (!fdf->mlx)
		exit(1);
	fdf->size = (int [2]){900, 600};
	fdf->win = mlx_new_window(fdf->mlx, fdf->size[X], fdf->size[Y], "");
	fdf->img = mlx_new_image(fdf->mlx, fdf->size[X], fdf->size[Y]);
	fdf->buf = mlx_get_data_addr(fdf->img, &fdf->img_pixel_bits,
			&fdf->img_line_bytes, &fdf->img_endian);
	if (!fdf->win || !fdf->img)
		event_quit(fdf);
	fdf->img_updated = 0;
	fdf->event_weight = 5;
	fdf->distance = 1000;
	fdf->perspective = 1;
	mlx_hook(fdf->win, KeyRelease, KeyReleaseMask, event_keyrelease, fdf);
	mlx_hook(fdf->win, KeyPress, KeyPressMask, event_keypress, fdf);
	mlx_hook(fdf->win, DestroyNotify, StructureNotifyMask, event_quit, fdf);
	mlx_loop_hook(fdf->mlx, fdf_draw, fdf);
	mlx_loop(fdf->mlx);
}
