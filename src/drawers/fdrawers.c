/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdrawers.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42bcn>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/17 22:52:39 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/08/17 22:53:07 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx_and_struct.h"
#include "fractol.h"

static int	drawer_utility(t_fractol *fractol,
				double new_x_iter, double new_y_iter);

void	draw_tricorn(t_fractol *fractol)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			fractol->setvalue.cx = (1.5 * (x - (W >> 1))
					/ (fractol->setvalue.zoom * (W >> 1))
					+ (fractol->setvalue.xcenter));
			fractol->setvalue.cy = ((y - (H >> 1))
					/ (fractol->setvalue.zoom * (H >> 1))
					+ (fractol->setvalue.ycenter));
			i = drawer_utility(fractol, 0, 0);
			if (i < fractol->iter_max)
				my_pixel_put(fractol, x++, y, fractol->get_color(i, fractol));
			else
				my_pixel_put(fractol, x++, y, 0x1D1C1A);
		}
		y++;
	}
}

void	draw_julia(t_fractol *fractol)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			i = drawer_utility(fractol, (1.5 * (x - (W >> 1))
						/ (fractol->setvalue.zoom * (W >> 1))
						+ (fractol->setvalue.xcenter)),
					((y - (H >> 1))
						/ (fractol->setvalue.zoom * (H >> 1))
						+ (fractol->setvalue.ycenter)));
			if (i < fractol->iter_max)
				my_pixel_put(fractol, x++, y, fractol->get_color(i, fractol));
			else
				my_pixel_put(fractol, x++, y, 0x1D1C1A);
		}
		y++;
	}
}

void	draw_mandelbrot(t_fractol *fractol)
{
	int		x;
	int		y;
	int		i;

	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			fractol->setvalue.cx = (1.5 * (x - (W >> 1))
					/ (fractol->setvalue.zoom * (W >> 1))
					+ (fractol->setvalue.xcenter));
			fractol->setvalue.cy = ((y - (H >> 1))
					/ (fractol->setvalue.zoom * (H >> 1))
					+ (fractol->setvalue.ycenter));
			i = drawer_utility(fractol, 0, 0);
			if (i < fractol->iter_max)
				my_pixel_put(fractol, x++, y, fractol->get_color(i, fractol));
			else
				my_pixel_put(fractol, x++, y, 0x1D1C1A);
		}
		y++;
	}
}

static int	drawer_utility(t_fractol *fractol,
				double new_x_iter, double new_y_iter)
{
	int		i;
	double	old_x_iter;
	double	old_y_iter;

	i = 0;
	while (i < fractol->iter_max
		&& ((new_x_iter * new_x_iter + new_y_iter * new_y_iter) < 4))
	{
		if (fractol->set == 't')
		{
			old_x_iter = fabs(new_x_iter);
			old_y_iter = fabs(new_y_iter);
		}
		else
		{
			old_x_iter = new_x_iter;
			old_y_iter = new_y_iter;
		}
		new_x_iter = (((old_x_iter * old_x_iter)
					- (old_y_iter * old_y_iter)) + (fractol->setvalue.cx));
		new_y_iter = 2 * old_x_iter * old_y_iter + (fractol->setvalue.cy);
		i++;
	}
	return (i);
}
