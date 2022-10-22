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
#include "mlx_and_struct.h"
#include "fractol.h"

static void	mjulia(t_fractol *fractol);
static void	mmandelbrot(t_fractol *fractol);
static void	mburningship(t_fractol *fractol);
static void	mtricorn(t_fractol *fractol);

//	Function to print the menu
void	mdrawer(t_fractol *fractol)
{
	char	*tmp;

	tmp = ft_itoa(fractol->iter_max);
	if (fractol->set == 'm')
		mmandelbrot(fractol);
	else if (fractol->set == 'j')
		mjulia(fractol);
	else if (fractol->set == 'b')
		mburningship(fractol);
	else if (fractol->set == 't')
		mtricorn(fractol);
	mlx_string_put(PTR, WIN, 1100, 630, PRINT, "To change the theme");
	mlx_string_put(PTR, WIN, 1100, 645, PRINT, "press 'T'");
	mlx_string_put(PTR, WIN, 1100, 700, PRINT, "For more or less resolution");
	mlx_string_put(PTR, WIN, 1100, 715, PRINT, "press 'Q' or 'W':");
	mlx_string_put(PTR, WIN, 1225, 715, PRINT, tmp);
	mlx_string_put(PTR, WIN, 1100, 770, PRINT, "If u feel lost press 'C'");
	free (tmp);
}

static void	mmandelbrot(t_fractol *fractol)
{
	mlx_string_put2(PTR, WIN, 1127, 30, PRINT, "MANDELBROT SET");
	mlx_string_put(PTR, WIN, 1125, 52, PRINT, "--------------------");
	
	mlx_string_put(PTR, WIN, 1131, 100, PRINT, "The Mandelbrot set");
	mlx_string_put(PTR, WIN, 1127, 120, PRINT, "is the most studied");
	mlx_string_put(PTR, WIN, 1140, 140, PRINT, "of the fractals.");
	mlx_string_put(PTR, WIN, 1136, 160, PRINT, "It is named after");
	mlx_string_put(PTR, WIN, 1135, 180, PRINT, "the mathematician");
	mlx_string_put(PTR, WIN, 1138, 200, PRINT, "Benoît Mandelbrot,");
	mlx_string_put(PTR, WIN, 1130, 220, PRINT, "who did research on");
	mlx_string_put(PTR, WIN, 1142, 240, PRINT, "it in the 1970s.");
	mlx_string_put(PTR, WIN, 1130, 260, PRINT, "This set is defined");
	mlx_string_put(PTR, WIN, 1126, 280, PRINT, "in the complex plane");
	mlx_string_put(PTR, WIN, 1149, 300, PRINT, "by fixing any");
	mlx_string_put(PTR, WIN, 1140, 320, PRINT, "complex number c");
	mlx_string_put(PTR, WIN, 1124, 340, PRINT, "and iterating through");
	mlx_string_put(PTR, WIN, 1148, 360, PRINT, "the function:");
	mlx_string_put(PTR, WIN, 1154, 385, PRINT, "Z = Z^2 + C");
}

static void	mjulia(t_fractol *fractol)
{
	mlx_string_put2(PTR, WIN, 1155, 30, PRINT, "JULIA SET");
	mlx_string_put(PTR, WIN, 1154, 52, PRINT, "-------------");
	mlx_string_put(PTR, WIN, 1135, 100, PRINT, "Julia sets, named");
	mlx_string_put(PTR, WIN, 1115, 120, PRINT, "after the mathematician");
	mlx_string_put(PTR, WIN, 1150, 140, PRINT, "Gaston Julia,");
	mlx_string_put(PTR, WIN, 1115, 160, PRINT, "are a family of fractal");
	mlx_string_put(PTR, WIN, 1117, 180, PRINT, "sets that are obtained");
	mlx_string_put(PTR, WIN, 1114, 200, PRINT, "by studying the behavior");
	mlx_string_put(PTR, WIN, 1130, 220, PRINT, "of complex numbers");
	mlx_string_put(PTR, WIN, 1129, 240, PRINT, "when iterated by a");
	mlx_string_put(PTR, WIN, 1118, 260, PRINT, "holomorphic function:");
	mlx_string_put(PTR, WIN, 1160, 285, PRINT, "Z = Z^2 + C");
	mlx_string_put(PTR, WIN, 1100, 560, PRINT, "Hold 'SHIFT' and move");
	mlx_string_put(PTR, WIN, 1100, 575, PRINT, "to see the magic");
}

