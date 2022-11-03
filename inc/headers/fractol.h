/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:55:25 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/10/25 17:55:40 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#ifndef FRACTOL_H
# define FRACTOL_H

// 						~ LIBRARIES ~

# include "mlx_and_struct.h"

//	LIBFT LIBRARY
# include "../bmlib/bmlib.h"

//	LIBRARY FOR MALLOC AND FREE
# include <stdlib.h>

// 						~ FUNCTIONS ~

//		startup
size_t	check_input(int argc, char **argv);
size_t	error_msg(int mode);
void	init_fractol(t_fractol *fractol, char **argv);
void	startup_pxl_buff(t_fractol *fractol, char *pxl_buff);

//		mlx_window
void	fractol_hooks(t_fractol *fractol);
int		window_startup(t_fractol *fractol);
int		end_fractol(t_fractol *fractol);
void	key_compare(int key, t_fractol *fractol);
void	mouse_compare(int btn, int x, int y, t_fractol *fractol);
int		mlx_keypress(int key, t_fractol *fractol);
int		mlx_keyrelase(int key, t_fractol *fractol);
int		mlx_mousepress(int btn, int x, int y, t_fractol *fractol);

//		drawers
void	screen_iterate(t_fractol *fractol);
void	mdrawer(t_fractol *fractol);
void	my_pixel_put(t_fractol *fractol, int x, int y, int color);
void	set_background(t_fractol *fractol);
void	drawer(t_fractol *fractol);

double	double_atoi(char *nptr, double num, double i);
void	theme_select(t_fractol *fractol);
int		get_color(int i, t_fractol *fractol);

#endif
