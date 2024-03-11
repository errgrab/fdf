/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:57:04 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/03/11 18:42:51 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	*model_init(int ac, char **av);
void	*model_free(t_model *model);

void	*model_init(int ac, char **av)
{
	t_model	*model;

	if (ac < 2)
		return (NULL);
	model = (t_model *)ft_calloc(sizeof(t_model), 1);
	model->fd = open(av[1], O_RDONLY);
	if (model->fd < 0)
		return (ft_printf("Error on opening file\n"), model_free(model));
	model->map = map_get_fd(model->fd);
	if (!model->map || !map_validate(model))
		return (ft_printf("Error on building map\n"), model_free(model));
	model->points = map_to_points(model);
	model->edges = map_to_edges(model);
	model->position = points_new(150, 150, -1200);
	model->rotation = points_new(45, 45, 0);
	model->scale = points_new(100, 100, 150);
	if (!model->points || !model->edges || !model->position || !model->rotation
		|| !model->scale)
		return (model_free(model));
	return (model);
}

void	*model_free(t_model *model)
{
	if (!model)
		return (NULL);
	if (model->fd > 0)
		close(model->fd);
	else
		return (NULL);
	free(model->map);
	if (model->points)
		points_free(model->points);
	if (model->edges)
		points_free(model->edges);
	free(model->position);
	free(model->rotation);
	free(model->scale);
	free(model->colors);
	free(model);
	return (NULL);
}
