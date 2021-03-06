#include "../includes/cub3d.h"

static void	print_error_1(int err)
{
	if (err == -10)
		ft_putendl("Error\nFile must have .cub extension.\n\n");
	if (err == -11)
		ft_putendl("Error\nInvalid file .cub.\n\n");
	if (err == -12)
		ft_putendl("Error\nTry cub3D <file>.cub --save(optional).\n\n");
	if (err == -13)
		ft_putendl("Error\nMLX unable to load game.\n\n");
	if (err == -14)
		ft_putendl("Error\nUnable to create bmp file.\n\n");
	if (err == -15)
		ft_putendl("Error\nUnable to open <file>.cub.\n\n");
	if (err == -16)
		ft_putendl("Error\nMap must be surrounded by walls.\n\n");
	if (err == -17)
		ft_putendl("Error\nMap not found in provided file.\n\n");
	if (err == -18)
		ft_putendl("Error\nMisconfiguration on file.\n\n");
	if (err == -19)
		ft_putendl("Error\nPlayer not found. Include N, S, E or W in map.\n\n");
}

static void	print_error_2(int err)
{
	if (err == -20)
	{
		ft_putendl("Error\nWrong resolution.\n");
		ft_putendl("R: 720 480 (positive integers).\n\n");
	}
	if (err == -21)
		ft_putendl("Error\nTexture path not found.\n\n");
	if (err == -22)
		ft_putendl("Error\nSprite path not found.\n\n");
	if (err == -23)
		ft_putendl("Error\nExpected a <file>.xpm.\n\n");
	if (err == -24)
	{
		ft_putendl("Error\nWrong color parameter for ceiling or floor");
		ft_putendl("Expected R,G,B color between 0-255. Try: 0, 255, 255.\n\n");
	}
}

// static void	free_paula(t_game *game)
// {
// 	int	i;

// 	if (game->tex)
// 	{
// 		i = N_TEX;
// 		while (i <= W_TEX)
// 		{
// 			if (game->tex[i].img)
// 				mlx_destroy_image(game->data.mlx, game->tex[i].img);
// 			i++;
// 		}
// 		free(game->tex);
// 	}
// 	// if (game->sprite)
// 	// {
// 	// 	i = 0;
// 	// 	while (i < game->num_sprite)
// 	// 	{
// 	// 		if (game->sprite[i].texture.img.ptr)
// 	// 			mlx_destroy_image(cub->mlx_ptr, sprites[i].texture.img.ptr);
// 	// 		i++;
// 	// 	}
// 	// 	free(sprites);
// 	// }
// }

void	return_error(int err/*, char *line*/)
{
	//t_game	game;
	//t_bmp	bmp;

	if (err <= -10 && err >= -19)
		print_error_1(err);
	else if (err <= -20 && err >= -24)
		print_error_2(err);
	//free_paula(&game.tex);
	// if (game.file.no_path)
	// 	mlx_destroy_image(game.data.mlx, game.file.no_path);
	//free(&game.file);
	//mlx_destroy_window(&game.data.mlx, &game.data.win);
	//mlx_destroy_display(game.data.mlx);
	//free(game.data.mlx);
	//free(&game);
	//free(line);
	//free_textures(&game);
	//*line = 0;
	//free(&game.ray.dist_wall);
	//free(&game.sprite);
	//free(&game.tex);
	//free(&bmp.file_size);
	//close_window(&game);
	exit(err);
}
