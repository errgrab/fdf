/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:21:06 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/03/05 16:35:34 by ecarvalh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <mlx.h>

# include <math.h>
# include <fcntl.h>

# include <X11/X.h>
# include <X11/keysym.h>

/* types */
typedef struct s_fdf	t_fdf;
typedef struct s_model	t_model;

/* definitions */

/* I use this like:
 * #define X 0
 * basically you can do:
 * model[X] = 240 // to transform the X position of the model to 240
 * this is basically a sytax suggar. */
enum
{
	X,
	Y,
	Z,
	W
};

/* int points[null_terminated][3] : is every point of the model
 * int sides[null_terminated][3]  : is every side (line) of the model
 * int position[3] : is the position of the model on the world
 * int rotation[3] : is the xyz roation of the model
 * float scale     : is the scale of the model */
struct	s_model
{
	int		**points;
	int		**sides;
	int		*colors;
	int		*position;
};

struct	s_fdf
{
	void	*mlx;
	void	*win;
	void	*win_img;
	int		*win_size;
	t_model	*model;
};

/* functions */

/* events.c */
int		event_quit(t_fdf *fdf);
int		event_keypress(int key, t_fdf *fdf);
int		event_keyrelease(int key, t_fdf *fdf);

/* draw.c */
void	draw_line(t_fdf *fdf, int **line, int color);
void	draw_shape(t_fdf *fdf, int **points, int **edges);

/* fdf.c */
int		fdf_draw(t_fdf *fdf);
void	fdf_init(t_fdf *fdf);

/* undr.c */
size_t	_tern(int cond, size_t t_val, size_t f_val);

/* point.c */
void	point_rotate(int *px, int *py, int angle);

/* apply.c */
void	apply_rotate(int **points, int *angle);
void	apply_translate(int **points, int *pos);
void	apply_scale(int **points, float scale);
void	apply_weak_projection(int **points, float distance);

#endif /* FDF_H */
