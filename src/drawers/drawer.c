/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoll-pe <bmoll-pe@student.42barcel>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 17:56:05 by bmoll-pe          #+#    #+#             */
/*   Updated: 2022/10/25 17:56:12 by bmoll-pe         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "mlx_and_struct.h"
#include "fractol.h"

void	drawer(t_fractol *fractol)
{
	set_background(fractol);
	mlx_put_image_to_window(fractol->screen.ptr,
		fractol->screen.win, fractol->screen.img, 0, 0);
	screen_iterate(fractol);
	if (!fractol->m_press)
		mdrawer(fractol);
	mlx_put_image_to_window(fractol->screen.ptr,
		fractol->screen.win, fractol->screen.img, 0, 0);
}
