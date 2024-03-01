/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:21:06 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/03/01 19:18:05 by ecarvalh         ###   ########.fr       */
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
typedef struct s_vec2	t_vec2;
typedef struct s_vec3	t_vec3;
typedef struct s_vec4	t_vec4;
typedef struct s_fdf	t_fdf;

/* definitions */
struct	s_vec2
{
	int	x;
	int	y;
};

struct	s_vec3
{
	int	x;
	int	y;
	int	z;
};

struct	s_vec4
{
	int	x;
	int	y;
	int	z;
	int	w;
};

struct	s_fdf
{
	void	*mlx;
	void	*win;
	t_vec2	win_size;
};

/* functions */

/* events.c */
int		event_quit(t_fdf *fdf);
int		event_keyrelease(int key, t_fdf *fdf);

/* draw.c */
void	draw_rect_bord(t_fdf *fdf, t_vec4 rect, int color);
void	draw_shape(t_fdf *fdf, t_vec2 **shape, int color);
void	draw_line(t_fdf *fdf, t_vec2 start, t_vec2 end, int color);

/* fdf.c */
int		fdf_draw(t_fdf *fdf);
void	fdf_init(t_fdf *fdf);

/* undr.c */
size_t	_tern(int cond, size_t t_val, size_t f_val);

/* simple.c */
void	simple_rot(int *px, int *py, int angle);
void	simple_trl(int *px, int *py, t_vec2 pos);

#endif /* FDF_H */
