#include "so_long.h"

int	clean_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->wall.img);
	mlx_destroy_image(game->mlx, game->empty.img);
	mlx_destroy_image(game->mlx, game->coin.img);
	mlx_destroy_image(game->mlx, game->player.img);
	mlx_destroy_image(game->mlx, game->exit.img);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_matrix(game->map);
	free(game);
	return (0);
}

void	rungame(t_game *game, char *arg)
{
	game->mlx = mlx_init();
	game->win = mlx_new_window(game->mlx, game->width * BITS, \
	game->length * BITS, arg);
	asset_loader(game);
	mlx_hook(game->win, 17, (1L << 17), close_game, game);
	mlx_hook(game->win, 2, (1L << 0), key_press, game);
	mlx_loop_hook(game->mlx, render_map, game);
	mlx_loop(game->mlx);
	clean_game(game);
}

int	mapmaker(t_game *game, char *arg)
{
	game->fd = open(arg, O_RDONLY);
	if (game->fd < 0)
	{
		ft_printf("Error\nInvalid file\n");
		close(game->fd);
		return (1);
	}
	if (read_map(game) == 1)
	{
		ft_printf("Error\nError map read\n");
		return (1);
	}
	close(game->fd);
	game->fd2 = open(arg, O_RDONLY);
	if (malloc_map(game) == 1)
	{
		ft_printf("Error\nNo memory\n");
		free_matrix(game->map);
		return (1);
	}
	close(game->fd2);
	return (0);
}

int	main(int argc, char **argv)
{
	t_game	*game;
	int		bug;

	if (ft_strrchr(argv[1], '.') == NULL)
		return (write(2, "invalid name\n", 13));
	game = (t_game *)ft_calloc(1, sizeof(t_game));
	bug = 0;
	if (argc != 2 || ft_strncmp(ft_strrchr(argv[1], '.'), ".ber", 5))
	{
		ft_printf("Error\nInvalid  arguments\n");
		return (free(game), 0);
	}
	if (mapmaker(game, argv[1]) == 1)
		return (free(game), 0);
	bug = errormanager(game);
	game->saveexit = 0;
	if (bug != 1)
		rungame(game, argv[0]);
	else
	{
		free_matrix(game->map);
		free(game);
	}
	return (0);
}
