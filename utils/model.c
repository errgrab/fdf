/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   model.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 18:57:04 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/03/08 20:56:06 by ecarvalh         ###   ########.fr       */
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
	{
		ft_printf("Error on opening file\n");
		return (model_free(model));
	}
	model->map = map_get_fd(model->fd);
	if (!model->map)
		return (model_free(model));
	if (!map_validate(model->map, &model->map_width, &model->map_height))
		return (model_free(model));
	model->points = map_to_points(model->map);
	model->edges = map_to_edges(model->map);
	model->position = points_new(150, 150, 0);
	model->rotation = points_new(0, 0, 0);
	model->scale = points_new(10, 10, 2);
	if (!model->points || !model->edges
		|| !model->position || !model->rotation || !model->scale)
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
	points_free(model->points);
	points_free(model->edges);
	free(model->position);
	free(model->rotation);
	free(model->scale);
	free(model);
	return (NULL);
}
