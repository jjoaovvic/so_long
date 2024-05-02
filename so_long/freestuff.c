#include "so_long.h"

void	free_matrix(char **map)
{
	int	x;

	x = 0;
	while (map[x] != NULL)
	{
		free(map[x]);
		x++;
	}
	free(map);
}

char	**creatcopy(t_game *game)
{
	char	**copy;
	int		x;

	copy = (char **)ft_calloc(game->length + 1, sizeof (char *));
	x = 0;
	while (x < game->length)
	{
		copy[x] = ft_strdup(game->map[x]);
		x++;
	}
	return (copy);
}
