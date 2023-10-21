/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:58:16 by ancolmen          #+#    #+#             */
/*   Updated: 2023/10/13 16:08:11 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_H
# define STRUCTURES_H

typedef enum s_keycode
{
	ESC = 65307,
	QUIT = 113,
	W = 119,
	S = 115,
	A = 97,
	D = 100,
	F_RIGHT = 65363,
	F_LEFT = 65361
}	t_keycode;

typedef struct s_key
{
	int	key_w;
	int	key_a;
	int	key_s;
	int	key_d;
	int	right;
	int	left;
}	t_key;

typedef struct s_range
{
	int	start;
	int	end;
}	t_range;

typedef struct s_points
{
	double	x;
	double	y;
}	t_points;

typedef struct s_coord
{
	int	x;
	int	y;
}	t_coord;

typedef struct s_tex
{
	double		wall_x;
	double		t_step;
	double		tex_pos;
	t_points	tex;
}	t_tex;

typedef struct s_ray
{
	t_points	pos;
	t_points	dir;
	t_points	screen_dir;
	t_points	plane;
	t_points	raydir;
	t_points	sidedist;
	t_points	deltadist;
	t_coord		map;
	t_coord		step;
	t_range		draw;
	double		camera_x;
	double		perp_w_dist;
	int			hit;
	int			side;
	int			line_height;
	int			color;
}	t_ray;

typedef struct s_img
{
	void	*img;
	void	*addr;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
}	t_img;

typedef struct s_gcol
{
	void			*ptr;
	int				id;
	struct s_gcol	*next;
}	t_gcol;

typedef struct s_map
{
	char	**map;
	int		map_w;
	int		map_h;
	int		n_textures;
	t_img	no_texture;
	t_img	so_texture;
	t_img	we_texture;
	t_img	ea_texture;
	t_img	r_tab[4];
	int		c_color;
	int		f_color;
	int		error;
}		t_map;

typedef struct s_game
{
	void	*mlx;
	void	*win;
	int		fd;
	int		loops;
	t_key	key;
	t_ray	coord;
	t_tex	tex;
	int		in;
	t_img	*img_tab[128];
	t_img	main_img;
	t_map	map;
	t_gcol	*gc;
}	t_game;

#endif
