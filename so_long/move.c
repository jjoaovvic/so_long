/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaovict <joaovict@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 14:15:57 by joaovict          #+#    #+#             */
/*   Updated: 2023/01/09 18:51:28 by joaovict         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_game(t_game *game)
{
	mlx_loop_end(game->mlx);
	return (0);
}

void	win_game(t_game *game)
{
	ft_printf("YOU WIN\n");
	close_game(game);
}

void	changechar(t_game *game, int x, int y)
{
	game->map[game->posx][game->posy] = '0';
	if (game->saveexit == 1)
	{
		game->map[game->posx][game->posy] = 'E';
		game->saveexit = 0;
	}
	game->movecount++;
	ft_printf("%i\n", game->movecount);
	if (game->map[game->posx + x][game->posy + y] == 'E' && game->coins == 0)
		win_game(game);
	else if (game->map[game->posx + x][game->posy + y] == 'E' \
		&& game->coins != 0)
		game->saveexit = 1;
	if (game->map[game->posx + x][game->posy + y] == 'C')
		game->coins--;
	game->posx += x;
	game->posy += y;
	game->map[game->posx][game->posy] = 'P';
}

int	key_press(int key, t_game *game)
{
	if (key == A_KEY && game->map[game->posx][game->posy - 1] != '1')
		changechar(game, 0, -1);
	if (key == D_KEY && game->map[game->posx][game->posy + 1] != '1')
		changechar(game, 0, 1);
	if (key == W_KEY && game->map[game->posx - 1][game->posy] != '1')
		changechar(game, -1, 0);
	if (key == S_KEY && game->map[game->posx + 1][game->posy] != '1')
		changechar(game, 1, 0);
	if (key == ESC_KEY)
		close_game(game);
	return (0);
}
