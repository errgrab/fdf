/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 00:35:49 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/03/03 00:37:23 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	apply_rot_x(t_vec3 **points, int angle);
void	apply_rot_y(t_vec3 **points, int angle);
void	apply_rot_z(t_vec3 **points, int angle);
void	apply_translate(t_vec3 **points, t_vec3 trl);
void	apply_scale(t_vec3 **points, float scale);

void	apply_rot_x(t_vec3 **points, int angle)
{
	int	i;

	i = -1;
	while (points[++i])
		point_rotate(&points[i]->y, &points[i]->z, angle);
}

void	apply_rot_y(t_vec3 **points, int angle)
{
	int	i;

	i = -1;
	while (points[++i])
		point_rotate(&points[i]->x, &points[i]->z, angle);
}

void	apply_rot_z(t_vec3 **points, int angle)
{
	int	i;

	i = -1;
	while (points[++i])
		point_rotate(&points[i]->x, &points[i]->y, angle);
}

void	apply_translate(t_vec3 **points, t_vec3 trl)
{
	int	i;

	i = -1;
	while (points[++i])
	{
		points[i]->x += trl.x;
		points[i]->y += trl.y;
		points[i]->z += trl.z;
	}
}

void	apply_scale(t_vec3 **points, float scale)
{
	int	i;

	i = -1;
	while (points[++i])
	{
		points[i]->x = (int)(points[i]->x * scale);
		points[i]->y = (int)(points[i]->y * scale);
		points[i]->z = (int)(points[i]->z * scale);
	}
}
