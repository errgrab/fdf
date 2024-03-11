/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecarvalh <ecarvalh@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/26 17:21:06 by ecarvalh          #+#    #+#             */
/*   Updated: 2024/03/11 12:19:53 by ecarvalh         ###   ########.fr       */
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

/* (int [3]) is a point... so:
 * int points[null_terminated][3]; // is every point of the model
 * int edges[null_terminated][3]; // is every side (line) of the model
 * int position[3]; // is the position of the model on the world
 * int rotation[3]; // is the rotation of the model on the world
 * int scale[3]; // is the scale of the model on the world
 * This is a mess:
 * char *map; // is the map input as a string
 * int fd; // is the file descriptor of the map
 * int map_width; // is the width of the map as points
 * int map_height; // is the height of the map as points */
struct	s_model
{
	int		**points;
	int		**edges;
	int		*position;
	int		*rotation;
	int		*scale;
	char	*map;
	int		fd;
	int		map_width;
	int		map_height;
/*	int		*colors;*/
};

/* I will not explain everything in here, but it have all the "mlx" things you
 * may want...
 *
 * The state of my program is in here too, I will have something to say if I
 * want to update the image or not. */
struct	s_fdf
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*buf;
	int		*size;
	int		img_pixel_bits;
	int		img_line_bytes;
	int		img_endian;
	int		img_updated;
	int		img_drawed;
	int		event_weight;
	float	distance;
	int		perspective;
	t_model	*model;
};

/* functions */

/* events.c */
int		event_quit(t_fdf *fdf);
int		event_keypress(int key, t_fdf *fdf);
int		event_keyrelease(int key, t_fdf *fdf);

/* draw.c */
void	draw_set_color(char *buff, int color, int endian);
void	draw_pixel(t_fdf *fdf, int px, int py, int color);
void	draw_clear(t_fdf *fdf, int color);
void	draw_line(t_fdf *fdf, int **line, int color);
void	draw_shape(t_fdf *fdf, int **points, int **edges);

/* fdf.c */
int		fdf_draw(t_fdf *fdf);
void	fdf_init(t_fdf *fdf, int ac, char **av);

/* undr.c */
size_t	_tern(int cond, size_t t_val, size_t f_val);

/* xy.c */
void	xy_rotate(int *px, int *py, int angle);

/* apply.c */
void	apply_rotate(int **points, int *angle);
void	apply_translate(int **points, int *pos);
void	apply_scale(int **points, int *scale);
void	apply_weak_projection(int **points, float distance);

/* points.c */
int		*points_new(int x, int y, int z);
int		points_len(int **points);
void	*points_free(int **points);
int		**points_append(int **dest, int **src);
int		**points_copy(int **points);

/* map.c */
char	*map_get_fd(int fd);
int		map_validate(t_model *model);
int		**map_to_points(t_model *model);
int		**map_to_edges(t_model *model);

/* model.c */
void	*model_init(int ac, char **av);
void	*model_free(t_model *model);

/* img.c */
void	img_update(t_fdf *fdf);

#endif /* FDF_H */
