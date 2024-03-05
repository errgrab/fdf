/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:34:12 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/03/04 11:44:22 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	point_rotate(int *px, int *py, int angle);

void	point_rotate(int *px, int *py, int angle)
{
	int		x;
	int		y;
	double	angle_rad;

	x = *px;
	y = *py;
	angle_rad = (angle % 360) * M_PI / 180.0;
	*px = (int)(x * cos(angle_rad) - y * sin(angle_rad));
	*py = (int)(x * sin(angle_rad) + y * cos(angle_rad));
}
