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
/*
static ssize_t	allocator(t_fractol *fractol, char *set)
{
	fractol->str.set = malloc(sizeof(char) * 11);
		if (!fractol->str.set)
			return (0);
	ft_strlcpy(fractol->str.set, set, 0xffffffff);
	fractol->str.posx = double_itoa(fractol->xcenter);
	if (!fractol->str.posx)
		return (0);
	fractol->str.posy = double_itoa(fractol->ycenter);
	if (!fractol->str.posy)
		return (0);
	fractol->str.zoom = NULL;
	return (1);
}*/

size_t	init_fract(t_fractol *fractol, char select, char **argv)
{
	fractol->zoom = 1;
	fractol->t_mdrawer = mdrawer;
	fractol->ycenter = 0;
	fractol->iter_max = 150;
	if (select == 'm')
	{
		fractol->t_fdrawer = draw_mandelbrot;
		fractol->xcenter = -0.45;
		fractol->cx = 0;
		fractol->cy = 0;
		fractol->set = 'm';
//		if (!allocator(fractol, "mandelbrot"))
//			return (0);
	}
	else if (select == 'j')
	{
		fractol->t_fdrawer = draw_julia;
		fractol->xcenter = 0;
		fractol->cx = double_atoi(argv[2], 0, 1);
		fractol->cy = double_atoi(argv[3], 0, 1);
		fractol->set = 'j';
//		if (!allocator(fractol, "julia"))
//			return (0);
	}
	return (1);
}
