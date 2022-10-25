/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:58:00 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/10/25 17:58:07 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx_and_struct.h"
#include "fractol.h"

int	window_startup(t_fractol *fractol)
{
	fractol->screen.ptr = mlx_init();
	if (!fractol->screen.ptr)
		return (0);
	fractol->screen.win = mlx_new_window(fractol->screen.ptr, W, H, "fractol");
	if (!fractol->screen.win)
		return (0);
	fractol->screen.img = mlx_new_image(fractol->screen.ptr, W, H);
	if (!fractol->screen.img)
		return (0);
	fractol->img.buff = mlx_get_data_addr(fractol->screen.img,
			&fractol->img.bitxpix, &fractol->img.s_line,
			&fractol->img.endian);
	if (!fractol->img.buff)
		return (0);
	return (1);
}

int	end_fractol(t_fractol *fractol)
{
	if (fractol->screen.ptr && fractol->screen.img)
		mlx_destroy_image(fractol->screen.ptr, fractol->screen.img);
	if (fractol->screen.ptr && fractol->screen.win)
		mlx_destroy_window(fractol->screen.ptr, fractol->screen.win);
	ft_printf("END OF FRACTOL\n");
	exit (0);
}
