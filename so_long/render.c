/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaovict <joaovict@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/08 14:53:19 by joaovict          #+#    #+#             */
/*   Updated: 2023/01/09 17:00:19 by joaovict         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	asset_loader(t_game *game)
{
	game->coin.img = mlx_xpm_file_to_image(game->mlx, "assets/coin.xpm", \
	&game->coin.width, &game->coin.height);
	game->empty.img = mlx_xpm_file_to_image(game->mlx, "assets/empty.xpm", \
	&game->empty.width, &game->empty.height);
	game->player.img = mlx_xpm_file_to_image(game->mlx, "assets/player.xpm", \
	&game->player.width, &game->player.height);
	game->exit.img = mlx_xpm_file_to_image(game->mlx, "assets/exit.xpm", \
	&game->exit.width, &game->exit.height);
	game->wall.img = mlx_xpm_file_to_image(game->mlx, "assets/wall.xpm", \
	&game->wall.width, &game->wall.height);
}

void	putimage(t_game *game, int x, int y)
{
	if (game->map[x][y] == 'C')
		game->img = game->coin.img;
	if (game->map[x][y] == 'P')
		game->img = game->player.img;
	if (game->map[x][y] == 'E')
		game->img = game->exit.img;
	if (game->map[x][y] == '1')
		game->img = game->wall.img;
	if (game->map[x][y] == '0')
		game->img = game->empty.img;
	mlx_put_image_to_window(game->mlx, game->win, game->img, \
		y * BITS, x * BITS);
}

int	render_map(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (x < game->length)
	{
		y = 0;
		while (y < game->width)
		{
			putimage(game, x, y);
			y++;
		}
		x++;
	}
	return (0);
}
