/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakader <hakader@student.1337.ma>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/06 17:09:16 by hakader           #+#    #+#             */
/*   Updated: 2025/03/19 02:03:47 by hakader          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	lose_message(void)
{
	ft_putstr("|------------------------|\n", 1);
	ft_putstr("|Haniya katji ha f lizom!|\n", 1);
	ft_putstr("|------------------------|\n", 1);
}

void	win_message(void)
{
	ft_putstr("|------------|\n", 1);
	ft_putstr("|3zwaaaaaaaa!|\n", 1);
	ft_putstr("|------------|\n", 1);
}

void	print_moves(t_mlx *mlx)
{
	mlx->moves += 1;
	ft_putstr("moves: ", 1);
	ft_putnbr(mlx->moves);
	ft_putstr("\n", 1);
}

void	move_player(t_mlx *mlx, int new_x, int new_y)
{
	if (mlx->game.c == 0 && mlx->game.map[new_y][new_x] == 'E')
	{
		print_moves(mlx);
		mlx->game.map[new_y][new_x] = 'P';
		mlx->game.map[mlx->p_y][mlx->p_x] = '0';
		win_message();
		close_window(mlx);
	}
	if (mlx->game.map[new_y][new_x] == '0'
		|| mlx->game.map[new_y][new_x] == 'C')
	{
		print_moves(mlx);
		mlx->game.map[new_y][new_x] = 'P';
		mlx->game.map[mlx->p_y][mlx->p_x] = '0';
	}
	if (mlx->game.map[new_y][new_x] == 'X')
	{
		lose_message();
		close_window(mlx);
	}
}
