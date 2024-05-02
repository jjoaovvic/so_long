#ifndef SO_LONG_H
# define SO_LONG_H

# include <mlx.h>
# include <fcntl.h>
# include "libftprintf/libft/libft.h"
# include "libftprintf/ft_printf.h"
# include <string.h>

# define BITS 32
# define ESC_KEY 65307
# define W_KEY 119
# define A_KEY 97
# define D_KEY 100
# define S_KEY 115

typedef struct s_img
{
	void	*img;
	int		width;
	int		height;
}	t_img;

typedef struct s_game
{
	char	**map;
	void	*mlx;
	void	*win;
	char	*img;
	int		posx;
	int		posy;
	int		coins;
	int		collectible;
	int		movecount;
	int		totalcount;
	int		key_number;
	int		length;
	int		width;
	int		fd;
	int		fd2;
	int		saveexit;
	t_img	coin;
	t_img	player;
	t_img	exit;
	t_img	empty;
	t_img	wall;
}	t_game;

int		testrectangle(t_game *game);
int		testletters(t_game *game);
int		testexistence(t_game *game, int start, int finish, int collectible);
void	testpath(char **copy, int x, int y, t_game *game);
int		getwidth(char *line);
int		read_map(t_game *game);
int		malloc_map(t_game *game);
void	countcoins(t_game *game);
void	p_position(t_game *game);
int		errormanager(t_game *game);
void	asset_loader(t_game *game);
int		render_map(t_game *game);
int		close_game(t_game *game);
void	win_game(t_game *game);
void	changechar(t_game *game, int x, int y);
int		key_press(int key, t_game *game);
void	free_matrix(char **map);
int		clean_game(t_game *game);
int		map_path_maker(t_game *game);
char	**creatcopy(t_game *game);

#endif
