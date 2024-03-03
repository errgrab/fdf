/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:21:06 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/03/03 01:24:20 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <mlx.h>

# include <math.h>

# include <X11/X.h>
# include <X11/keysym.h>

/* types */
typedef struct s_fdf	t_fdf;

/* definitions */
enum
{
	X,
	Y,
	Z,
	W
};

struct	s_fdf
{
	void	*mlx;
	void	*win;
	int		win_size[2];
};

/* functions */

/* events.c */
int		event_quit(t_fdf *fdf);
int		event_keypress(int key, t_fdf *fdf);
int		event_keyrelease(int key, t_fdf *fdf);

/* draw.c */
void	draw_line(t_fdf *fdf, int line[2][2], int color);
void	draw_shape(t_fdf *fdf, int **points, int **edges);

/* fdf.c */
int		fdf_draw(t_fdf *fdf);
void	fdf_init(t_fdf *fdf);

/* undr.c */
size_t	_tern(int cond, size_t t_val, size_t f_val);

/* point.c */
void	point_rotate(int *px, int *py, int angle);
void	point_translate(int *px, int *py, int x, int y);
void	point_scale(int *px, int *py, double scale);

/* apply.c */
void	apply_rot(int **points, int *angle);
void	apply_translate(int **points, int *pos);
void	apply_scale(int **points, float scale);

#endif /* FDF_H */
