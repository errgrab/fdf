/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   undr.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 17:54:51 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/02/29 17:55:41 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

size_t	_tern(int cond, size_t t_val, size_t f_val)
{
	if (cond)
		return (t_val);
	return (f_val);
}
