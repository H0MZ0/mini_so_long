/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/02/12 14:25:40 by hakader           #+#    #+#             */
/*   Updated: 2025/03/18 22:17:14 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# define RED "\033[1;31m"
# define RESET "\033[0m"
# define KEY_ESC 65307
# define KEY_UP 65362
# define KEY_DOWN 65364
# define KEY_RIGHT 65363
# define KEY_LEFT 65361
# define KEY_W 119
# define KEY_D 100
# define KEY_S 115
# define KEY_A 97
# define KEY_Q 113
# define ON_DESTROY 17

# include <mlx.h>
# include "GNL/get_next_line.h"

typedef struct s_axis
{
	int		x;
	int		y;
}	t_axis;

typedef struct s_map
{
	int		p;
	int		e;
	int		c;
	int		x;
	int		row;
	int		column;
	char	**map;
	char	**copy;
}	t_map;

typedef struct s_image
{
	void	*coin;
	void	*floor;
	void	*player;
	void	*enemy[4];
	void	*door;
	void	*ldoor;
	void	*wall;
	void	*img;
}	t_image;

typedef struct s_mlx
{
	t_map	game;
	t_axis	axis;
	t_image	tx;
	int		lines;
	int		p_x;
	int		p_y;
	void	*mlx;
	void	*win;
	int		moves;
	int		width;
	int		height;
	int		exit;
}	t_mlx;
/*check_walls*/
void	fl_walls(t_mlx *mlx, int y);
void	check_fl_walls(t_mlx *mlx);
void	check_rl_walls(t_mlx *mlx);

/*flood_fill*/
void	flood_fill(t_mlx *mlx, int x, int y, char **copy);
void	flood_err(t_mlx *mlx, char *str);
void	check_flood(t_mlx *mlx, char **map);

/*ft_free*/
void	free_images(t_mlx *mlx);
int		close_window(void *param);

/*ft_helpers*/
int		ft_strcmp(const char *s1, const char *s2);
void	ft_putstr(char *str, int fd);
void	free_arr(char **str);
int		is_valid_ber_file(char *filename);
/*ft_helpers2*/
size_t	ft_strcpy(char *dst, const char *src);
void	put_err(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int nbr);
/*ft_helpers3*/
void	*ft_memset(void *s, int c, size_t n);

/*init_helpers*/
int		update_game(t_mlx *mlx);
void	exit_door(t_mlx *mlx);
void	animate_enemy(t_mlx *mlx);
void	rendre_helper(t_mlx *mlx, int y, int x);

/*init_helpers2*/
char	*ft_itoa(int n);
void	draw_rectangle(t_mlx *mlx, int x, int y);
void	display_moves(t_mlx *mlx);

/*init_window*/
void	rendre_map(t_mlx *mlx);
int		key_hook(int keyhook, t_mlx *mlx);
void	enemy_sprites(t_mlx *mlx);
void	init_wind(t_mlx *mlx);
void	in_mlx(t_mlx *mlx);

/*map_parsing*/
void	read_map(t_mlx *mlx, char *map);
void	pars_square(t_mlx *mlx);
void	check_others(t_mlx *mlx);
int		column(char *map);
void	count_things(t_mlx *mlx, int check);

/*map_parsing2*/
void	copy_map(t_mlx *mlx);
void	find_player(t_mlx *mlx);
void	count_helper(t_mlx *mlx, int n);

/*player*/
void	lose_message(void);
void	win_message(void);
void	print_moves(t_mlx *mlx);
void	move_player(t_mlx *mlx, int new_x, int new_y);

/*so_long*/
void	map_filter(char *map);

#endif
