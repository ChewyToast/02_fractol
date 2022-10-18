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
	char	*tmp;

	tmp = ft_itoa(fractol->plus_iter);
	if (fractol->set == 'm')
	{
		mlx_string_put(fractol->screen.ptr, fractol->screen.win, 1144, 30, 0x1FFFFFF, "MANDELBROT SET");
		mlx_string_put(fractol->screen.ptr, fractol->screen.win, 1144, 40, 0x1FFFFFF, "--------------");
	}
	else if (fractol->set == 'j')
	{
		mlx_string_put(fractol->screen.ptr, fractol->screen.win, 1162, 30, 0x1FFFFFF, "JULIA SET");
		mlx_string_put(fractol->screen.ptr, fractol->screen.win, 1162, 40, 0x1FFFFFF, "---------");
		mlx_string_put(fractol->screen.ptr, fractol->screen.win, 1100, 650, 0x1FFFFFF, "Hold 'SHIFT' and move");
		mlx_string_put(fractol->screen.ptr, fractol->screen.win, 1100, 665, 0x1FFFFFF, "to see the magic");
	}
	mlx_string_put(fractol->screen.ptr, fractol->screen.win, 1100, 700, 0x1FFFFFF, "For more or less resolution");
	mlx_string_put(fractol->screen.ptr, fractol->screen.win, 1100, 715, 0x1FFFFFF, "press 'Q' or 'W':");
	mlx_string_put(fractol->screen.ptr, fractol->screen.win, 1225, 715, 0x1FFFFFF, tmp);
	mlx_string_put(fractol->screen.ptr, fractol->screen.win, 1100, 770, 0x1FFFFFF, "If u feel lost press 'C'");
	free (tmp);
}