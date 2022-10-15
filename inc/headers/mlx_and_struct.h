/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42bcn>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 01:23:12 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/08/16 01:24:12 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MLX_AND_STRUC_H
# define MLX_AND_STRUC_H

//	LIBRARY FOR THE MLX FUNCTIONS
# include "../mlx/mlx.h"

//	LIBRARY FOR MALLOC AND FREE
# include <stdlib.h>

# include <math.h>

//	Struct declaration
typedef struct s_fractol	t_fractol;

//	Function definition to be associated to a fractal
typedef void	(*t_fdrawer)(t_fractol *fractol);
typedef void	(*t_mdrawer)(t_fractol *fractol);
typedef int		(*t_get_color)(int i, t_fractol *fractol);

//	Containing structure of screen pointers
typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	void	*img;
}				t_mlx;

//	Containing structure of strings for screen info
typedef struct s_str
{
	char	*set;
	char	*posx;
	char	*posy;
	char	*zoom;
}				t_str;

typedef struct s_setvalue
{
	double		zoom;
	double		xcenter;
	double		ycenter;
	double		cx;
	double		cy;
}				t_setvalue;

typedef struct s_myrgba
{
	int	r;
	int	g;
	int	b;
}				t_myrgba;

typedef struct s_img
{
	char	*buff;
	int		bitxpix;
	int		s_line;
	int		endian;
}				t_img;

//	Main struct
struct s_fractol
{
	char		set;
	t_mlx		screen;
	t_str		str;
	t_setvalue	setvalue;
	t_fdrawer	t_fdrawer;
	t_mdrawer	t_mdrawer;
	t_get_color	get_color;
	t_myrgba	rgba;
	t_img		img;
	char		color_index;
	double		center_modi;
	int			plus_iter;
	int			iter_max;
};

//	Defines
# define W 1294
# define H 800

#endif