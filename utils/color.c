/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:07:04 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/03/11 18:43:02 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		color_len(int *colors);
int		*color_add(int *colors, int color);

int	color_len(int *colors)
{
	int	len;

	len = 0;
	while (colors[len])
		len++;
	return (len);
}

int	*color_add(int *colors, int color)
{
	int	*res;
	int	i;

	if (!colors)
		colors = (int *)ft_calloc(sizeof(int), 1);
	res = (int *)ft_calloc(sizeof(int), color_len(colors) + 2);
	if (!colors || !res)
		return (free(colors), free(res), NULL);
	i = -1;
	while (colors[++i])
		res[i] = colors[i];
	res[i] = color;
	free(colors);
	return (res);
}
