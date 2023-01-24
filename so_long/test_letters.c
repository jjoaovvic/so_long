/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_letters.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaovict <joaovict@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/09 17:53:48 by joaovict          #+#    #+#             */
/*   Updated: 2023/01/09 18:42:22 by joaovict         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	countcoins(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	game->coins = 0;
	while (x < game->length)
	{
		y = 0;
		while (y < game->width)
		{
			if (game->map[x][y] == 'C')
				game->coins++;
			y++;
		}
		x++;
	}
}

int	checkers(t_game *game, int x, int y)
{
	if (game->map[x][y] != 'P' && game->map[x][y] != 'E' \
		&& game->map[x][y] != 'C' && game->map[x][y] != '0' \
		&& game->map[x][y] != '1')
		return (1);
	return (0);
}

int	testexistence(t_game *game, int start, int finish, int collectible)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->length)
	{
		y = -1;
		while (++y < game->width)
		{
			if (checkers(game, x, y) != 0)
				return (3);
			if (game->map[x][y] == 'P')
				start++;
			if (game->map[x][y] == 'E')
				finish++;
			if (game->map[x][y] == 'C')
				collectible++;
		}
		x++;
	}
	if (start == 0 || finish == 0 || collectible == 0)
		return (1);
	if (start > 1 || finish > 1)
		return (2);
	return (0);
}
