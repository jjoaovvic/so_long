/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   testmap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaovict <joaovict@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 16:26:53 by joaovict          #+#    #+#             */
/*   Updated: 2023/01/09 18:52:51 by joaovict         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	testrectangle(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	game->width = getwidth(game->map[0]);
	y = 0;
	while (x < game->length)
	{
		y = getwidth(game->map[x]);
		if (y != game->width)
			return (1);
		x++;
	}
	return (0);
}

int	testletters(t_game *game)
{
	int	x;

	x = 0;
	while (x < game->width)
	{
		if (game->map[0][x] != '1' || game->map[game->length - 1][x] != '1')
			return (1);
		x++;
	}
	x = 0;
	while (x < game->length)
	{
		if (game->map[x][0] != '1' || game->map[x][game->width - 1] != '1')
			return (1);
		x++;
	}
	return (0);
}

void	testpath(char **copy, int x, int y, t_game *game)
{
	if (copy[x][y] == 'C' \
		|| copy[x][y] == 'E')
		game->totalcount--;
	copy[x][y] = '1';
	if (copy[x][y - 1] != '1')
		testpath (copy, x, y - 1, game);
	if (copy[x][y + 1] != '1')
		testpath (copy, x, y + 1, game);
	if (copy[x - 1][y] != '1')
		testpath (copy, x - 1, y, game);
	if (copy[x + 1][y] != '1')
		testpath (copy, x + 1, y, game);
}
