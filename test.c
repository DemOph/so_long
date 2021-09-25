#include "mlx.h"
#include <stdlib.h>
#include "structs.h"
#include <stdio.h>

typedef struct  s_data {
    void        *img;
    void        *img2;
    char        *addr;
    int         bits_per_pixel;
    int         line_length;
    int         endian;
    void        *mlx;
    void        *mlx_win;
    int         righto;
    int         lefto;
    int         up;
    int         down;
    int         posX;
    int         posY;
    char        **map;
}               t_data;

void            my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
    char    *dst;

    dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
    *(unsigned int*)dst = color;
}

// int     key_press(int keycode, t_data *data)
// {
//     if (keycode == 53)
//     {
//         mlx_destroy_window(data->mlx, data->mlx_win);
//         exit(0);
//     }
//     if (keycode == 2)
//         data->righto = 1;
//     if (keycode == 0)
//         data->lefto = 1;
//     if (keycode == 13)
//         data->up = 1;
//     if (keycode == 1)
//         data->down = 1;
//     return (0);
// }

// int     key_release(int keycode, t_data *data)
// {
//     // if (keycode == 53)
//     // {
//     //     mlx_destroy_window(data->mlx, data->mlx_win);
//     //     exit(0);
//     // }
//     if (keycode == 2)
//         data->righto = 0;
//     if (keycode == 0)
//         data->lefto = 0;
//     if (keycode == 13)
//         data->up = 0;
//     if (keycode == 1)
//         data->down = 0;
//     printf("Key pressed -> %d\n", keycode);
//     return (0);
// }


// int     render_next_frame(t_data *data)
// {
//     // static int i = 700;
//     // i++;
//     //return 0;
//     // if (data->righto)
//     //     data->posX++;
//     // mlx_put_image_to_window(data->mlx, data->mlx_win, data->img2, data->posX, data->posY);
//     // while ()
//     int i = 0;
//     int j = 0;
//     while (i < 1080)
//     {
//         j = 0;
//         while (j < 1920)
//         {
//             my_mlx_pixel_put(data, j, i, 0x00000080);
//             j++;
//         }
//         i++;
//     }
//     mlx_put_image_to_window(data->mlx, data->mlx_win, data->img, 0, 0);
//     if (data->righto)
//         data->posX++;
//     mlx_put_image_to_window(data->mlx, data->mlx_win, data->img2, data->posX, data->posY);
//     if (data->lefto)
//         data->posX--;
//     mlx_put_image_to_window(data->mlx, data->mlx_win, data->img2, data->posX, data->posY);
//     if (data->up)
//         data->posY--;
//     mlx_put_image_to_window(data->mlx, data->mlx_win, data->img2, data->posX, data->posY);
//     if (data->down)
//         data->posY++;
//     mlx_put_image_to_window(data->mlx, data->mlx_win, data->img2, data->posX, data->posY);
//     return 0;
// }

// int main()
// {
//     //init window
//     //input
//     //update
//     //render
//     // t_vars vars;
//     t_data data;
//     char    *relative_path = "/Users/chael-ha/Desktop/ft_cub 2/textures/cat1.xpm";
//     int     img_width;
//     int     img_height;
//     data.righto =0;
//     data.lefto = 0;
//     data.up = 0;
//     data.down = 0;
//     data.posX = WINDOW_WIDTH/2;
//     data.posY = WINDOW_HEIGHT/2;
//     data.mlx = mlx_init();
//     if (!(data.mlx_win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "imposter is not here")))//initiating a window
//         printf("Couldnt create the window!\n");
//     data.img = mlx_new_image(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);//init the image to push it into the win
//     data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);

 
//     mlx_hook(data.mlx_win, 2, 1L<<0, key_press , &data);
//     mlx_hook(data.mlx_win, 3, 1L<<1, key_release , &data);//slower than mlx_loop_hook

//     data.img2 = mlx_xpm_file_to_image(data.mlx, relative_path, &img_width, &img_height);
//     //char *s = "Game is Over Nihahaha!";
//     mlx_loop_hook(data.mlx, render_next_frame, &data);
//     mlx_loop(data.mlx);//initiate the window rendering
//     mlx_string_put(data.mlx, data.mlx_win, 0, 0, 0x009ee6af, s);

// }

void    draw_square(t_data data, t_mlx *mlx)
{
    int i;
    int j;

    i = 0;
    while (mlx->lines[i])
    {
        j = 0;
        if (mlx->lines[i][j] == '1')
        {
            my_mlx_pixel_put(&data, j * SIZE, i * SIZE, 0x00000080);
        }
        i++;
    }
}

int main()
{
    t_data  data;
    t_mlx   *mlx;
    
    data.map = mlx->lines;
    data.mlx = mlx_init();
    data.mlx_win = mlx_new_window(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT, "imposter is not here");
    data.img = mlx_new_image(data.mlx, WINDOW_WIDTH, WINDOW_HEIGHT);
    data.addr = mlx_get_data_addr(data.img, &data.bits_per_pixel, &data.line_length, &data.endian);
    draw_square(data, mlx);
}