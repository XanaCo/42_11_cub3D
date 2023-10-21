/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ancolmen <ancolmen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 16:00:04 by atardif           #+#    #+#             */
/*   Updated: 2023/10/15 16:00:24 by ancolmen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_BONUS_H
# define CUB3D_BONUS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <fcntl.h>
# include <limits.h>
# include <errno.h>
# include <curses.h>
# include <math.h>
# include "../../../libft/src/libft.h"
# include "../../../mlx/mlx.h"
# include "structures_bonus.h"

# define SPEED 1000
# define MOV_SPEED 37
# define ROT_SPEED 5
# define END 0
# define TMP 1
# define WIN_W 1080
# define WIN_H 720
# define TEX_W 128
# define TEX_H 128
# define RATE 2500
# define BIG_RATE 50000
# define IMG 0
# define NORTH 0
# define SOUTH 1
# define WEST 2
# define EAST 3
# define NORTH_T 0
# define SOUTH_T 1
# define WEST_T 2
# define EAST_T 3
# define FLOOR_T 4
# define CEIL_T 5
# define NS1_D 6
# define NS2_D 7
# define NS3_D 8
# define NS4_D 9
# define WE1_D 10
# define WE2_D 11
# define WE3_D 12
# define WE4_D 13
# define BEAR_T 14
# define EXIT_T 15
# define ELE_D 16
# define C_T1 17
# define C_T2 18
# define C_T3 19
# define C_T4 20
# define C_D1 21
# define C_D2 22
# define C_TRANSP 23
# define NS2_D_PATH "./img/XPM/doors/DO_destruct_N_S-02.xpm"
# define NS3_D_PATH "./img/XPM/doors/DO_destruct_N_S-03.xpm"
# define NS4_D_PATH "./img/XPM/doors/DO_destruct_N_S-04.xpm"
# define WE2_D_PATH "./img/XPM/doors/DO_destruct_W_E-02.xpm"
# define WE3_D_PATH "./img/XPM/doors/DO_destruct_W_E-03.xpm"
# define WE4_D_PATH "./img/XPM/doors/DO_destruct_W_E-04.xpm"
# define C_TRANSP_PATH "./img/XPM/characters/C_TRANSP.xpm"
# define C_T2_PATH "./img/XPM/characters/C_Twins_02.xpm"
# define C_T3_PATH "./img/XPM/characters/C_Twins_03.xpm"
# define C_T4_PATH "./img/XPM/characters/C_Twins_04.xpm"
# define D_2_PATH "./img/XPM/characters/DAN_02.xpm"
# define W1_PATH "./img/XPM/weapon/AX_at_01.xpm"
# define W2_PATH "./img/XPM/weapon/AX_at_02.xpm"
# define W3_PATH "./img/XPM/weapon/AX_at_03.xpm"
# define W4_PATH "./img/XPM/weapon/AX_at_04.xpm"
# define END_PATH "./img/XPM/end_machine/M_"
# define D_SPRITE 0
# define T_SPRITE 1

/*MLX*/
int			init_mlx_ptr(t_game *data);
int			init_mlx_img_addr(t_game *data);
void		destroy_mlx_img_tab(t_game *data);
int			mlx_sprite_get_pixel_color(t_img *spr, int x, int y);
int			mlx_sprite_pixel_put(t_img *spr, t_px point);

/*PARSING*/
int			parsing(t_game *data, char *file);
void		get_textures(t_game *data);
t_list		*get_map(t_game *data);
void		check_and_stock_map(t_game *data, t_list *lst);
void		stock_map_tab(t_game *data, t_list *lst);
int			check_charset(t_game *data, char *map_line);
void		check_players_and_sprites(t_game *data, int map_char);
int			init_texture(t_game *data, t_img *texture, char *path);
int			init_fc_color(t_game *data, int *color, char *path);
int			get_colors(int *r, int *g, int *b, char **color_tab);
void		fill_espaces(t_game *data, char **map_line);
void		check_walls(t_game *data, char **map);
void		search_player(t_game *data, char **map);
void		stock_player(t_game *data, char dir, int pos_x, int pos_y);
void		init_sprites(t_game *data, char **map, t_img *r_tab, int i);
void		search_sprites(t_game *data, char **map, char sprites);
void		ref_img_tab(t_img *r_tab, t_map map);

