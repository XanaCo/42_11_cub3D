/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:58:16 by ancolmen          #+#    #+#             */
/*   Updated: 2023/10/13 16:24:25 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <errno.h>
# include <math.h>
# include "../../../libft/src/libft.h"
# include "../../../mlx/mlx.h"
# include "structures.h"
# include <limits.h>

# define SPEED 100
# define MOV_SPEED 100
# define ROT_SPEED 16
# define END 0
# define TMP 1
# define WIN_W 1080
# define WIN_H 720
# define TEX_W 128
# define TEX_H 128
# define RATE 5000
# define IMG 0
# define NORTH_T 0
# define SOUTH_T 1
# define WEST_T 2
# define EAST_T 3
# define START_S 4

/*MLX*/
int			init_mlx_ptr(t_game *data);
int			init_mlx_img_addr(t_game *data);
void		destroy_mlx_img_tab(t_game *data);

/*PARSING*/
int			parsing(t_game *data, char *file);
void		get_textures(t_game *data);
t_list		*get_map(t_game *data);
void		check_and_stock_map(t_game *data, t_list *lst);
void		stock_map_tab(t_game *data, t_list *lst);
int			check_charset(t_game *data, char *map_line);
void		add_texture_to_map(t_game *data, char *line);
int			init_texture(t_game *data, t_img *texture, char *path);
int			init_fc_color(t_game *data, int *color, char *path);
int			get_colors(int *r, int *g, int *b, char **color_tab);
void		fill_espaces(t_game *data, char **map_line);
void		check_walls(t_game *data, char **map);
void		search_player(t_game *data, char **map);
void		stock_player(t_game *data, char dir, int pos_x, int pos_y);
void		ref_img_tab(t_img *r_tab, t_map map);

/*LOOP*/
void		start_game(t_game *data);
int			update_game(t_game *data);

/*EVENTS*/
int			key_press_handler(int keycode, t_game *data);
int			key_release_handler(int keycode, t_game *data);
void		set_moves(t_game *data, double *mov_x, double *mov_y);
void		get_move(t_game *data);
void		get_rotation(t_game *data);

/*VECTOR OPERATIONS*/
t_points	rotate(t_points coord, double angle);
t_points	sum_coord(t_points v1, t_points v2);
t_points	diff_coord(t_points v1, t_points v2);
t_points	prod_coord(t_points v1, double factor);
t_points	div_coord(t_points v1, double factor);
t_points	abs_coord(t_points coord);

/*DISPLAY*/
void		ft_display(t_game *data);

/*DRAW*/
void		render_background(t_game *data);
void		ft_draw_walls(t_game *data, t_ray *coord, int x, int side);
void		ft_raycasting(t_game *data);

/*UTILS*/
int			check_filename(char *argv);
void		print_instructions(void);
void		print_title(void);
char		*get_next_map_line(t_game *data);
int			ft_atoi_rgb(const char *nptr);
void		add_img_to_tab(t_game *data, void *ptr);

/*GARBAGE COLLECTOR*/
int			add_to_garbage(t_game *data, void *ptr, int id);
int			add_matrix_to_garbage(t_game *data, int id, void **ptr);
void		clean_all(t_game *data);
void		clean_tmp(t_game *data);
void		clean_garbage(t_game *data, int flag);
void		*ft_calloc_gc(t_game *data, int id, size_t nmemb, size_t size);
char		*ft_strdup_gc(t_game *data, int id, const char *s);

/*EXIT*/
int			exit_succes(t_game *data);
void		exit_failure(t_game *data, char *str, int error);
int			error_msg(t_game *data, char *str, int error);
void		finish_fd_read(t_game *data);

/*DEBUG AND TESTING*/
void		print_garbage(t_game *data);
void		print_tab(char **map);

#endif
