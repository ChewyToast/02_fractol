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

//	Function to print the menu
void	mdrawer(t_fractol *fractol)
{
	if (fractol->set == 'm')
	{
		mlx_string_put(fractol->screen.ptr, fractol->screen.win, 1144, 30, 0x1FFFFFF, "MANDELBROT SET");
		mlx_string_put(fractol->screen.ptr, fractol->screen.win, 1144, 40, 0x1FFFFFF, "--------------");
	}
	else if (fractol->set == 'j')
	{
		mlx_string_put(fractol->screen.ptr, fractol->screen.win, 1162, 30, 0x1FFFFFF, "JULIA SET");
		mlx_string_put(fractol->screen.ptr, fractol->screen.win, 1162, 40, 0x1FFFFFF, "---------");
	}
	mlx_string_put(fractol->screen.ptr, fractol->screen.win, 1110, 750, 0x1FFFFFF, "FOR MORE RESOLUTION");
	mlx_string_put(fractol->screen.ptr, fractol->screen.win, 1110, 760, 0x1FFFFFF, "PRESS 'Q'");
	mlx_string_put(fractol->screen.ptr, fractol->screen.win, 1210, 760, 0x1FFFFFF, ft_itoa(fractol->plus_iter));
}