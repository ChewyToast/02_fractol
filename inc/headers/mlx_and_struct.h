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

#ifndef MLX_AND_STRUCT_H
# define MLX_AND_STRUCT_H

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
	_Bool		m_press;
};

//	Defines
# define W 1294
# define H 800

# define GSA "To change the theme"
# define GSB "press 'T'"
# define GSC "For more or less resolution"
# define GSD "press 'Q' or 'W':"
# define GSE "If u feel lost press 'C'"
# define GSF "Hide / show the menu"
# define GSG "press the 'M'"

# define MSA "MANDELBROT SET"
# define MSB "--------------------"
# define MSC "The Mandelbrot set"
# define MSD "is the most studied"
# define MSE "of the fractals."
# define MSF "It is named after"
# define MSG "the mathematician"
# define MSH "Benoît Mandelbrot,"
# define MSI "who did research on"
# define MSJ "it in the 1970s."
# define MSK "This set is defined"
# define MSL "in the complex plane"
# define MSM "by fixing any"
# define MSN "complex number c"
# define MSO "and iterating through"
# define MSP "the function:"
# define MSQ "Z = Z^2 + C"

# define JSA "JULIA SET"
# define JSB "-------------"
# define JSC "Julia sets, named"
# define JSD "after the mathematician"
# define JSE "Gaston Julia,"
# define JSF "are a family of fractal"
# define JSG "sets that are obtained"
# define JSH "by studying the behavior"
# define JSI "of complex numbers"
# define JSJ "when iterated by a"
# define JSK "holomorphic function:"
# define JSL "Z = Z^2 + C"
# define JSM "Hold 'SHIFT' and move"
# define JSN "to see the magic"

# define TSA "TRICORN"
# define TSB "----------"
# define TSC "In mathematics, the"
# define TSD "tricorn, sometimes called"
# define TSE "the Mandelbar set,"
# define TSF "is a fractal defined"
# define TSG "in a similar way"
# define TSH "to the Mandelbrot set,"
# define TSI "but using the mapping:"
# define TSJ "Z = Z^-2 + C"
# define TSK "It was introduced by"
# define TSL "W. D. Crowe, R. Hasson,"
# define TSM "P. J. Rippon, and"
# define TSN "P. E. D. Strain-Clark."

# define BSA "BURNING SHIP"
# define BSB "-----------------"
# define BSC "Burning Ship fractal"
# define BSD "first described and"
# define BSE "created by"
# define BSF "Michael Michelitsch"
# define BSG "in 1992, generated by"
# define BSH "iterating the function:"
# define BSI "Z = (|Re|+i|Im|)^2 + C"
# define BSJ "The difference between"
# define BSK "this calculation and"
# define BSL "that for the"
# define BSM "Mandelbrot set is that"
# define BSN "the real and imaginary"
# define BSO "components are set to"
# define BSP "their respective absolute"
# define BSQ "values before squaring"
# define BSR "at each iteration"

# define PCL 0x1FFFFFF

#endif