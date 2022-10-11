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
#include "../inc/headers/fractol.h"

void	init_fract(t_fractol *fractol, char select, char **argv)
{
	if (select == 'm')
	{
		fractol->t_fdrawer = draw_mandelbrot;
		fractol->zoom = 1;
		fractol->xcenter = -0.45;
		fractol->ycenter = 0;
		fractol->cx = 0;
		fractol->cy = 0;
	}
	else if (select == 'j')
	{
		fractol->t_fdrawer = draw_julia;
		fractol->zoom = 0.7;
		fractol->xcenter = 0;
		fractol->ycenter = 0;
		fractol->cx = double_atoi(argv[2], 0, 1);
		fractol->cy = double_atoi(argv[3], 0, 1);
	}
}
