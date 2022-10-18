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

void	my_pixel_put(t_fractol *fractol, int x, int y, int color)
{
	if (color == 0)
	{
		fractol->img.buff[(W * 4 * (y - 1)) + (x * 4)] = fractol->rgba.r;
		fractol->img.buff[(W * 4 * (y - 1)) + (x * 4) + 1] = fractol->rgba.g;
		fractol->img.buff[(W * 4 * (y - 1)) + (x * 4) + 2] = fractol->rgba.b;
		if (x > 1094)
			fractol->img.buff[(W * 4 * (y - 1)) + (x * 4) + 3] = 90;
		else
			fractol->img.buff[(W * 4 * (y - 1)) + (x * 4) + 3] = 10;
	}
	else
	{
		fractol->img.buff[(W * 4 * (y - 1)) + (x * 4)] = color & 0xff;
		fractol->img.buff[(W * 4 * (y - 1)) + (x * 4) + 1] = (color >> 8) & 0xff;
		fractol->img.buff[(W * 4 * (y - 1)) + (x * 4) + 2] = (color >> 16) & 0xff;
		if (x > 1094)
			fractol->img.buff[(W * 4 * (y - 1)) + (x * 4) + 3] = 90;
		else
			fractol->img.buff[(W * 4 * (y - 1)) + (x * 4) + 3] = 10;
	}
}
void	set_background(t_fractol *fractol)
{
	size_t	i;

	i = W * H * 4 + 1;
	while (i--)
		fractol->img.buff[i] = 0;
}
