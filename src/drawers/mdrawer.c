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
	size_t	x;
	size_t	y;

	y = 0;
	while (y <= H)
	{
		x = W;
		while (x < WM)
			my_pixel_put(fractol, x++, y, 0x494949);
		y++;
	}
	mlx_string_put(fractol->screen.ptr, fractol->screen.win, W + 20, 60, 0x494949, "RESOLUCION:");
	mlx_string_put(fractol->screen.ptr, fractol->screen.win, W + 120, 60, fractol->get_color(83), ft_itoa(fractol->iter_max));
}