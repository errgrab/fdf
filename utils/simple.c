/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 19:11:26 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/03/01 19:15:23 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	simple_rot(int *px, int *py, int angle);
void	simple_trl(int *px, int *py, t_vec2 pos);

void	simple_rot(int *px, int *py, int angle)
{
	int		x;
	int		y;
	int		cos_appr;
	int		sin_appr;
	double	angle_rad;

	x = *px;
	y = *py;
	angle_rad = (angle % 360) * M_PI / 180.0;
	cos_appr = (int)(cos(angle_rad) * 1024);
	sin_appr = (int)(sin(angle_rad) * 1024);
	*px = (x * cos_appr - y * sin_appr) / 1024;
	*py = (x * sin_appr + y * cos_appr) / 1024;
}

void	simple_trl(int *px, int *py, t_vec2 pos)
{
	*px += pos.x;
	*py += pos.y;
}
