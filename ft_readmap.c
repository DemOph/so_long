/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_readmap.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/17 14:25:00 by chael-ha          #+#    #+#             */
/*   Updated: 2021/09/25 13:06:17 by chael-ha         ###   ########.fr       */
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

void	check_map_necessities(char c, t_mlx *mlx)
{
	if (c == 'P')
		mlx->player++;
	else if (c == 'C')
		mlx->collectible++;
	else if (c == 'E')
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
				check_map_necessities(map[i][j], mlx);
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
	if (!mlx->player || !mlx->collectible || !mlx->exi)
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
	WINDOW_HEIGHT = mlx->max_x * SIZE;
	WINDOW_WIDTH = mlx->max_y * SIZE;
	// WINDOW_HEIGHT = 1024;
	// WINDOW_WIDTH = 1024;
	is_map_rectang(mlx);
	printf("width = %d and height = %d are\n", WINDOW_WIDTH, WINDOW_HEIGHT);
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

// #include <mlx.h>

// typedef struct	s_data {
// 	void	*img;
// 	char	*addr;
// 	int		bits_per_pixel;
// 	int		line_length;
// 	int		endian;
// }				t_data;

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	ft_load_texture(char *path, t_data *data)
{
	t_mlx	mlx;

	mlx.win.mlx_ptr = mlx_init();
	data->img = mlx_xpm_file_to_image(mlx.win.mlx_ptr, path, &data->img_width, &data->img_height);
	// if (!mlx.mlx_img.img_ptr)
	// 	ft_err_print("error in texture path: ", path);
	data->img = (int *)mlx_get_data_addr(data->img,
			&data->bits_per_pixel, &data->line_length, &data->endian);
	return (1);
}

void map_texture_array(void)
{
	// t_data texture;
	// t_data mapped_texture;

	float ratio_x = (float)texture.img_width/(float)SIZE; 
	float ratio_y = (float)texture.img_height/(float)SIZE; 
	mapped_texture.img = mlx_new_image(mlx_init(), SIZE, SIZE);
	mapped_texture.addr = mlx_get_data_addr(mapped_texture.img, &mapped_texture.bits_per_pixel, &mapped_texture.line_length,&mapped_texture.endian);
	int i = -1;
	while(++i < SIZE)
	{
		int j = -1;
		while(++j < SIZE)
			my_mlx_pixel_put(&mapped_texture, i, j, ((int *)texture.img)[(int)(j * ratio_y) * texture.img_width + (int)(i * ratio_x)]);//postion in text tab
	}
}

void	draw_square(t_data *data,int i, int j, t_mlx mlx)
{
	// int x;
	// int	y;

	// x = 0;
	// while (x < SIZE)
	// {
	// 	y = 0;
	// 	while (y < SIZE)
	// 	{
			//and here

			mlx_put_image_to_window(mlx.win.mlx_ptr, mlx.win.win_ptr, mapped_texture.img, j * SIZE,i * SIZE);
			//my_mlx_pixel_put(data, x + (j * SIZE), y + (i * SIZE), 0x00ff00ff);
	// 		y++;
	// 	}
	// 	x++;
	// }
}

// void    draw_mapp(t_data *data, t_mlx *mlx)
// {
//     int i;
//     int j;


//     i = 0;
//     while (mlx->lines[i])
//     {
//         j = 0;
//         while (mlx->lines[i][j])
//         {
// 			colorTheMap(data, i, j, *mlx);//here
// 			j++;
//         }
//         i++;
//     }
// }
// void	colorTheMap(t_data *data)
// {
// 	int x;
// 	int	y;

// 	x = 0;
// 	while (x < SIZE)
// 	{
// 		y = 0;
// 		while (y < SIZE)
// 		{
// 			//mlx_put_image_to_window(mlx.win.mlx_ptr, mlx.win.win_ptr, data.img, 0,i * SIZE);
// 			my_mlx_pixel_put(data, x , y, 0x00ff00ff);
// 			y++;
// 		}
// 		x++;
// 	}
// }

void    draw_map(t_data *data, t_mlx *mlx)
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
				draw_square(data, i, j, *mlx);//here
			j++;
        }
        i++;
    }
}

int main(int argc, char **argv)
{
	(void)argc;
	int i;
	t_mlx	mlx;
	t_data	data;
	char **s;
	// data.relative_path = "/Users/chael-ha/Desktop/ft_cub 2/textures/bit.xpm";
	data.relative_path = "/Users/chael-ha/Desktop/texture/textures/brick.xpm";
	s = ft_readmap(argv[1], &mlx);
	i = 0;
	while(s[i])
	 {
		printf("%s| %d\n",s[i], i);
		i++;
	}
	mlx.win.mlx_ptr = mlx_init();
	mlx.win.win_ptr = mlx_new_window(mlx.win.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "./so_long");
	data.img = mlx_new_image(mlx.win.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	// mlx_pixel_put(mlx, mlx_win, 5, 5, 0xFF0000);
	// mlx_loop(mlx);
	/*
	** After creating an image, we can call `mlx_get_data_addr`, we pass
	** `bits_per_pixel`, `line_length`, and `endian` by reference. These will
	** then be set accordingly for the *current* data address.
	*/
	data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length,&data.endian);
	// t_mlx	mlx2;
	// mlx2.win.mlx_ptr = mlx_init();
	ft_load_texture(data.relative_path, &texture);
	map_texture_array();
	//colorTheMap(&data);
	draw_map(&data, &mlx);
	my_mlx_pixel_put(&data, 50, 50, 0x0000FF00);
	//mlx_put_image_to_window(mlx.win.mlx_ptr, mlx.win.win_ptr, data.img, 0, 0);
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


*/