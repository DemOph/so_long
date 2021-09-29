/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 14:25:09 by chael-ha          #+#    #+#             */
/*   Updated: 2021/09/29 18:56:42 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCTS_H
# define STRUCTS_H
# include	<fcntl.h>
# include	<mlx.h>
# include	<unistd.h>
# include	<stdlib.h>
# include	"get_next_line/get_next_line.h"

# define SIZE		42
# define UP_KEY		13
# define DOWN_KEY	1
# define RIGHT_KEY	2
# define LEFT_KEY	0
# define ESC			53

typedef struct s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*relative_path;
	int		img_width;
	int		img_height;
}				t_data;

typedef struct s_texture{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*relative_path;
	int		img_width;
	int		img_height;	
}				t_texture;

typedef struct s_window
{
	int				width;
	int				height;
	char			*title;
	void			*mlx_ptr;
	void			*win_ptr;
}	t_window;

typedef struct s_player_pos
{
	int				x;
	int				y;
	int				player_count;
	int				collect_ate;
	int				exit6;
}					t_player_pos;

typedef struct s_mlx
{
	t_window		win;
	t_player_pos	player;
	int				collectible;
	int				exi;
	char			**lines;
	int				max_x;
	int				max_y;
	int				nb_map_char;
	t_texture		p_text;
	t_texture		c_text;
	t_texture		w_text;
	t_texture		exit_text;
	t_texture		screen_img;
}	t_mlx;

void	ft_putchar(char c);
void	ft_putnbr(int n);
void	ft_putstr(char *s);
void	ft_put_error(char *str, t_mlx *mlx);
char	**ft_readmap(char *filename, t_mlx *mlx);
void	ft_load_ressources(t_mlx *mlx);
void	map_texture_array(t_mlx *mlx, t_texture *text);
int		ft_move_player(t_mlx *mlx, int var_1, int var_2);
int		ft_exit(void);
int		key_press(int keycode, t_mlx *mlx);
void	draw_map(t_mlx *mlx);
void	screen_to_black(t_mlx *mlx);
void	my_mlx_pixel_put(t_texture *text, int x, int y, int color);
void	init_param(t_mlx *mlx);
void	is_map_valid(t_mlx *mlx);
int		countx(char **lines);
int		county(char **lines);

#endif