/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 00:35:49 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/03/04 11:35:34 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	apply_rotate(int **points, int *angle);
void	apply_translate(int **points, int *trl);
void	apply_scale(int **points, float scale);
void	apply_weak_projection(int **points, float distance);

void	apply_rotate(int **points, int *angle)
{
	int	i;

	i = -1;
	while (points[++i])
	{
		point_rotate(&points[i][Y], &points[i][Z], angle[X]);
		point_rotate(&points[i][X], &points[i][Z], angle[Y]);
		point_rotate(&points[i][X], &points[i][Y], angle[Z]);
	}
}

void	apply_translate(int **points, int *trl)
{
	int	i;

	i = -1;
	while (points[++i])
	{
		points[i][X] += trl[X];
		points[i][Y] += trl[Y];
		points[i][Z] += trl[Z];
	}
}

void	apply_scale(int **points, float scale)
{
	int	i;

	i = -1;
	while (points[++i])
	{
		points[i][X] = (int)(points[i][X] * scale);
		points[i][Y] = (int)(points[i][Y] * scale);
		points[i][Z] = (int)(points[i][Z] * scale);
	}
}

void	apply_weak_projection(int **points, float distance)
{
	int	i;

	i = -1;
	while (points[++i])
	{
		points[i][X] = (int)(points[i][X] * (distance / points[i][Z]));
		points[i][Y] = (int)(points[i][Y] * (distance / points[i][Z]));
	}
}
