/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errormanager.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaovict <joaovict@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 00:08:06 by joaovict          #+#    #+#             */
/*   Updated: 2023/01/09 18:29:59 by joaovict         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	p_position(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	game->posx = 0;
	game->posy = 0;
	while (x < game->length)
	{
		y = 0;
		while (y < game->width)
		{
			if (game->map[x][y] == 'P')
			{
				game->posx = x;
				game->posy = y;
				return ;
			}
			y++;
		}
		x++;
	}
}

int	getwidth(char *line)
{
	int	x;

	x = 0;
	while (line[x] != '\0' && line[x] != '\n')
		x++;
	return (x);
}

int	errorlog(int i)
{
	if (i == 1)
		ft_printf("Error\nThe map is not a rectangle\n");
	if (i == 2)
		ft_printf("Error\nThe map is not surrounded by walls\n");
	if (i == 3)
		ft_printf("Error\nThe map hasn't a start or an end or a collectible\n");
	if (i == 4)
		ft_printf("Error\nThe map have more than one start and/or end\n");
	if (i == 5)
		ft_printf("Error\nThe map dosn't has an valid path\n");
	if (i == 6)
		ft_printf("Error\nThe map has a wrong character\n");
	return (1);
}

int	creatpath(t_game *game)
{
	int		bug;
	char	**copy;

	bug = 0;
	p_position(game);
	countcoins(game);
	game->totalcount = game->coins + 1;
	copy = creatcopy(game);
	testpath(copy, game->posx, game->posy, game);
	if (game->totalcount != 0)
		bug = errorlog(5);
	free_matrix(copy);
	return (bug);
}

int	errormanager(t_game *game)
{
	int	bug;

	bug = 0;
	if (testrectangle(game) == 1)
		bug = errorlog(1);
	if (testletters(game) == 1)
		bug = errorlog(2);
	if (testexistence(game, 0, 0, 0) == 1)
		bug = errorlog(3);
	if (testexistence(game, 0, 0, 0) == 2)
		bug = errorlog(4);
	if (testexistence(game, 0, 0, 0) == 3)
		bug = errorlog(6);
	if (bug != 0)
		return (bug);
	bug = creatpath(game);
	return (bug);
}
