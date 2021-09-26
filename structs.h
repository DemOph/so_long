/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   structs.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 14:25:09 by chael-ha          #+#    #+#             */
/*   Updated: 2021/09/26 15:06:18 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>

#define FALSE	0
#define TRUE	1
#define SIZE	30


int	WINDOW_HEIGHT = FALSE;
int	WINDOW_WIDTH  = FALSE;
int isGameRunning = FALSE;


typedef struct	s_data {
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*relative_path;
	int		img_width;
	int		img_height;
}				t_data;

typedef struct	s_texture{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	char	*relative_path;
	int		img_width;
	int		img_height;	
}				t_texture;



t_data mapped_texture;
t_data texture;

typedef struct		s_window
{
	int				width;
	int				heigth;
	char			*title;
	void			*mlx_ptr;
	void			*win_ptr;
}                   t_window;

typedef struct		s_player_pos
{
	int				player_count;
	int				x;
	int				y;
}					t_player_pos;

typedef	struct		s_mlx
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
	t_texture		screen_img;
}					t_mlx;



void 		init_param(t_mlx *mlx)
{
	mlx->max_x = 0;
	mlx->max_y= 0;
	mlx->nb_map_char = 0;
	mlx->player.player_count = 0;
	mlx->collectible = 0;
	mlx->exi = 0;
}

// int     key_press(int keycode, t_mlx *mlx);
// int     key_release(int keycode, t_mlx *mlx);