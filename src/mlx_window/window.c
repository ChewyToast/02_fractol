/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ut3.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42bcn>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 01:20:02 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/08/16 01:20:29 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx_and_struct.h"
#include "fractol.h"

int	window_startup(t_fractol *fractol)
{
	PTR = mlx_init();
	if (!PTR)
		return (0);
	WIN = mlx_new_window(PTR, W, H, "fractol");
	if (!WIN)
		return (0);
	fractol->screen.img = mlx_new_image(PTR, W, H);
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
	if (PTR && fractol->screen.img)
		mlx_destroy_image(PTR, fractol->screen.img);
	if (PTR && WIN)
		mlx_destroy_window(PTR, WIN);
	ft_printf("END OF FRACTOL\n");
	exit (0);
}
