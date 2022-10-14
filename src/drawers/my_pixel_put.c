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
#include "mlx_and_struct.h"
#include "fractol.h"

static void	my_get_color(int color, t_fractol *fractol);

size_t	my_pixel_put(t_fractol *fractol, int x, int y, int color)
{
	write(1, "PX\n", 3);
	my_get_color(color, fractol);
	if ((y < 0 || y >= H) || (x < 0 || x >= W))
		return (0);
	write(1, "P1\n", 3);
	fractol->img.buff[(WM * 4 * (y - 1)) + (x * 4)] = fractol->rgba.r;
	write(1, "P2\n", 3);
	fractol->img.buff[(WM * 4 * y) + (WM * 2 + x * 4) + 1] = fractol->rgba.g;
	write(1, "P3\n", 3);
	fractol->img.buff[(WM * 4 * y) + (WM * 2 + x * 4) + 2] = fractol->rgba.b;
	write(1, "P4\n", 3);
	fractol->img.buff[(WM * 4 * y) + (WM * 2 + x * 4) + 3] = fractol->rgba.a;
	return (0);
}

static void	my_get_color(int color, t_fractol *fractol)
{
	fractol->rgba.r = (color >> 16) & 0xff;
	fractol->rgba.g = (color >> 8) & 0xff;
	fractol->rgba.b = color & 0xff;
	fractol->rgba.a = 1;
}