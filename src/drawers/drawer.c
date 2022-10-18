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

void	drawer(t_fractol *fractol)
{
	set_background(fractol);
	mlx_put_image_to_window(fractol->screen.ptr,
		fractol->screen.win, fractol->screen.img, 0, 0);
	fractol->t_fdrawer(fractol);
	fractol->t_mdrawer(fractol);
	mlx_put_image_to_window(fractol->screen.ptr,
		fractol->screen.win, fractol->screen.img, 0, 0);
}
