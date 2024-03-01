/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 17:25:51 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/28 13:32:30 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	event_quit(t_fdf *fdf);
int	event_keyrelease(int key, t_fdf *fdf);

int	event_quit(t_fdf *fdf)
{
	mlx_destroy_window(fdf->mlx, fdf->win);
	mlx_destroy_display(fdf->mlx);
	free(fdf->mlx);
	exit(0);
	return (0);
}

int	event_keyrelease(int key, t_fdf *fdf)
{
	if (key == XK_Escape)
		event_quit(fdf);
	return (0);
}
