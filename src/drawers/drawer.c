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
	write(1, "HJ\n", 3);
	fractol->t_fdrawer(fractol);
	write(1, "HJ\n", 3);
	fractol->t_mdrawer(fractol);
	write(1, "HJ\n", 3);
	mlx_put_image_to_window(fractol->screen.ptr, fractol->screen.win, fractol->screen.img, 0, 0);
}