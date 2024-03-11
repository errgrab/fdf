/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 17:45:12 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/03/11 18:19:38 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_to_lower(char *str);
int		ft_atoi_base(char *str, char *base);

void	ft_to_lower(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += ('a' - 'A');
	}
}

int	ft_atoi_base(char *str, char *base)
{
	int	res;
	int	len;
	int	i;

	res = 0;
	ft_to_lower(str);
	len = ft_strlen(base);
	i = -1;
	while (str[++i] && ft_strchr(base, str[i]))
		res = (res * len) + (ft_strchr(base, str[i]) - base);
	return (res);
}
