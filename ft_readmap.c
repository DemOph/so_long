/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 14:25:00 by chael-ha          #+#    #+#             */
/*   Updated: 2021/09/27 17:30:13 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line/get_next_line.c"
#include <fcntl.h>
#include <stdio.h>
#include "structs.h"

int		delete_game(t_mlx *mlx)
{
	int i;

	i = 0;
	if (mlx->lines)
	{
		while (mlx->lines[i])
		{
			free(mlx->lines[i]);
			i++;
		}
		free(mlx->lines);
	}
	exit(EXIT_SUCCESS);
}

void    ft_put_error(char *str, t_mlx *mlx)
{
    printf ("\n%s\n",str);
    delete_game(mlx);
}

char	**getMapLines(char **lines, char **tmp, int fd)
{
	char	*s;
	int		i;
	int		j;
	int		ret;

	//printf("hi");
	ret = 1;
	i = 1;
	while (ret)
	{
		ret = get_next_line(fd, &s);
		tmp = lines;
		j = 0;
		lines = malloc((i + 1) * sizeof(char *));
		if (tmp)
			while (tmp[j])
			{
				lines[j] = tmp[j];
				j++;
			}
		free(tmp);
		lines[j++] = s;
		lines[j] = NULL;
		i++;
	}
	return (lines);
}

void	check_map_necessities(int i, int j, t_mlx *mlx)
{
	if (mlx->lines[i][j] == 'P')
	{
		mlx->player.player_count++;
		mlx->player.x = j;
		mlx->player.y = i;
		//printf ("i = %d, j = %d\n", mlx->player.y,mlx->player.x);
	}
	else if (mlx->lines[i][j] == 'C')
		mlx->collectible++;
	else if (mlx->lines[i][j] == 'E')
		mlx->exi++;
}
int	check_map(char **map, t_mlx *mlx)
{
	int i;
	int j;
	
	i = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] != 'P' && map[i][j] != 'C' && map[i][j] != 'E' 
				&& map[i][j] != '1' && map[i][j] != '0')
				ft_put_error("map contain weird characters!", mlx);
			if (map[i][j] != '0' && map[i][j] != '1')
				check_map_necessities(i, j, mlx);
			j++;
			mlx->nb_map_char++;
		}
		i++;
	}
	return (mlx->nb_map_char);
}

int		countx(char **lines)
{
	int i;
	int j;

	i = 0;
	while (lines[i])
	{
		j = 0;
		if (lines[i])
			i++;
	}
	return (i);
}

int 	county(char **lines)
{
	int i ;
	int j;

	i = 0;
	j = 0;
	while (lines[i][j])
		j++;
	return (j);
}

void	is_map_rectang(t_mlx *mlx)
{
	// printf("nb map char %d\n", mlx->nb_map_char);
	// printf("countx = %d\n", mlx->max_x);
	// printf("county = %d\n", mlx->max_y);
	// printf("countx*county%d\n", mlx->max_x * mlx->max_y);
	if ((countx(mlx->lines) * county(mlx->lines)) != (mlx->nb_map_char))
		ft_put_error("Map is not rectangular!\n", mlx);
}

void	is_map_closed(t_mlx *mlx)
{
	int tmp;
	int i = 0;
	
	tmp = mlx->max_y;
	while(--tmp >= 0)
		if(mlx->lines[0][tmp] && mlx->lines[0][tmp] != '1')
			ft_put_error("Map not closed!\n", mlx);

	tmp = mlx->max_y;
	//printf("tmp = %d\n", tmp);
	while(--tmp >= 0)
		if(mlx->lines[mlx->max_x - 1][tmp] && mlx->lines[mlx->max_x - 1][tmp] != '1')
			ft_put_error("Map not closed!\n", mlx);
	
	i = 0;
	while (i < mlx->max_x)
		if (mlx->lines[i][0] && mlx->lines[i++][0] != '1')
			ft_put_error("Map not closed!\n", mlx);

	i = 0;
	while (i < mlx->max_x)
		if (mlx->lines[i][mlx->max_y - 1] && mlx->lines[i++][mlx->max_y - 1] != '1')
			ft_put_error("Map not closed!\n", mlx);
}

void	is_map_valid(t_mlx *mlx)
{
	//if map doesnt have at least P C E not valid
	if (!mlx->player.player_count || !mlx->collectible || !mlx->exi)
		ft_put_error("Map is invalid!\n", mlx);
}

char	**ft_readmap(char *filename, t_mlx *mlx)
{
    int     fd;
    char    **tmp;
	
	tmp = NULL;
    if((fd = open(filename, O_RDONLY)) < 0)
        ft_put_error("MAP FILE IS NOWHERE TO BE FOUND", mlx);
	mlx->lines = getMapLines(mlx->lines, tmp, fd);
    close(fd);
	init_param(mlx);
	check_map(mlx->lines, mlx);
	mlx->max_x = countx(mlx->lines);
	mlx->max_y = county(mlx->lines);
	mlx->win.height = mlx->max_x * SIZE;
	mlx->win.width = mlx->max_y * SIZE;
	// mlx->win.height = 1024;
	// mlx->win.height = 1024;
	is_map_rectang(mlx);
	printf("width = %d and height = %d are\n", mlx->win.width, mlx->win.height);
	is_map_closed(mlx);
	is_map_valid(mlx);
	return (mlx->lines);
}


// int main(int argc, char **argv)
// {
// 	(void)argc;
// 	// int fd;
// 	int i;
// 	// char **tmp;
// 	// char **lines;
// 	t_mlx mlx;
// 	char **s;
// 	//fd = open("/Users/chael-ha/Desktop/Cub3d/2.cub", O_RDONLY);
// 	//char **s = (char **)malloc(250*sizeof(char *));
// 	s = ft_readmap(argv[1], &mlx);
// 	i = 0;
// 	while(s[i])
// 	 {
// 		//s[i] = (char *)malloc(70*sizeof(char));
// 		printf("%s| %d\n",s[i], i);
// 		i++;
// 	}
// }

void	my_mlx_pixel_put(t_texture *text, int x, int y, int color)
{
	char	*dst;

	dst = text->addr + (y * text->line_length + x * (text->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	ft_load_texture(char *path, t_texture *data, t_mlx *mlx)
{
	data->img = mlx_xpm_file_to_image(mlx->win.mlx_ptr, path, &data->img_width, &data->img_height);
	if (!data->img)
		ft_put_error("Couldn't loat the texture a zayn \\-/\n", mlx);
	data->img = (int *)mlx_get_data_addr(data->img,
		&data->bits_per_pixel, &data->line_length, &data->endian);
	return (1);
}

void map_texture_array(t_mlx *mlx, t_texture *text)
{
	t_texture mapped_texture;

	float ratio_x = (float)text->img_width/(float)SIZE; 
	float ratio_y = (float)text->img_height/(float)SIZE; 
	mapped_texture.img = mlx_new_image(mlx->win.mlx_ptr, SIZE, SIZE);
	mapped_texture.addr = mlx_get_data_addr(mapped_texture.img, &mapped_texture.bits_per_pixel, &mapped_texture.line_length,&mapped_texture.endian);
	int i = -1;
	while(++i < SIZE)
	{
		int j = -1;
		while(++j < SIZE)
			my_mlx_pixel_put(&mapped_texture, i, j, ((int *)text->img)[(int)(j * ratio_y) * text->img_width + (int)(i * ratio_x)]);//postion in text tab
	}

	// mlx_destroy_image(mlx->win.mlx_ptr, text->img); // @TODO: delete original texture
	(*text) = mapped_texture;
}

// void	draw_square(int i, int j, t_mlx mlx)
// {
// 	mlx_put_image_to_window(mlx.win.mlx_ptr, mlx.win.win_ptr, mlx.w_text.img, j * SIZE, i * SIZE);
// }
void    draw_map(t_mlx *mlx)
{
    int i;
    int j;


    i = 0;
    while (mlx->lines[i])
    {
        j = 0;
        while (mlx->lines[i][j])
        {
			if (mlx->lines[i][j] == '1')
				mlx_put_image_to_window(mlx->win.mlx_ptr, mlx->win.win_ptr, mlx->w_text.img, j * SIZE, i * SIZE);
			else if (mlx->lines[i][j] == 'P')
				mlx_put_image_to_window(mlx->win.mlx_ptr, mlx->win.win_ptr, mlx->p_text.img, j * SIZE, i * SIZE);
			else if (mlx->lines[i][j] == 'C')
				mlx_put_image_to_window(mlx->win.mlx_ptr, mlx->win.win_ptr, mlx->c_text.img, j * SIZE, i * SIZE);
			else if (mlx->lines[i][j] == 'E')
				mlx_put_image_to_window(mlx->win.mlx_ptr, mlx->win.win_ptr, mlx->exit_text.img, j * SIZE, i * SIZE);
			j++;
        }
        i++;
    }
}

void ft_load_ressources(t_mlx *mlx) 
{
	mlx->w_text.relative_path = "/Users/chael-ha/Desktop/texture/textures/grass.xpm";
	ft_load_texture(mlx->w_text.relative_path, &mlx->w_text, mlx);


	mlx->p_text.relative_path = "/Users/chael-ha/goinfre/mc.xpm";
	ft_load_texture(mlx->p_text.relative_path, &mlx->p_text, mlx);

	mlx->c_text.relative_path = "/Users/chael-ha/Desktop/ft_cub 2/textures/bit.xpm";
	ft_load_texture(mlx->c_text.relative_path, &mlx->c_text, mlx);
	
	mlx->exit_text.relative_path = "/Users/chael-ha/goinfre/exit.xpm";
	ft_load_texture(mlx->exit_text.relative_path, &mlx->exit_text, mlx);
	
	map_texture_array(mlx, &mlx->w_text);
	map_texture_array(mlx, &mlx->p_text);
	map_texture_array(mlx, &mlx->c_text);
	map_texture_array(mlx, &mlx->exit_text);
}

void	screen_to_black(t_mlx *mlx)
{
	int i = 0;
    int j = 0;
	while (i < mlx->win.height)
	{
	j = 0;
	while (j < mlx->win.width)
	{
		my_mlx_pixel_put(&mlx->screen_img, j, i, 0x00000000);
		j++;
	}
	i++;
	}
}

int     key_press_E(int keycode, t_mlx *mlx)
{
	if (keycode == 53)
		exit(0);
	return (0);
}

int ft_success(t_mlx *mlx)
{
	mlx_clear_window(mlx->win.mlx_ptr, mlx->win.win_ptr);
	mlx_string_put(mlx->win.mlx_ptr, mlx->win.win_ptr, mlx->win.width/2, mlx->win.height/2, 0x008000, "YOU WIN!");
	mlx_hook(mlx->win.win_ptr, 2, 1L<<0, key_press_E , &mlx);
	mlx_loop(mlx->win.mlx_ptr); //window rendering
	return (0);
}

// int	move_right(t_mlx *mlx)
// {
// 	if (mlx->lines[mlx->player.y][mlx->player.x + 1] == 'E' && mlx->player.collect_ate != mlx->collectible)
// 		return (0);
// 	else if (mlx->lines[mlx->player.y][mlx->player.x + 1] == 'E' && mlx->player.collect_ate == mlx->collectible)
// 		ft_success(mlx);
// 	if (mlx->lines[mlx->player.y][mlx->player.x + 1] == 'C')
// 		mlx->player.collect_ate++;
//     if (mlx->lines[mlx->player.y][mlx->player.x + 1] != '1')
//     {
//         mlx->lines[mlx->player.y][mlx->player.x + 1] = 'P'; //update player pos in map
//         mlx->lines[mlx->player.y][mlx->player.x] = '0';//del P from old pos
//         mlx->player.x = mlx->player.x + 1;
// 		mlx->player.y = mlx->player.y;
// 		mlx->player.player_count++;
//     }
// 	return (1);
// }

// int	move_left(t_mlx *mlx)
// {
// 	if (mlx->lines[mlx->player.y][mlx->player.x - 1] == 'E' && mlx->player.collect_ate != mlx->collectible)
// 		return (0);
// 	else if (mlx->lines[mlx->player.y][mlx->player.x - 1] == 'E' && mlx->player.collect_ate == mlx->collectible)
// 		ft_success(mlx);
// 	if (mlx->lines[mlx->player.y][mlx->player.x - 1] == 'C')
// 		mlx->player.collect_ate++;
//     if (mlx->lines[mlx->player.y][mlx->player.x - 1] != '1')
//     {
//         mlx->lines[mlx->player.y][mlx->player.x - 1] = 'P'; //update player pos in map
//         mlx->lines[mlx->player.y][mlx->player.x] = '0';//del P from old pos
//         mlx->player.x = mlx->player.x - 1;
// 		mlx->player.y = mlx->player.y;
// 		mlx->player.player_count++;
// 	}
// 	return (1);
// }

// int	move_up(t_mlx *mlx)
// {
// 	if (mlx->lines[mlx->player.y - 1][mlx->player.x] == 'E' && mlx->player.collect_ate != mlx->collectible)
// 		return (0);
// 	if (mlx->lines[mlx->player.y - 1][mlx->player.x] == 'E' && mlx->player.collect_ate == mlx->collectible)
// 		ft_success(mlx);
// 	if (mlx->lines[mlx->player.y - 1][mlx->player.x] == 'C')
// 		mlx->player.collect_ate++;
//     if (mlx->lines[mlx->player.y - 1][mlx->player.x] != '1')
//     {
//         mlx->lines[mlx->player.y - 1][mlx->player.x] = 'P'; //update player pos in map
//         mlx->lines[mlx->player.y][mlx->player.x] = '0';//del P from old pos
//         mlx->player.x = mlx->player.x;
// 		mlx->player.y = mlx->player.y - 1;
// 		mlx->player.player_count++;		
//     }
// 	return (1);
// }

// int	move_down(t_mlx *mlx)
// {
// 	if (mlx->lines[mlx->player.y + 1][mlx->player.x] == 'E' && mlx->player.collect_ate != mlx->collectible)
// 		return (0);
// 	if (mlx->lines[mlx->player.y + 1][mlx->player.x] == 'E' && mlx->player.collect_ate == mlx->collectible)
// 		ft_success(mlx);
// 	if (mlx->lines[mlx->player.y + 1][mlx->player.x] == 'C')
// 		mlx->player.collect_ate++;
//     if (mlx->lines[mlx->player.y + 1][mlx->player.x] != '1')
//     {
//         mlx->lines[mlx->player.y + 1][mlx->player.x] = 'P'; //update player pos in map
//         mlx->lines[mlx->player.y][mlx->player.x] = '0';//del P from old pos
//         mlx->player.x = mlx->player.x;
// 		mlx->player.y = mlx->player.y + 1;
// 		mlx->player.player_count++;
//     }
// 	return (1);
// }

int		ft_move_player(t_mlx *mlx, int var_1, int var_2)
{
	if (mlx->lines[mlx->player.y + var_1][mlx->player.x + var_2] == 'E' && mlx->player.collect_ate != mlx->collectible)
		return (0);
	if (mlx->lines[mlx->player.y + var_1][mlx->player.x + var_2] == 'E' && mlx->player.collect_ate == mlx->collectible)
		ft_success(mlx);
	if (mlx->lines[mlx->player.y + var_1][mlx->player.x + var_2] == 'C')
		mlx->player.collect_ate++;
    if (mlx->lines[mlx->player.y + var_1][mlx->player.x + var_2] != '1')
    {
        mlx->lines[mlx->player.y + var_1][mlx->player.x + var_2] = 'P'; //update player pos in map
        mlx->lines[mlx->player.y][mlx->player.x] = '0';//del P from old pos
        mlx->player.x = mlx->player.x + var_2;
		mlx->player.y = mlx->player.y + var_1;
		mlx->player.player_count++;
    }
	return (1);	
}

int     key_press(int keycode, t_mlx *mlx)
{
	int k;
	printf("player collect ate%d\n", mlx->player.collect_ate);
	printf("map collect%d\n", 	mlx->collectible);
	if (keycode == 0 || keycode == 13 || keycode == 1 || keycode == 2)
		printf("player count %d\n", mlx->player.player_count);
    if (keycode == 53)
        exit(0);
   	if (keycode == 2)
       k = ft_move_player(mlx, 0, 1);
	if (keycode == 1)
        k = ft_move_player(mlx, 1, 0);
	if (keycode == 13)
        k = ft_move_player(mlx, -1, 0);
	if (keycode == 0)
        k = ft_move_player(mlx, 0, -1);
	// clean image if not Exit before all collect
	if (k)
	{
		screen_to_black(mlx);
		mlx_put_image_to_window(mlx->win.mlx_ptr, mlx->win.win_ptr, mlx->screen_img.img, 0, 0);
	}
	draw_map(mlx);
    return (0);
}

int	ft_exit(t_mlx *mlx)
{
	exit(0);
	return (0);
}

int main(int argc, char **argv)
{
	int		i;
	t_mlx	mlx;
	char	**s;

	if (argc > 2)
		ft_put_error("too much arguments1\n", &mlx);
	s = ft_readmap(argv[1], &mlx);
	i = 0;
	while(s[i])
	 {
		printf("%s| %d\n",s[i], i);
		i++;
	}
	mlx.win.mlx_ptr = mlx_init();
	mlx.win.win_ptr = mlx_new_window(mlx.win.mlx_ptr, mlx.win.width, mlx.win.height, "./so_long");
	mlx.screen_img.img = mlx_new_image(mlx.win.mlx_ptr, mlx.win.width, mlx.win.height);// NOT THERE ANYMORE
	mlx.screen_img.addr = mlx_get_data_addr(mlx.screen_img.img, &mlx.screen_img.bits_per_pixel, &mlx.screen_img.line_length,&mlx.screen_img.endian);
	ft_load_ressources(&mlx);
	draw_map(&mlx);
	mlx_hook(mlx.win.win_ptr, 2, 1L<<0, key_press , &mlx);
	mlx_hook(mlx.win.win_ptr, 17, 1L<<0, ft_exit , &mlx);
    //mlx_hook(mlx.win.win_ptr, 3, 1L<<1, key_release , &mlx);//slower than mlx_loop_hook
	mlx_loop(mlx.win.mlx_ptr); //window rendering
}


/*
loading multiple textures (E, C, P)
handle events (key pressess) (EXIT WIN EVENT)
move character
colision with walls
collect objects
counter for collectibles
Exit event

  nm 
*/