/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:20:20 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/03/11 13:52:50 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	main(int ac, char **av)
{
	t_fdf	fdf;

	if (ac == 1)
		return (ft_printf("Segmentation Fault (core dumped)\n"), 1);
	fdf_init(&fdf, ac, av);
	return (0);
}