static void	mtricorn(t_fractol *fractol)
{
	mlx_string_put2(PTR, WIN, 1165, 30, PRINT, "TRICORN");
	mlx_string_put(PTR, WIN, 1165, 52, PRINT, "----------");
	mlx_string_put(PTR, WIN, 1129, 100, PRINT, "In mathematics, the");
	mlx_string_put(PTR, WIN, 1106, 120, PRINT, "tricorn, sometimes called");
	mlx_string_put(PTR, WIN, 1135, 140, PRINT, "the Mandelbar set,");
	mlx_string_put(PTR, WIN, 1125, 160, PRINT, "is a fractal defined");
	mlx_string_put(PTR, WIN, 1140, 180, PRINT, "in a similar way");
	mlx_string_put(PTR, WIN, 1120, 200, PRINT, "to the Mandelbrot set,");
	mlx_string_put(PTR, WIN, 1120, 220, PRINT, "but using the mapping:");
	mlx_string_put(PTR, WIN, 1154, 245, PRINT, "Z = Z^-2 + C");
	mlx_string_put(PTR, WIN, 1124, 270, PRINT, "It was introduced by");
	mlx_string_put(PTR, WIN, 1116, 290, PRINT, "W. D. Crowe, R. Hasson,");
	mlx_string_put(PTR, WIN, 1136, 310, PRINT, "P. J. Rippon, and");
	mlx_string_put(PTR, WIN, 1122, 330, PRINT, "P. E. D. Strain-Clark.");
}

static void	mburningship(t_fractol *fractol)
{
	mlx_string_put2(PTR, WIN, 1135, 30, PRINT, "BURNING SHIP");
	mlx_string_put(PTR, WIN, 1134, 52, PRINT, "-----------------");
	mlx_string_put(PTR, WIN, 1124, 100, PRINT, "Burning Ship fractal");
	mlx_string_put(PTR, WIN, 1126, 120, PRINT, "first described and");
	mlx_string_put(PTR, WIN, 1158, 140, PRINT, "created by");
	mlx_string_put(PTR, WIN, 1126, 160, PRINT, "Michael Michelitsch");
	mlx_string_put(PTR, WIN, 1120, 180, PRINT, "in 1992, generated by");
	mlx_string_put(PTR, WIN, 1115, 200, PRINT, "iterating the function:");
	mlx_string_put(PTR, WIN, 1118, 225, PRINT, "Z = (|Re|+i|Im|)^2 + C");
	mlx_string_put(PTR, WIN, 1118, 250, PRINT, "The difference between");
	mlx_string_put(PTR, WIN, 1124, 270, PRINT, "this calculation and");
	mlx_string_put(PTR, WIN, 1153, 290, PRINT, "that for the");
	mlx_string_put(PTR, WIN, 1120, 310, PRINT, "Mandelbrot set is that");
	mlx_string_put(PTR, WIN, 1120, 330, PRINT, "the real and imaginary");
	mlx_string_put(PTR, WIN, 1123, 350, PRINT, "components are set to");
	mlx_string_put(PTR, WIN, 1107, 370, PRINT, "their respective absolute");
	mlx_string_put(PTR, WIN, 1118, 390, PRINT, "values before squaring");
	mlx_string_put(PTR, WIN, 1136, 410, PRINT, "at each iteration");
}
