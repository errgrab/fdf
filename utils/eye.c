/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eye.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/03 00:40:25 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/03/03 00:40:34 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	eye_projection(t_vec3 **points, float factor)
{
	int	i;

	i = -1;
	while (points[++i])
	{
		points[i]->x = (int)(points[i]->x * (factor * points[i]->z));
		points[i]->y = (int)(points[i]->y * (factor * points[i]->z));
	}
}
