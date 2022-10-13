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

static int	drawer_utility(t_fractol *fractol, double new_x_iter, double new_y_iter);

void	draw_julia(t_fractol *fractol)
{
	double	color;
	int		x;
	int		y;
	int		i;

	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			i = drawer_utility(fractol, (1.5 * (x - W / 2)
						/ (0.5 * fractol->zoom * W) + fractol->xcenter),
					((y - H / 2)
						/ (0.5 * fractol->zoom * H) + fractol->ycenter));
			if (i < fractol->iter_max)
				color = get_color(i);
			else
				color = 0x1D1C1A;
			mlx_pixel_put(fractol->screen.ptr,
				fractol->screen.win, x++, y, color);
		}
		y++;
	}
}

void	draw_mandelbrot(t_fractol *fractol)
{
	double	color;
	int		x;
	int		y;
	int		i;

	y = 0;
	while (y < H)
	{
		x = 0;
		while (x < W)
		{
			fractol->cx = (1.5 * (x - W / 2)
					/ (0.5 * fractol->zoom * W) + fractol->xcenter);
			fractol->cy = ((y - H / 2)
					/ (0.5 * fractol->zoom * H) + fractol->ycenter);
			i = drawer_utility(fractol, 0, 0);
			if (i < fractol->iter_max)
				color = get_color(i);
			else
				color = 0x1D1C1A;
			mlx_pixel_put(fractol->screen.ptr,
				fractol->screen.win, x++, y, color);
		}
		y++;
	}
}

static int	drawer_utility(t_fractol *fractol, double new_x_iter, double new_y_iter)
{
	int		i;
	double	old_x_iter;
	double	old_y_iter;

	i = 0;
	while (i < fractol->iter_max)
	{
		old_x_iter = new_x_iter;
		old_y_iter = new_y_iter;
		new_x_iter = (((old_x_iter * old_x_iter)
					- (old_y_iter * old_y_iter)) + fractol->cx);
		new_y_iter = 2 * old_x_iter * old_y_iter + fractol->cy;
		if ((new_x_iter * new_x_iter + new_y_iter * new_y_iter) > 4)
			break ;
		i++;
	}
	return (i);
}

