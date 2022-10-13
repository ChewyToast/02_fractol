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
#include "utils.h"

static size_t	init_julia(t_fractol *fractol, char **argv);
static size_t	init_mandelbrot(t_fractol *fractol, char **argv);
static size_t	startup_pxl_buff(t_fractol *fractol, char *pxl_buff);

size_t	init_fract(t_fractol *fractol, char select, char **argv)
{
	if (select == 'm')
		return (init_julia(fractol, argv));
	else if (select == 'j')
		return (init_fract(fractol, argv));
	return (1);
}

static size_t	init_julia(t_fractol *fractol, char **argv)
{
	fractol->set = 'j';
	fractol->iter_max = 150;
	fractol->setvalue.zoom = 1;
	fractol->t_mdrawer = mdrawer;
	fractol->setvalue.xcenter = 0;
	fractol->setvalue.ycenter = 0;
	fractol->t_fdrawer = draw_julia;
	fractol->get_color = get_color_blue;
	fractol->setvalue.cx = double_atoi(argv[2], 0, 1);
	fractol->setvalue.cy = double_atoi(argv[3], 0, 1);
	return (1);
}

static size_t	init_mandelbrot(t_fractol *fractol, char **argv)
{
	fractol->set = 'm';
	fractol->iter_max = 150;
	fractol->setvalue.cx = 0;
	fractol->setvalue.cy = 0;
	fractol->setvalue.zoom = 1;
	fractol->t_mdrawer = mdrawer;
	fractol->setvalue.ycenter = 0;
	fractol->setvalue.xcenter = -0.45;
	fractol->get_color = get_color_blue;
	fractol->t_fdrawer = &draw_mandelbrot;
	return (1);
}

void	startup_pxl_buff(t_fractol *fractol, char *pxl_buff)
{
	if (!fractol->pxl_buff)
		return (0);
	pxl_buff[WM * H * 4] = '\0';
	while (pxl_buff)
		*pxl_buff++ = 0;
}

/*
static ssize_t	allocator(t_fractol *fractol, char *set)
{
	fractol->str.set = malloc(sizeof(char) * 11);
		if (!fractol->str.set)
			return (0);
	ft_strlcpy(fractol->str.set, set, 0xffffffff);
	fractol->str.posx = double_itoa(fractol->setvalue.xcenter);
	if (!fractol->str.posx)
		return (0);
	fractol->str.posy = double_itoa(fractol->setvalue.ycenter);
	if (!fractol->str.posy)
		return (0);
	fractol->str.zoom = NULL;
	return (1);
}*/
