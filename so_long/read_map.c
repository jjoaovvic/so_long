/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: joaovict <joaovict@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 15:46:01 by joaovict          #+#    #+#             */
/*   Updated: 2023/01/09 19:00:05 by joaovict         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	read_map(t_game *game)
{
	char	*line;

	line = get_next_line(game->fd);
	if (line == NULL)
		return (1);
	else
	{
		game->length = 1;
		while (line != NULL)
		{
			free(line);
			line = get_next_line(game->fd);
			if (line != NULL)
				game->length++;
		}
	}
	free(line);
	return (0);
}

void	checkgnl(int i)
{
	char	*s;

	while (1)
	{
		s = get_next_line(i);
		if (s != NULL)
			free(s);
		else
			break ;
	}
}

int	malloc_map(t_game *game)
{
	int		x;

	x = 0;
	game->map = (char **)ft_calloc(game->length + 1, sizeof (char *));
	if (game->map == NULL)
		return (1);
	while (x < game->length)
	{
		game->map[x] = get_next_line(game->fd2);
		if (game->map[x] == NULL)
		{
			free_matrix(game->map);
			return (1);
		}
		x++;
	}
	checkgnl(game->fd2);
	return (0);
}
