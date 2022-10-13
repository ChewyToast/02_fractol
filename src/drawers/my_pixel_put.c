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
#include "my_rgba.h"

size_t	my_pixel_put(t_fractol *fractol, int x, int y, int color)
{
	size_t	i;

	i = 0;
	my_get_color(color, fractol);
	if (x >= 0 && y >= 0)
	{
		fractol->img.buff[(WM * 4 * y) + (WM * 2 + x * 4)] = fractol->get_color.r;
		fractol->img.buff[(WM * 4 * y) + (WM * 2 + x * 4) + 1] = fractol->get_color.g;
		fractol->img.buff[(WM * 4 * y) + (WM * 2 + x * 4) + 2] = fractol->get_color.b;
		fractol->img.buff[(WM * 4 * y) + (WM * 2 + x * 4) + 3] = fractol->get_color.a;
	}
}

static void	my_get_color(int color, t_fractol *fractol)
{
	t_fractol->get_color.r = (color >> 16) & 0xff;
	t_fractol->get_color.g = (color >> 8) & 0xff;
	t_fractol->get_color.b = color & 0xff;
	t_fractol->get_color.a = 1;
}