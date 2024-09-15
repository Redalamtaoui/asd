#include "cube.h"

// 1920 x 1080


int texture_check(t_cube *data)
{
	(void)data;

	return 0;
}

int	ft_exit(t_cube *data)
{
	mlx_clear_window(data->mlx_init, data->mlx_win);
	mlx_destroy_window(data->mlx_init, data->mlx_win);
	mlx_destroy_display(data->mlx_init);
	free(data->mlx_init);
	exit(1);
	return (0);
}

int	ft_parse(t_cube *data)
{
	data->var.fd = open(data->var.av[1] , O_RDWR);
	if (data->var.fd == -1 || texture_check(data) == 1)
	{
		write(2, "Error In Game\n", 15);
		return (0);
	}
	close(data->var.fd);
	return (1);
}

void	ft_inite(t_cube *data)
{
	data->list_collecte_head = NULL;
	data->var.x = 0;
	data->var.y = 0;
	data->var.fd = 0;
}

int	main(int argc, char **argv)
{
	t_cube data;

	if (argc == 2)
	{
		data.var.av = argv;
		ft_inite(&data);
		if (ft_parse(&data) == 0)
			exit(1);
		data.mlx_init = mlx_init();
		data.mlx_win = mlx_new_window(data.mlx_init, 1920, 1080, NAME);
		mlx_hook(data.mlx_win, 17, 0, ft_exit, &data);
		mlx_loop(data.mlx_init);
	}
}