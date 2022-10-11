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
#include "../inc/headers/fractol.h"

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
			if (i < ITER_MAX)
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
			if (i < ITER_MAX)
				color = get_color(i);
			else
				color = 0x1D1C1A;
			mlx_pixel_put(fractol->screen.ptr,
				fractol->screen.win, x++, y, color);
		}
		y++;
	}
}

int	drawer_utility(t_fractol *fractol, double new_x_iter, double new_y_iter)
{
	int		i;
	double	old_x_iter;
	double	old_y_iter;

	i = 0;
	while (i < ITER_MAX)
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

/* int	get_color(int i)
{
	int	color;
	int a;
	if (i < 40)
		a = 201;
	else
		a = (i * 50 / 60) + 200;
	int r = 31;
	int g = 95;
	int b = 142;
	color = (((r + 256) * 256 + g) * 256 + b) & (((a + 256) * 256 + a) * 256 + a);

	return (color);
} */

int	get_color(int i)
{
	int	color;

	if (i < 2)
		color = 0x07365A;
	else if (i < 5)
		color = 0x083A61;
	else if (i < 8)
		color = 0x09416C;
	else if (i < 15)
		color = 0x094573;
	else if (i < 30)
		color = 0x0A4A7B;
	else if (i < 50)
		color = 0x0A4F83;
	else if (i < 58)
		color = 0x0C5892;
	else if (i < 65)
		color = 0x0E66A9;
	else if (i < 73)
		color = 0x0E6AB1;
	else if (i < 82)
		color = 0x0F6FB8;
	else if (i < 91)
		color = 0x0F73C0;
	else if (i < 100)
		color = 0x1078C8;
	else if (i < 108)
		color = 0x1183DA;
	else if (i < 116)
		color = 0x128BE6;
	else
		color = 0x149AFF;
	return (color);
}
