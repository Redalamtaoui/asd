#ifndef CUBE_H
# define CUBE_H

# include <mlx.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
#include <fcntl.h>

# define NAME "Space Isolation"

typedef struct colectore
{
	void				*ptr;
	struct colectore	*next;

}						t_colec;

typedef struct variable
{
	char				**av;
	int					x;
	int					y;
	int					fd;

}						t_var;

typedef struct cube
{
	t_var				var;
	t_colec				*list_collecte_head;
	void				*mlx_init;
	void				*mlx_win;

}						t_cube;

#endif