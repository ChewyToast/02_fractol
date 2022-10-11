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

#ifndef FRACTOL_H
# define FRACTOL_H

// 						~ LIBRARYS ~

//	LIBRARY FOR THE MLX FUNCTIONS
# include "mlx/mlx.h"

//	LIBFT LIBRARY
# include "libft/libft.h"

//	LIBRARY FOR THE PRINTF
# include <stdio.h>

//	LIBRARY FOR MALLOC AND FREE
# include <stdlib.h>

// 						~ STRUCTS ~

typedef struct s_fractol	t_fractol;
//	Function definition to be associated to a fractal
typedef void				(*t_fdrawer)(t_fractol *fractol);

//	Containing structure of screen pointers
typedef struct s_mlx
{
	void	*ptr;
	void	*win;
}				t_mlx;

//	Main struct
struct s_fractol
{
	t_mlx		screen;
	t_fdrawer	t_fdrawer;
	double		zoom;
	double		xcenter;
	double		ycenter;
	double		cx;
	double		cy;
};

// 						~ MACROS ~

# define W 1200
# define H 800
# define ITER_MAX 100

// 						~ FUNCTIONS ~

//		main.c
int		main(int argc, char **argv);
int		program_startup(char select, char **argv);

//		startup_utilities.c
int		check_input(int argc, char **argv, char *set);
int		check_input_num(char *num, int symb, int point);
int		error_msg(int mode);

//		double_atoi.c
double	double_atoi(const char *nptr, double num, double i);
void	atoi_utilities(const char *nptr, int dec, double *num, double *i);

//		initialize.c
void	init_fract(t_fractol *fractol, char select, char **argv);

//		window.c
int		window_startup(t_fractol *fractol);

//		fdrawers.c
void	draw_julia(t_fractol *fractol);
void	draw_mandelbrot(t_fractol *fractol);
int		drawer_utility(t_fractol *fractol,
			double new_x_iter, double new_y_iter);
int		get_color(int i);

#endif
