/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut5.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42bcn>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 01:21:16 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/08/16 01:21:42 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "fractol.h"
#include "mlx_and_struct.h"

static size_t	init_mandelbrot(t_fractol *fractol);
static size_t	init_julia(t_fractol *fractol, char **argv);

size_t	init_fract(t_fractol *fractol, char select, char **argv)
{
	if (select == 'm')
		return (init_mandelbrot(fractol));
	else if (select == 'j')
		return (init_julia(fractol, argv));
	return (1);
}

static size_t	init_mandelbrot(t_fractol *fractol)
{
	fractol->set = 'm';
	fractol->setvalue.zoom = 0.5;
	fractol->plus_iter = 50;
	fractol->center_modi = 0.1 / fractol->setvalue.zoom;
	fractol->iter_max = 50;
	fractol->setvalue.cx = 0;
	fractol->setvalue.cy = 0;
	fractol->t_mdrawer = mdrawer;
	fractol->setvalue.ycenter = 0;
	fractol->setvalue.xcenter = -0.45;
	fractol->get_color = get_color_blue;
	fractol->t_fdrawer = draw_mandelbrot;
	return (1);
}

static size_t	init_julia(t_fractol *fractol, char **argv)
{
	fractol->set = 'j';
	fractol->plus_iter = 50;
	fractol->setvalue.zoom = 0.5;
	fractol->center_modi = 0.1 / fractol->setvalue.zoom;
	fractol->iter_max = 50;
	fractol->t_mdrawer = mdrawer;
	fractol->setvalue.xcenter = 0;
	fractol->setvalue.ycenter = 0;
	fractol->t_fdrawer = draw_julia;
	fractol->get_color = get_color_blue;
	fractol->setvalue.cx = double_atoi(argv[2], 0, 1);
	fractol->setvalue.cy = double_atoi(argv[3], 0, 1);
	return (1);
}
