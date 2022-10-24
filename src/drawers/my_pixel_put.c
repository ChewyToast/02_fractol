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
	size_t	calc;

	calc = (W * 4 * (y - 1)) + (x * 4);
	fractol->img.buff[calc] = color & 0xff;
	fractol->img.buff[calc + 1] = (color >> 8) & 0xff;
	fractol->img.buff[calc + 2] = (color >> 16) & 0xff;
	if (x > 1094 && !fractol->m_press)
		fractol->img.buff[calc + 3] = 90;
	else
		fractol->img.buff[calc + 3] = 10;
}

void	set_background(t_fractol *fractol)
{
	size_t	i;

	i = W * H * 4 + 1;
	while (i--)
		fractol->img.buff[i] = 0;
}
