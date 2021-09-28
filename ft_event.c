/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_event.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chael-ha <chael-ha@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 11:36:29 by chael-ha          #+#    #+#             */
/*   Updated: 2021/09/28 18:31:16 by chael-ha         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "structs.h"

    move_right(t_mlx *mlx)
{
    if (mlx->lines[mlx->player.y][mlx->player.x + 1] != '1')
    {
        mlx->lines[mlx->player.y][mlx->player.x + 1] = 'P'; //update player pos in map
        mlx->lines[mlx->player.y][mlx->player.x] = '0';//del P from old pos
        mlx->player.x = mlx->player.x+1;
		mlx->player.y = mlx->player.y;
    }
    handle_result();
}

int     key_press(int keycode, t_mlx *mlx)
{
    if (keycode == 53)
        exit(0);
    if (keycode == 2)
    {
        move_right()
    }
    if (keycode == 0)
        data->lefto = 0;
    if (keycode == 13)
        data->up = 0;
    if (keycode == 1)
        data->down = 0;
    return (0);
}

int     key_release(int keycode, t_mlx *mlx)
{
    return (0);
}

/*


game loop {

    // events
    // execution {
        if (player => E) {

        }
        if (player => C) {

        }
    }
}

//x--------------
//y
//--

press right => check [i][j+1] != '1'  => delete player from old coordinates(replace by 0) => update the player position => put player in new pos

*/