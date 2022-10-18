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

static void	hsv_rgb(int h, int s, int v, t_fractol *fractol);

int	get_color_blue(int i, t_fractol *fractol)
{
	hsv_rgb( 199, (i * 100 / fractol->iter_max), 90, fractol);
//	ft_printf("I VALUDE: %d INTENSIDAD: %d\n",i , (i * 100 / fractol->iter_max));
	return (0);
}

static void	hsv_rgb(int h, int s, int v, t_fractol *fractol)
{
	if (!((h * 6) % 6))
	{
		fractol->rgba.r = v;
		fractol->rgba.g = v * (1 - (1 - (h * 6 - floor(h * 6))) * s);
		fractol->rgba.b = v * (1 - s);
	}
	else if (((h * 6) % 6) == 1)
	{
		fractol->rgba.r = v * (1 - (h * 6 - floor(h * 6)) * s);
		fractol->rgba.g = v;
		fractol->rgba.b = v * (1 - s);
	}
	else if (((h * 6) % 6) == 2)
	{
		fractol->rgba.r = v * (1 - s);
		fractol->rgba.g = v;
		fractol->rgba.b = v * (1 - (1 - (h * 6 - floor(h * 6))) * s);
	}
	else if (((h * 6) % 6) == 3)
	{
		fractol->rgba.r = v * (1 - s);
		fractol->rgba.g = v * (1 - (h * 6 - floor(h * 6)) * s);
		fractol->rgba.b = v;
	}
	else if (((h * 6) % 6) == 4)
	{
		fractol->rgba.r = v * (1 - (1 - (h * 6 - floor(h * 6))) * s);
		fractol->rgba.g = v * (1 - s);
		fractol->rgba.b = v;
	}
	else if (((h * 6) % 6) == 5)
	{
		fractol->rgba.r = v;
		fractol->rgba.g = v * (1 - s);
		fractol->rgba.b = v * (1 - (h * 6 - floor(h * 6)) * s);
	}
	fractol->rgba.r *= 255;
	fractol->rgba.g *= 255;
	fractol->rgba.b *= 255;
}