/*TEXTURES AND IMG*/
void		add_texture_to_map(t_game *data, char *line);
void		add_wall_texture(t_game *data, char *line);
void		add_floor_ceiling_texture(t_game *data, char *line);
void		add_door_texture(t_game *data, char *line);
void		add_surprise_texture(t_game *data, char *line);
void		add_characters_texture(t_game *data, char *line);
void		add_sprites_to_map(t_game *data);
void		add_door_sprite_texture(t_game *data);
void		add_characters_sprite_texture(t_game *data);
void		add_weapon_sprite_texture(t_game *data);
void		add_end_screen_texture(t_game *data);

/*LOOP AND MOVES*/
void		start_game(t_game *data);
int			update_game(t_game *data);
void		update_loops(t_game *data);
void		set_moves(t_game *data, double *mov_x, double *mov_y);
void		get_move(t_game *data);
void		get_rotation(t_game *data);

/*EVENTS*/
int			key_press_handler(int keycode, t_game *data);
int			key_release_handler(int keycode, t_game *data);
void		espace_handler(int keycode, t_game *data);
int			mouse_handler(int x, int y, t_game *data);
int			enter_win(t_game *data);
int			leave_win(t_game *data);
void		ft_handle_door_state(t_game *data, int keycode);
int			is_237_door(t_game *data);
void		ft_handle_final_door(t_game *data);
bool		ft_is_door(char door);
bool		ft_far_enough(float pos, int goal, int i);
bool		ft_check_all_coords(float new_coord, char **map,
				t_points *coord, int i);

/*SPRITES*/
void		init_weapon(t_game *data);
void		load_weapon(t_game *data);
t_img		*get_w_status(t_game *data);
bool		is_near_twins(t_ray *coord, t_sprites *sp);
void		twins_proximity(t_game *data, t_map *map, t_sprites *sp);
void		ft_draw_sprites(t_game *data, t_ray *coord, t_sprites sp[],
				t_spdraw *sd);
void		danny_follows(t_game *data);

/*VECTOR OPERATIONS*/
t_points	rotate(t_points coord, double angle);
t_points	sum_coord(t_points v1, t_points v2);
t_points	diff_coord(t_points v1, t_points v2);
t_points	prod_coord(t_points v1, double factor);
t_points	div_coord(t_points v1, double factor);
t_points	abs_coord(t_points coord);
double		dist_coord(t_coord a, t_coord b);
double		dist_points(t_points a, t_points b);

/*DISPLAY*/
void		ft_display(t_game *data);
void		load_screen_title(t_game *data);
void		init_screen_title(t_game *data);
t_color		get_palette(t_game *data);
void		ft_draw_minimap(t_game *data);

/*DRAW*/
void		render_background(t_game *data, t_back *back,
				t_ray *coord, t_map *map);
void		ft_draw_walls(t_game *data, t_ray *coord, int x, int side);
void		ft_raycasting(t_game *data, int i);
void		ft_img_pix_put(t_img *img, int x, int y, int color);
void		ft_get_door_side(int *side, int *tex_i, char obs);
void		ft_get_door_state(int side, int *tex_i, char obs);
void		ft_get_wall_side(int *side, int *tex_i);

/*UTILS*/
int			check_filename(char *argv);
void		print_instructions(void);
void		print_title(void);
char		*get_next_map_line(t_game *data);
int			ft_atoi_rgb(const char *nptr);
void		add_img_to_tab(t_game *data, void *ptr);
int			ft_get_dir(t_ray *coord);

/*GARBAGE COLLECTOR*/
int			add_to_garbage(t_game *data, void *ptr, int id);
int			add_matrix_to_garbage(t_game *data, int id, void **ptr);
void		clean_all(t_game *data);
void		clean_tmp(t_game *data);
void		clean_garbage(t_game *data, int flag);
void		*ft_calloc_gc(t_game *data, int id, size_t nmemb, size_t size);
char		*ft_strdup_gc(t_game *data, int id, const char *s);
char		*ft_strjoin_gc(t_game *data, int id,
				char const *s1, char const *s2);

/*EXIT*/
int			exit_succes(t_game *data);
void		exit_failure(t_game *data, char *str, int error);
int			error_msg(t_game *data, char *str, int error);
int			error_msg_continuation(t_game *data, char *str, int error);

void		finish_fd_read(t_game *data);

/*DEBUG AND TESTING*/
void		print_garbage(t_game *data);
void		print_tab(char **map);

#endif
