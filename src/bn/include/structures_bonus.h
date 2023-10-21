/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structures_bonus.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/03 17:01:02 by atardif           #+#    #+#             */
/*   Updated: 2023/10/13 20:00:06 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTURES_BONUS_H
# define STRUCTURES_BONUS_H

typedef enum s_keycode
{
	ESC = 65307,
	QUIT = 113,
	W = 119,
	S = 115,
	A = 97,
	D = 100,
	F_RIGHT = 65363,
	F_LEFT = 65361,
	ESPACE = 32,
	R = 114,
	ONE = 49,
	TWO = 50,
	ENTER = 65293
}	t_keycode;

typedef struct s_key
{
	int	key_w;
	int	key_a;
	int	key_s;
	int	key_d;
	int	key_e;
	int	enter;
	int	espace;
	int	one;
	int	right;
	int	left;
}	t_key;

typedef struct s_color
{
	int	wall;
	int	floor;
	int	door;
	int	b_door;
	int	end;
	int	ext;
}	t_color;

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

typedef struct s_px
{
	int	x;
	int	y;
	int	color;
}	t_px;

typedef struct s_tex
{
	double		wall_x;
	double		t_step;
	double		tex_pos;
	t_points	tex;
}	t_tex;

typedef struct s_back
{
	t_points	ray_dir_a;
	t_points	ray_dir_b;
	int			p;
	double		pos_z;
	double		row_dist;
	t_points	floor_step;
	t_points	floor;
	t_coord		cell;
	t_coord		tex;
}	t_back;

typedef struct s_spdraw
{
	double		sp_dist[2];
	int			sp_order[2];
	t_points	sprite;
	double		inv_det;
	t_points	transform;
	int			sprite_screen_x;
	int			sprite_height;
	int			sprite_width;
	t_coord		draw_start;
	t_coord		draw_end;
	t_coord		tex;
	int			d;
	int			i;
	int			stripe;
	int			y;
}	t_spdraw;

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
	int			tex_i;
	int			line_height;
	int			color;
	double		*dist_tab;
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

typedef struct s_sprites
{
	char		id;
	t_points	pos;
	t_points	new_pos;
	t_points	dir;
	double		ang;
	int			anim;
	int			visible;
	double		dist;
	t_img		texture;
}	t_sprites;

typedef struct s_gcol
{
	void			*ptr;
	int				id;
	struct s_gcol	*next;
}	t_gcol;

typedef struct s_xpm
{
	t_img	img_1;
	t_img	img_2;
	t_img	img_3;
	t_img	img_4;
}		t_xpm;

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
	t_img	c_texture;
	t_img	f_texture;
	t_img	pns1_texture;
	t_img	pns2_texture;
	t_img	pns3_texture;
	t_img	pns4_texture;
	t_img	pwe1_texture;
	t_img	pwe2_texture;
	t_img	pwe3_texture;
	t_img	pwe4_texture;
	t_img	t0_texture;
	t_img	t1_texture;
	t_img	t2_texture;
	t_img	t3_texture;
	t_img	t4_texture;
	t_img	d1_texture;
	t_img	d2_texture;
	t_img	x_texture;
	t_img	b_texture;
	t_img	ele_texture;
	t_img	r_tab[25];
	int		error;
	int		sp_error;
}		t_map;

typedef struct s_mini
{
	int			width;
	int			height;
	int			case_size;
	t_points	case_zero;
	t_coord		pl_pos;
	t_coord		center;
	t_points	iter;
	double		c_dist;
}	t_mini;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			fd;
	int			loops;
	int			start;
	int			in;
	t_map		map;
	t_key		key;
	t_ray		coord;
	t_back		back;
	t_tex		tex;
	t_spdraw	spdraw;
	t_sprites	sprite[2];
	t_img		*img_tab[128];
	t_xpm		screen_title;
	t_img		screen_end[34];
	t_xpm		weapon;
	int			show_weapon;
	int			init_sprite;
	int			rev_text;
	t_img		main_img;
	t_gcol		*gc;
	int			colors;
	int			end;
}	t_game;

#endif
