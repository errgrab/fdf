/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xy.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 13:34:12 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/03/07 19:25:27 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	xy_rotate(int *px, int *py, int angle);

void	xy_rotate(int *px, int *py, int angle)
{
	double	x;
	double	y;
	double	angle_rad;

	x = *px;
	y = *py;
	angle_rad = (angle % 360) * M_PI / 180.0;
	*px = round(x * cos(angle_rad) - y * sin(angle_rad));
	*py = round(x * sin(angle_rad) + y * cos(angle_rad));
}
