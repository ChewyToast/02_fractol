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

//	Containing structure of screen pointers
typedef struct s_mlx
{
	void	*ptr;
	void	*win;
	void	*img;
}				t_mlx;

typedef struct s_setvalue
{
	double		zoom;
	double		xcenter;
	double		ycenter;
	double		cx;
	double		cy;
	double		xiter;
	double		yiter;
	int			value;
}				t_setvalue;

typedef struct s_setcolor
{
	int	count;
	int	start;
	int	end;
}				t_setcolor;

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
	t_setvalue	setvalue;
	t_img		img;
	t_setcolor	setcolor;
	char		color_index;
	double		center_modi;
	int			plus_iter;
	int			iter_max;
	_Bool		shift_press;
};

//	Defines
# define W 1294
# define H 800
# define VAL fractol->setvalue.value
# define XIT fractol->setvalue.xiter
# define YIT fractol->setvalue.yiter
# define PTR fractol->screen.ptr
# define WIN fractol->screen.win
# define PRINT 0x1FFFFFF

#endif