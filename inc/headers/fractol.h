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

# include "mlx_and_struct.h"

//	LIBFT LIBRARY
# include "../bmlib/bmlib.h"

//	LIBRARY FOR MALLOC AND FREE
# include <stdlib.h>

// 						~ FUNCTIONS ~

//		startup
size_t	check_input(int argc, char **argv, char *set);
size_t	init_fract(t_fractol *fractol, char select, char **argv);
size_t	error_msg(int mode);

//		utils
double	double_atoi(const char *nptr, double num, double i);
//char	*double_itoa(double num);
int		get_color(int i);

//		mlx_window
int		window_startup(t_fractol *fractol);
void	end_fractol(void);
void	key_compare(int key, t_fractol *fractol);
int		mlx_keypress(int key, t_fractol *fractol);
int		mlx_mousepress(int btn, int x, int y, t_fractol *fractol);

//		drawers
void	draw_julia(t_fractol *fractol);
void	draw_mandelbrot(t_fractol *fractol);
size_t	mdrawer(t_fractol *fractol);

#endif
