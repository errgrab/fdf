/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 22:56:15 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/03/07 20:46:02 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		*points_new(int x, int y, int z);
int		points_len(int **points);
void	*points_free(int **points);
int		**points_append(int **dest, int **src);
int		**points_copy(int **points);

int	*points_new(int x, int y, int z)
{
	int	*res;

	res = (int *)ft_calloc(sizeof(int), 3);
	if (!res)
		return (NULL);
	res[X] = x;
	res[Y] = y;
	res[Z] = z;
	return (res);
}

int	points_len(int **points)
{
	int	len;

	len = 0;
	if (!points)
		return (len);
	while (points[len])
		len++;
	return (len);
}

void	*points_free(int **points)
{
	int	i;

	i = -1;
	while (points[++i])
		free(points[i]);
	free(points);
	return (NULL);
}

int	**points_append(int **dest, int **src)
{
	int	**res;
	int	i;
	int	j;

	if (!dest)
		dest = (int **)ft_calloc(sizeof(int *), 1);
	res = (int **)ft_calloc(sizeof(int *),
			points_len(dest) + points_len(src) + 1);
	if (!res)
		return (NULL);
	i = -1;
	j = 0;
	while (dest[++i])
		res[i] = dest[i];
	while (src[j])
		res[i++] = src[j++];
	res[i] = NULL;
	free(dest);
	return (res);
}

int	**points_copy(int **points)
{
	int	**res;
	int	i;

	res = (int **)ft_calloc(sizeof(int *), points_len(points) + 1);
	i = -1;
	while (points[++i])
		res[i] = points_new(points[i][X], points[i][Y], points[i][Z]);
	return (res);
}
