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

static void	conditionals(t_fractol *fractol, char **argv);

void	init_fractol(t_fractol *fractol, char select, char **argv)
{
	PTR = NULL;
	WIN = NULL;
	fractol->set = select;
	fractol->iter_max = 50;
	fractol->plus_iter = 50;
	fractol->shift_press = 0;
	fractol->screen.img = NULL;
	fractol->setcolor.count = 0;
	fractol->setvalue.zoom = 0.5;
	fractol->setvalue.xcenter = 0;
	fractol->setvalue.ycenter = 0;
	fractol->setcolor.end = 0xF7FFBF;
	fractol->setcolor.start = 0x250040;
	fractol->center_modi = 0.1 / fractol->setvalue.zoom;
	conditionals(fractol, argv);
}

static void	conditionals(t_fractol *fractol, char **argv)
{
	if (!argv[2])
	{
		fractol->setvalue.cx = 0;
		fractol->setvalue.cy = 0;
	}
	else
	{
		fractol->setvalue.cx = double_atoi(argv[2], 0, 1);
		fractol->setvalue.cy = double_atoi(argv[3], 0, 1);
	}
	if (fractol->set == 't')
		VAL = -2;
	else
		VAL = 2;
	if (fractol->set == 'm')
		fractol->setvalue.xcenter = -0.45;
}
